%code requires{
    #include <bits/stdc++.h>
}

%{
#include<bits/stdc++.h>
#include <typeinfo>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "Helper.h"

// #define YYSTYPE SymbolInfo*

extern FILE *yyin;

void yyerror(string s){
	cout<<s<<"\n"<<endl;
}

int yyparse(void);
int yylex(void);

extern int line_count;
bool is_function_now = false;


int hashF(string s)
{
    int h = 0;
    for(int i=0;i<(int)s.size();i++)
    {
        h = (h + s[i]);
    }
    return h;
}

int bucket_size = 30;
SymbolTable *sym_tab = new SymbolTable(bucket_size,hashF);

string do_implicit_typecast(string left_op,string right_op)
{
    if(left_op == "void" || right_op == "void") return "error";

    if(left_op == "float" || right_op == "float") return "float";

    return "int";
}

void print_grammar_rule(string left_part,string right_part)
{
    cout<<"At line no: "<<line_count<<" "<<left_part<<" : "<<right_part<<"\n"<<endl; 
}

void print_log_text(string log_text)
{
    cout<<log_text<<"\n"<<endl;
}

void error_multiple_declaration(string error_symbol)
{
    cout<<"Error at Line "<<line_count<<": Multiple Declaration of "<<error_symbol<<"\n"<<endl;
}

void error_array_size_float()
{
    cout<<"Error at Line "<<line_count<<": Non-integer Array Size\n"<<endl;
}

void error_array_index_float()
{
    cout<<"Error at Line "<<line_count<<": Non-integer Array Index\n"<<endl;
}

void error_type_cast()
{
    cout<<"Error at Line "<<line_count<<": operand is void\n"<<endl;
}

void error_type_cast_mod()
{
    cout<<"Error at Line "<<line_count<<": non-integer operand on modulus operator\n"<<endl;
}


%}


%union{
    SymbolInfo* symbol_info;
    // SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    Helper* helper;
    // int ival;
    // double dval;
}

%token IF ELSE LOWER_THAN_ELSE FOR WHILE DO BREAK CHAR DOUBLE RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN INCOP DECOP ASSIGNOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token <symbol_info> ID INT FLOAT VOID ADDOP MULOP RELOP LOGICOP CONST_INT CONST_FLOAT
// %token <ival> CONST_INT
// %token <dval> CONST_FLOAT

%type < helper > start program unit variable var_declaration type_specifier func_declaration func_definition parameter_list
// %type < temp_str > expression logic_expression rel_expression simple_expression term  factor argument_list arguments
%type < helper > expression factor unary_expression term simple_expression rel_expression statement statements compound_statement logic_expression expression_statement
%type < helper > arguments argument_list
%type < helper > declaration_list

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start: program
	{
		//write your code in this block in all the similar blocks below
	}
	;

program: program unit  {
            print_grammar_rule("program","program unit");

            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "\n";
            $$->text += $2->text;

            print_log_text($$->text); 
        }
	| unit { 
            print_grammar_rule("program","unit");

            print_log_text($1->text); 
        }
	;
	
unit: var_declaration { print_grammar_rule("unit","var_declaration"); print_log_text($1->text); }
     | func_declaration { print_grammar_rule("unit","func_declaration"); print_log_text($1->text);  }
     | func_definition { print_grammar_rule("unit","func_definition"); print_log_text($1->text);  }
     ;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                if(!sym_tab->insert_symbol(*$2))
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);
    
            }
		| type_specifier ID LPAREN RPAREN SEMICOLON { 

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                if(!sym_tab->insert_symbol(*$2))
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);
            }
		;
		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += $6->text;

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                sym_tab->insert_symbol(*$2);

                print_log_text($$->text);

            }
		| type_specifier ID LPAREN RPAREN compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN RPAREN compound_statement");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += $5->text;

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                sym_tab->insert_symbol(*$2);

                print_log_text($$->text);
            
            }
 		;				


parameter_list: parameter_list COMMA type_specifier ID {

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->text;
                $$->text += " ";
                $$->text += $4->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                // $4->setVarType($3->text);
                // sym_tab->insert_symbol(*$4);

                print_log_text($$->text);

            }
		| parameter_list COMMA type_specifier {
             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");
        }
 		| type_specifier ID  { 
                print_grammar_rule("parameter_list","type_specifier ID");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                // $2->setVarType($1->text);
                // sym_tab->insert_symbol(*$2);

                print_log_text($$->text);
             }
		| type_specifier {
            print_grammar_rule("parameter_list","type_specifier");
        }
 		;

 		
