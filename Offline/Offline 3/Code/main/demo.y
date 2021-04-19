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

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// SYMBOL TABLE //////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// FUNCTION PARAMETER  ///////////////////////////////////////////

bool is_function_now = false;
vector<SymbolInfo>function_params;

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// ERROR HANDLING ///////////////////////////////////////////////

string do_implicit_typecast(string left_op,string right_op)
{
    if(left_op == "void" || right_op == "void") return "error";

    if(left_op == "float" && right_op == "float") return "float";
    if(left_op == "float" && right_op == "int") return "float";
    if(left_op == "int" && right_op == "float") return "float";
    if(left_op == "int" && right_op == "int") return "int";

    return "error";
}

bool is_param_typecast_ok(string og_p,string pass_p)
{
    if(og_p == "void") return pass_p == "void";
    if(og_p == "int") return pass_p == "int";
    if(og_p == "float") return pass_p != "void";
}

bool check_assignop(string left_op,string right_op)
{

    if(left_op == "void" || right_op == "void") return false;
    if(left_op == "NULL" || right_op == "NULL") return false;
    if(left_op == "" || right_op == "") return false;

    if(left_op == "int" && right_op =="int_array") return true;
    if(left_op == "int_array" && right_op =="int") return true;

    if(left_op == "float" && right_op =="float_array") return true;
    if(left_op == "float_array" && right_op =="float") return true;

    if(left_op == "int" && right_op !="int") return false;

    return true;
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

void error_array_index_invalid()
{
    cout<<"Error at Line "<<line_count<<": Non-integer Array Index\n"<<endl;
}

void error_type_cast()
{
    cout<<"Error at Line "<<line_count<<": Incompatible Operand\n"<<endl;
}

void error_type_cast_mod()
{
    cout<<"Error at Line "<<line_count<<": non-integer operand on modulus operator\n"<<endl;
}

void error_undeclared_variable(string var_name)
{
    cout<<"Error at Line "<<line_count<<": Undeclared Variable: "<<var_name<<"\n"<<endl;
}

void error_type_mismatch()
{
    cout<<"Error at Line "<<line_count<<": Type Mismatch\n"<<endl;
}

void error_function_parameter_type(string extra_s="")
{
    cout<<"Error at Line "<<line_count<<": Parameter Type Mismactch "<<extra_s<<"\n"<<endl;
}

void error_function_parameter_number(string extra_s="")
{
    cout<<"Error at Line "<<line_count<<": Parameter Number Mismactch\n"<<extra_s<<"\n"<<endl;
}

void error_function_not_implemented()
{
    cout<<"Error at Line "<<line_count<<": Function not implemented\n"<<endl;
}

void error_function_return_condflict()
{
    cout<<"Error at Line "<<line_count<<": Function return type mismatch\n"<<endl;
}


void error_not_function(string f_name)
{
    cout<<"Error at Line "<<line_count<<": "<<f_name<<" not a function\n"<<endl;
}

///////////////////////////////////////////

void insert_function_to_global(SymbolInfo* temp_s,string var_type)
{
    // insert function ID to SymbolTable with VAR_TYPE
    temp_s->setVarType(var_type);
    temp_s->isFunction = true;

    // update parrameter type
    for(auto temp_p : function_params)
    {
        temp_s->param_v.push_back(temp_p.var_type);
    }

    if(!sym_tab->insert_symbol(*temp_s))
    {
        SymbolInfo* ret_symbol = sym_tab->lookup(temp_s->key);

        if(ret_symbol->isFunctionDeclaration == false){
            error_multiple_declaration(temp_s->key);
        }
        else{

            // declared before , now definition happening

            // check if any clash between declaration and definition

            if(ret_symbol->var_type != temp_s->var_type)
            {
                error_function_return_condflict();
            }

            if(ret_symbol->param_v.size() != temp_s->param_v.size())
            {
                error_function_parameter_number("(Declaration vs Definition)");
            }
            else
            {
                for(int i=0;i<ret_symbol->param_v.size();i++)
                {
                    if(ret_symbol->param_v[i] != temp_s->param_v[i]){
                        error_function_parameter_type("(Declaration vs Definition)");
                        break;
                    }
                }
            }

            // the following line is commented out because in case of clash , use the declaration info 
            // ret_symbol->param_v = $2->param_v;
            ret_symbol->isFunctionDeclaration = false; // declaration + 
        }
    }
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
                $2->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    $2->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                // clear param_info
                function_params.clear();
    
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
                $2->isFunction = true;
                
                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                function_params.clear();
            }
            | error SEMICOLON {
                cout<<"inside error function ;"<<endl;
                yyclearin;
                yyerrok;
            }
		;

		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN { is_function_now = true;insert_function_to_global($2,$1->text);} compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += $7->text; 

                print_log_text($$->text);

                // clear temp function params
                is_function_now = false;
                function_params.clear();

            }
		|   type_specifier ID LPAREN RPAREN {is_function_now = true;insert_function_to_global($2,$1->text);} compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN RPAREN compound_statement");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += $6->text;

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;
                sym_tab->insert_symbol(*$2);

                print_log_text($$->text);
            
                // clear temp function params
                is_function_now = false;
                function_params.clear();
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
                $4->setVarType($3->text);
                function_params.push_back(*$4);

                print_log_text($$->text);

            }
		| parameter_list COMMA type_specifier {
             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->text;

                SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
                temp_s.var_type = $3->text;

                function_params.push_back(temp_s);

                print_log_text($$->text);
        }
 		| type_specifier ID  { 
                print_grammar_rule("parameter_list","type_specifier ID");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;

                // insert parameter ID to Parameter SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                function_params.push_back(*$2);

                print_log_text($$->text);
             }
		| type_specifier {
            print_grammar_rule("parameter_list","type_specifier");

            $$ = new Helper();

            // update text
            $$->text = $1->text;

            SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
            temp_s.var_type = $1->text;

            function_params.push_back(temp_s);

            print_log_text($$->text);
        }
 		;
 		