compound_statement: LCURL statements RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                // string temp = $2->text;
                $$ = new Helper();
                $$->text = "{\n"; 
                $$->text += $2->text; 
                $$->text += "\n}"; 
                print_log_text($$->text);

                sym_tab->print_all_scope();
                sym_tab->exit_scope();

             }
 		    | LCURL RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");

                $$ = new Helper();
                $$->text = "{\n";  
                $$->text += "\n}"; 
                print_log_text($$->text);

                sym_tab->print_all_scope();
                sym_tab->exit_scope();
             }
 		    ;
 		    
var_declaration: type_specifier declaration_list SEMICOLON { 

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
            $$ = new Helper();

            // update text
            $$->text = $1->text;
            $$->text += " ";
            $$->text += $2->text;
            $$->text += ";";

            // insert all declaration_list ID to SymbolTable with VAR_TYPE
            for(auto el:$2->v)
            {
                el->setVarType($1->text); 
                if(!sym_tab->insert_symbol(*el)) // already present in current scope
                {
                    error_multiple_declaration(el->key);
                }
            }

            print_log_text($$->text);
        }
 		;
 		 
type_specifier: INT  { print_grammar_rule("type_specifier","INT"); cout<<$1->key<<"\n"<<endl; $$->text = $1->key; }
 		| FLOAT { print_grammar_rule("type_specifier","FLOAT"); cout<<$1->key<<"\n"<<endl; $$->text = $1->key;}
 		| VOID { print_grammar_rule("type_specifier","VOID"); cout<<$1->key<<"\n"<<endl; $$->text = $1->key;}
 		;
 		
declaration_list: declaration_list COMMA ID { 
                    print_grammar_rule("declaration_list","declaration_list COMMA ID");
                    
                    $$ = new Helper();

                    // update text
                    $$->text = $1->text;
                    $$->text += ",";
                    $$->text += $3->key;

                    // update vector
                    $$->HelperType = $1->HelperType;
                    $$->v.push_back($3);
                    $$->print();

                    print_log_text($$->text);
            }
 		    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->key;
                $$->text += "[";
                $$->text += $5->key;
                $$->text += "]";

                // update vector
                $$->HelperType = $1->HelperType;
                $$->v.push_back($3);
                $$->print();

                print_log_text($$->text);
           
           }
           | declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                ***/

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->key;
                $$->text += "[";
                $$->text += $5->key;
                $$->text += "]";

                // update vector
                $$->HelperType = $1->HelperType;
                $$->v.push_back($3);
                $$->print();

                error_array_size_float();

                print_log_text($$->text);
           
            }
 		    | ID {     
                    print_grammar_rule("declaration_list","ID");

                    $$ = new Helper();

                    // update text
                    $$->text = $1->key;

                    // init vector
                    $$->v.push_back($1);

                    print_log_text($$->text);

            }
 		    | ID LTHIRD CONST_INT RTHIRD {

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_INT RTHIRD");

                    $$ = new Helper();

                    // update text
                    $$->text = $1->key;
                    $$->text += "[";
                    $$->text += $3->key;
                    $$->text += "]";

                    // init vector
                    $$->v.push_back($1);

                    print_log_text($$->text);
            }
            | ID LTHIRD CONST_FLOAT RTHIRD {

                    /***
                        THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    ***/

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_FLOAT RTHIRD");

                    $$ = new Helper();

                    // update text
                    $$->text = $1->key;
                    $$->text += "[";
                    $$->text += $3->key;
                    $$->text += "]";

                    // init vector
                    $$->v.push_back($1);

                    error_array_size_float();

                    print_log_text($$->text);


           }
 		  ;
 		  
statements: statement {
            print_grammar_rule("statements","statement");
            
            $$ = new Helper();
            $$->text = $1->text;
            print_log_text($$->text); 
        }
	   | statements statement {
            print_grammar_rule("statements","statements statement");
        
            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "\n";
            $$->text += $2->text;

            print_log_text($$->text); 
        }
	   ;
	   
statement: var_declaration {
            print_grammar_rule("statement","var_declaration");
    
            $$ = new Helper();
            $$->text = $1->text;
            print_log_text($$->text);
        }
	  | expression_statement {
            print_grammar_rule("statement","expression_statement");
            $$ = new Helper();
            $$->text = $1->text;
            print_log_text($$->text);
        }
	  | compound_statement {
            print_grammar_rule("statement","compound_statement");
        }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
            print_grammar_rule("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");
        }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE { 
            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
            
            $$ = new Helper();
            $$->text = "if";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;

            print_log_text($$->text);

        }
	  | IF LPAREN expression RPAREN statement ELSE statement {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");
        
            $$ = new Helper();
            $$->text = "if";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;
            $$->text += "else ";
            $$->text += $7->text;

            print_log_text($$->text);
        
        }
	  | WHILE LPAREN expression RPAREN statement {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");
        }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");
        }
	  | RETURN expression SEMICOLON {
            print_grammar_rule("statement","RETURN expression SEMICOLON");

            $$ = new Helper();
            $$->text = "return";
            $$->text += " ";
            $$->text += $2->text;
            $$->text += ";";

            print_log_text($$->text);
        }
	  ;
	  
expression_statement: SEMICOLON	{
                    print_grammar_rule("expression_statement","SEMICOLON");
                }		
			| expression SEMICOLON {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    
                    $$ = new Helper();

                    // update text
                    $$->text = $1->text;
                    $$->text += ";";

                    print_log_text($$->text);
                }
			;
	  
variable: ID { 
            print_grammar_rule("variable","ID");
            $$ = new Helper();

            // update text
            $$->text = $1->key;

            // insert ID
            sym_tab->insert_symbol(*$1);

            print_log_text($$->text);
        }		
	 | ID LTHIRD expression RTHIRD {
            print_grammar_rule("variable","ID LTHIRD expression RTHIRD");
            
            $$ = new Helper();

            // update text
            $$->text = $1->key;
            $$->text += "[";
            $$->text += $3->text;
            $$->text += "]";

            // check error
            if($3->HelperType != "int")
            {
                error_array_index_float();
            }

            print_log_text($$->text);
         }
	 ;
	 
 expression: logic_expression	{
                print_grammar_rule("expression","logic_expression");

                $$ = new Helper();
                // update text
                $$->text = $1->text;

                // update vector : push up
                $$->HelperType = $1->HelperType;

                print_log_text($$->text);
            }
	   | variable ASSIGNOP logic_expression {
                print_grammar_rule("expression","variable ASSIGNOP logic_expression");
                
                $$ = new Helper();

                // updat text
                $$->text = $1->text;
                $$->text += "=";
                $$->text += $3->text;

                print_log_text($$->text);
            }	
	   ;


			 
logic_expression: rel_expression {
                print_grammar_rule("logic_expression","rel_expression");

                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // update vector : push up
                $$->HelperType = $1->HelperType;

                print_log_text($$->text);
            }	
		 | rel_expression LOGICOP rel_expression {
                print_grammar_rule("logic_expression","rel_expression LOGICOP rel_expression");
                
                $$ = new Helper();
                // update text
                $$->text = $1->text;
                $$->text += $2->key;
                $$->text += $3->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);
                if(typecast_ret != "error") $$->setHelperType("int"); // ALWAYS INT
                else error_type_cast();
                cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                
                print_log_text($$->text);
            }	
		 ;
			
rel_expression: simple_expression {
                print_grammar_rule("rel_expression","simple_expression");

                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // update vector : push up
                $$->HelperType = $1->HelperType;
                 print_log_text($$->text);
            }
		| simple_expression RELOP simple_expression	{
                print_grammar_rule("rel_expression","simple_expression RELOP simple_expression");
                
                $$ = new Helper();
                // update text
                $$->text = $1->text;
                $$->text += $2->key;
                $$->text += $3->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);
                if(typecast_ret != "error") $$->setHelperType("int"); // ALWAYS INT
                else error_type_cast();
                cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;

                print_log_text($$->text);
            }
		;
				