compound_statement: LCURL dummy_scope_function statements RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                $$ = new Helper();

                // update text
                $$->text = "{\n"; 
                $$->text += $3->text; 
                $$->text += "\n}"; 

                print_log_text($$->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

             }
 		    | LCURL dummy_scope_function RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");

                $$ = new Helper();

                // update text
                $$->text = "{\n";  
                $$->text += "\n}"; 

                print_log_text($$->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

                // // clear temp function params
                // is_function_now = false;
                // function_params.clear();
             }
 		    ;

dummy_scope_function:  {

                    sym_tab->enter_scope(); 

                    if(is_function_now)
                    {
                        for(auto el:function_params)
                        {
                            // insert ID
                            // cout<<"INSIDE FUNCTIONNN"<<endl;
                            sym_tab->insert_symbol(el);
                        }
                    }
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
                if(el->var_type == "array") el->setVarType($1->text + "_array") ; 
                else el->setVarType($1->text); 
                
                if(!sym_tab->insert_symbol(*el)) // already present in current scope
                {
                    error_multiple_declaration(el->key);
                }

            }

            print_log_text($$->text);
        }
 		;
 		 
type_specifier: INT  { print_grammar_rule("type_specifier","INT"); cout<<$1->key<<"\n"<<endl; $$->text = $1->key; }
 		| FLOAT { print_grammar_rule("type_specifier","FLOAT"); cout<<$1->key<<"\n"<<endl; $$->text = $1->key; }
 		| VOID { print_grammar_rule("type_specifier","VOID"); cout<<$1->key<<"\n"<<endl; $$->text = $1->key;}
 		;
 		