simple_expression: term {

                    print_grammar_rule("simple_expression","term");

                    $$ = new Helper();
                    // update text
                    $$->text = $1->text;
                    // update vector : push up
                    $$->HelperType = $1->HelperType;

                    print_log_text($$->text);
            }
		    |   simple_expression ADDOP term {
                    print_grammar_rule("simple_expression","simple_expression ADDOP term");

                    $$ = new Helper();
                    // update text
                    $$->text = $1->text;
                    $$->text += $2->key;
                    $$->text += $3->text;
                    // do implicit typecast
                    string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);
                    if(typecast_ret != "error") $$->setHelperType(typecast_ret);
                    else error_type_cast();
                    cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;

                    print_log_text($$->text);
            }
		    ;
					
term:	unary_expression {

            print_grammar_rule("term","unary_expression");

            $$ = new Helper();
            // update text
            $$->text = $1->text;
            // update vector : push up
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);
    }
    |  term MULOP unary_expression {

            print_grammar_rule("term","term MULOP unary_expression");

            $$ = new Helper();
            // update text
            $$->text = $1->text;
            $$->text += $2->key;
            $$->text += $3->text;
            // implicit typecast
            string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);

            if($2->key == "%") // both operand should be integer
            {
                if(typecast_ret != "int")
                {
                    error_type_cast_mod();
                }
            }
            else
            {
                if(typecast_ret != "error") $$->setHelperType(typecast_ret);
                else error_type_cast();
                cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
            }

            print_log_text($$->text);
    }
    ;

unary_expression: ADDOP unary_expression  {
                print_grammar_rule("unary_expression","ADDOP unary_expression");
                
                $$ = new Helper();
                // update text
                $$->text = $1->key;
                $$->text += $2->text;
                // implicit typecast
                $$->HelperType = $2->HelperType;

                print_log_text($$->text);
            }
		    | NOT unary_expression {
                print_grammar_rule("unary_expression","NOT unary_expression");
                
                $$ = new Helper();
                // update text
                $$->text = "!";
                $$->text += $2->text;
                // implicit typecast
                $$->HelperType = $2->HelperType;

                print_log_text($$->text);
            }
		    | factor  { 
                print_grammar_rule("unary_expression","factor");
                
                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // implicit typecast
                $$->HelperType = $1->HelperType;

                print_log_text($$->text);
            }
		 ;
	
factor: variable {

            print_grammar_rule("factor","variable");

            $$ = new Helper();
            // update text
            $$->text = $1->text;

            print_log_text($$->text);
        }
	| ID LPAREN argument_list RPAREN {

            print_grammar_rule("factor","ID LPAREN argument_list RPAREN");

            $$ = new Helper();
            // update text
            $$->text = $1->key;
            $$->text += "( ";
            $$->text += $3->text;
            $$->text += " )";

            print_log_text($$->text);
        }
	| LPAREN expression RPAREN {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            $$ = new Helper();
            // update text
            $$->text = "(";
            $$->text += $2->text;
            $$->text += ")";

            print_log_text($$->text);
        
        }
	| CONST_INT  { 
            print_grammar_rule("factor","CONST_INT");

            // update text
            $$ = new Helper();
            $$->text = $1->key;

            // pass up
            $$->setHelperType("int");

            print_log_text($$->text);
        }
	| CONST_FLOAT  { 
            print_grammar_rule("factor","CONST_FLOAT");

            $$ = new Helper();
            // update text
            $$->text = $1->key;
            // pass up
            $$->setHelperType("float");

            print_log_text($$->text);
        }
	| variable INCOP {
            print_grammar_rule("factor","variable INCOP");
        }
	| variable DECOP {
            print_grammar_rule("factor","variable DECOP");
        }
	;
	
argument_list: arguments {

                    print_grammar_rule("argument_list","arguments");

                    $$ = new Helper();
                    $$->text = $1->text; 
                    print_log_text($$->text);
                }
			| {
                cout<<"WHAT IS THIS"<<endl;
            }   
			;
	
arguments: arguments COMMA logic_expression {

                print_grammar_rule("arguments","arguments COMMA logic_expression");
                
                $$ = new Helper();
                $$->text = $1->text; 
                $$->text += " , "; 
                $$->text += $3->text; 
                print_log_text($$->text);
            }
	    | logic_expression {

                print_grammar_rule("arguments","logic_expression");

                $$ = new Helper();
                $$->text = $1->text; 
                print_log_text($$->text);

            }
	    ;

%%

main(int argc,char *argv[])
{
    if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

    yyin=fin;
	yyparse();
    fclose(yyin);

    exit(0);
}