declaration_list: declaration_list COMMA ID { 
                    print_grammar_rule("declaration_list","declaration_list COMMA ID");
                    
                    $$ = new Helper();

                    // update text
                    $$->text = $1->text;
                    $$->text += ",";
                    $$->text += $3->key;

                    // update type
                    $$->HelperType = $1->HelperType;

                    // init update vector
                    $$->v = $1->v;
                    $$->v.push_back($3);
                    // $$->print();

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

                // update type
                $$->HelperType = $1->HelperType;

                // init & update vector
                $$->v = $1->v;
                $3->setVarType("array");
                $$->v.push_back($3);
                // $$->print();

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

                // update type
                $$->HelperType = $1->HelperType;

                // int & update vector
                $$->v = $1->v;
                $3->setVarType("array");
                $$->v.push_back($3);
                // $$->print();

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
                    $1->setVarType("array");
                    $$->v.push_back($1);
                    // cout<<"PRINT"<<endl;
                    // $$->print();

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
            $$ = new Helper();
            $$->text = $1->text;
            print_log_text($$->text);

        }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
            print_grammar_rule("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");

            $$ = new Helper();
            // update text
            $$->text = "for";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += $4->text;
            $$->text += $5->text;
            $$->text += ")";
            $$->text += $7->text;
            
            print_log_text($$->text);
        }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE { 
            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
            
            $$ = new Helper();
            // update text
            $$->text = "if";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;

            print_log_text($$->text);
        }
	  | IF LPAREN expression RPAREN statement ELSE statement {

            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
        
            $$ = new Helper();
            // update text
            $$->text = "if";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;
            $$->text += "\nelse ";
            $$->text += $7->text;

            print_log_text($$->text);
        
        }
	  | WHILE LPAREN expression RPAREN statement {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");

            $$ = new Helper();
            // update text
            $$->text = "while";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;

            print_log_text($$->text);
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
        | RETURN SEMICOLON {

            /***
                EXTRA RULE ADDED 
            ***/

            print_grammar_rule("statement","RETURN SEMICOLON");

            $$ = new Helper();
            $$->text = "return";
            $$->text += ";";

            print_log_text($$->text);
        }
        | error SEMICOLON {
            cout<<"inside error statement ;"<<endl;
            yyclearin;
            yyerrok;
        }
        | error RCURL {
            cout<<"inside error statement }"<<endl;
            yyclearin;
            yyerrok;
        }
	  ;
	  
expression_statement: SEMICOLON	{
                    print_grammar_rule("expression_statement","SEMICOLON");

                    $$ = new Helper();
                    $$->text = ";";

                    print_log_text($$->text);
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

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($1->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($1->key);
                $$->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int_array" || ret_symbol->var_type == "float_array")
                {
                   error_type_mismatch(); // should i change this to indexing
                }

                 $$->setHelperType(ret_symbol->var_type);
                 cout<<"Helper : "<<$$->HelperType<<endl;
            }

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
            SymbolInfo* ret_symbol = sym_tab->lookup($1->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($1->key);
                $$->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int" || ret_symbol->var_type == "float")
                {
                   error_type_mismatch();
                }

                $$->setHelperType(ret_symbol->var_type);
                // cout<<"HelperType : "<<$$->HelperType<<endl;
            }

            if($3->HelperType != "int")
            {
                error_array_index_invalid();
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

                // update text
                $$->text = $1->text;
                $$->text += "=";
                $$->text += $3->text;

                //check error
                cout<<$1->HelperType<<" ---- "<<$3->HelperType<<endl;
                if(!check_assignop($1->HelperType,$3->HelperType))
                {
                    error_type_mismatch();
                }

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
                    cout<<$1->HelperType<<" --- "<<$3->HelperType<<endl;
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
                    $$->setHelperType("NULL");
                }
                else{
                    $$->setHelperType("int");
                    cout<<"HERERE"<<endl;
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
            // implicit typecast
            $$->HelperType = $1->HelperType;

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

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($1->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($1->key);
                $$->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->isFunction == false)
                {
                    $$->setHelperType("NULL");
                    error_not_function($1->key);
                    break;
                }

                $$->setHelperType(ret_symbol->var_type);

                if(ret_symbol->isFunctionDeclaration) // only declared , no definition
                {
                    error_function_not_implemented();
                }
                else // other errors
                {
                    // printing function param_list
                    cout<<"OG Param : ";
                    for(auto s:ret_symbol->param_v)
                    {
                        cout<<s<<" , ";
                    }
                    cout<<endl;

                    // printing argument_list
                    cout<<"Called Args : ";
                    for(auto s:$3->param_v)
                    {
                        cout<<s<<" , ";
                    }
                    cout<<endl;

                    if(ret_symbol->param_v.size() != $3->param_v.size())
                    {
                        error_function_parameter_number();
                    }
                    else
                    {
                        for(int i=0;i<ret_symbol->param_v.size();i++)
                        {
                            if(!is_param_typecast_ok(ret_symbol->param_v[i],$3->param_v[i])){
                                error_function_parameter_type();
                                break;
                            }
                        }
                    }
                }
            }

            print_log_text($$->text);
        }
	| LPAREN expression RPAREN {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            $$ = new Helper();
            // update text
            $$->text = "(";
            $$->text += $2->text;
            $$->text += ")";

            $$->HelperType = $2->HelperType;

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

            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "++";

            print_log_text($$->text);
        }
	| variable DECOP {
            print_grammar_rule("factor","variable DECOP");

            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "--";

            print_log_text($$->text);
        }
	;
	
argument_list: arguments {

                    print_grammar_rule("argument_list","arguments");

                    $$ = new Helper();
                    $$->text = $1->text;

                    $$->param_v = $1->param_v; 

                    print_log_text($$->text);
                }
			| {
                print_grammar_rule("argument_list","");
                $$ = new Helper();
            }   
			;
	
arguments: arguments COMMA logic_expression {

                print_grammar_rule("arguments","arguments COMMA logic_expression");
                
                $$ = new Helper();
                $$->text = $1->text; 
                $$->text += " , "; 
                $$->text += $3->text;

                // update vector
                $$->param_v = $1->param_v; 
                $$->param_v.push_back($3->HelperType);

                print_log_text($$->text);
            }
	    | logic_expression {

                print_grammar_rule("arguments","logic_expression");

                $$ = new Helper();

                // update text
                $$->text = $1->text; 
                // update helper type
                $$->HelperType = $1->HelperType;
                cout<<"Logic Helper : "<<$$->HelperType<<endl;
                // init vector
                $$->param_v.push_back($1->HelperType);

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

    sym_tab->print_all_scope();

    cout<<"Total Lines : "<<line_count<<endl;

    fclose(yyin);

    exit(0);
}
