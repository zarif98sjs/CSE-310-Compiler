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

// #define YYSTYPE SymbolInfo*

extern FILE *yyin;

void yyerror(char *s){
	printf("%s\n",s);
}

int yyparse(void);
int yylex(void);

extern int line_count;


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

void print_grammar_rule(string left_part,string right_part)
{
    cout<<"At line no: "<<line_count<<" "<<left_part<<" : "<<right_part<<"\n"<<endl; 
}

%}


%union{
    SymbolInfo* symbol_info;
    // SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    // int ival;
    // double dval;
}

%token IF ELSE LOWER_THAN_ELSE FOR WHILE DO BREAK CHAR DOUBLE RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN INCOP DECOP ASSIGNOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token <symbol_info> ID INT FLOAT VOID ADDOP MULOP RELOP LOGICOP CONST_INT CONST_FLOAT
// %token <ival> CONST_INT
// %token <dval> CONST_FLOAT

%type < temp_str > start program unit variable var_declaration type_specifier func_declaration func_definition parameter_list
// %type < temp_str > expression logic_expression rel_expression simple_expression term  factor argument_list arguments
%type < temp_str > expression factor unary_expression term simple_expression rel_expression statement statements compound_statement logic_expression expression_statement
%type < temp_str > arguments argument_list
%type < symbol_info_str > declaration_list

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
            $$ = new string();
            *$$ = *$1;
            *$$ += "\n";
            *$$ += *$2;
            cout<<*$$<<"\n"<<endl; 
        }
	| unit { 
            print_grammar_rule("program","unit");
            cout<<*$1<<"\n"<<endl; 
        }
	;
	
unit: var_declaration { print_grammar_rule("unit","var_declaration"); cout<<*$1<<"\n"<<endl; }
     | func_declaration { print_grammar_rule("unit","func_declaration"); cout<<*$1<<"\n"<<endl; }
     | func_definition { print_grammar_rule("unit","func_definition"); cout<<*$1<<"\n"<<endl; }
     ;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
                // *$$ = *$1;
                // *$$ += " ";
                // *$$ += $2->key;
                // *$$ += "(";
                // *$$ += ")";
                // *$$ += ";";

                // cout<<*$$<<"\n"<<endl;
    
            }
		| type_specifier ID LPAREN RPAREN SEMICOLON { 
                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
                $$ = new string();
                *$$ = *$1;
                *$$ += " ";
                *$$ += $2->key;
                *$$ += "(";
                *$$ += ")";
                *$$ += ";";

                cout<<*$$<<"\n"<<endl;

            }
		;
		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                $$ = new string();
                *$$ = *$1;
                *$$ += " ";
                *$$ += $2->key;
                *$$ += "(";
                *$$ += *$4;
                *$$ += ")";
                *$$ += *$6;

                cout<<*$$<<"\n"<<endl;

            }
		| type_specifier ID LPAREN RPAREN compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN RPAREN compound_statement");

                $$ = new string();
                *$$ = *$1;
                *$$ += " ";
                *$$ += $2->key;
                *$$ += "(";
                *$$ += ")";
                *$$ += *$5;

                cout<<*$$<<"\n"<<endl;
            
            }
 		;				


parameter_list: parameter_list COMMA type_specifier ID {

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

                $$ = new string();
                *$$ = *$1;
                *$$ += ",";
                *$$ += *$3;
                *$$ += " ";
                *$$ += $4->key;

                cout<<*$$<<"\n"<<endl;

            }
		| parameter_list COMMA type_specifier {
             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");
        }
 		| type_specifier ID  { 
                print_grammar_rule("parameter_list","type_specifier ID");
                
                $$ = new string();
                *$$ = *$1;
                *$$ += " ";
                *$$ += $2->key;

                cout<<*$$<<"\n"<<endl;
             }
		| type_specifier {
            print_grammar_rule("parameter_list","type_specifier");
        }
 		;

 		
compound_statement: LCURL statements RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                // string temp = *$2;
                $$ = new string();
                *$$ = "{\n"; 
                *$$ += *$2; 
                *$$ += "\n}"; 
                cout<<*$$<<"\n"<<endl;

                sym_tab->print_all_scope();
                sym_tab->exit_scope();

             }
 		    | LCURL RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");

                $$ = new string();
                *$$ = "{\n";  
                *$$ += "\n}"; 
                cout<<*$$<<"\n"<<endl;

                sym_tab->print_all_scope();
                sym_tab->exit_scope();
             }
 		    ;
 		    
var_declaration: type_specifier declaration_list SEMICOLON { 

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
            $$ = new string();
            *$$ = *$1;
            *$$ += " ";
            *$$ += *$2;
            *$$ += ";";

            cout<<*$$<<"\n"<<endl;
        }
 		 ;
 		 
type_specifier: INT  { print_grammar_rule("type_specifier","INT"); cout<<$1->key<<"\n"<<endl; *$$ = $1->key; }
 		| FLOAT { print_grammar_rule("type_specifier","FLOAT"); cout<<$1->key<<"\n"<<endl; *$$ = $1->key;}
 		| VOID { print_grammar_rule("type_specifier","VOID"); cout<<$1->key<<"\n"<<endl; *$$ = $1->key;}
 		;
 		
declaration_list: declaration_list COMMA ID { 
                    print_grammar_rule("declaration_list","declaration_list COMMA ID");
                    
                    $$ = new string();
                    *$$ = *$1;
                    *$$ += ",";
                    *$$ += $3->key;
                    cout<< *$$ <<"\n"<<endl;
                }
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
                $$ = new string();
                *$$ = *$1;
                *$$ += ",";
                *$$ += $3->key;
                *$$ += "[";
                *$$ += $5->key;
                *$$ += "]";

                cout<< *$$ <<"\n"<<endl;
           
           }
 		  | ID { 
               print_grammar_rule("declaration_list","ID");
               cout<<$1->key<<"\n"<<endl;
                $$ = new string();
                *$$ = $1->key;
               }
 		  | ID LTHIRD CONST_INT RTHIRD
           {
               print_grammar_rule("declaration_list","ID LTHIRD CONST_INT RTHIRD");
           
                $$ = new string();
                *$$ = $1->key;
                *$$ += "[";
                *$$ += $3->key;
                *$$ += "]";

                cout<< *$$ <<"\n"<<endl;
           }
 		  ;
 		  
statements: statement {
            print_grammar_rule("statements","statement");
            
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl; 
        }
	   | statements statement {
            print_grammar_rule("statements","statements statement");
        
            $$ = new string();
            *$$ = *$1;
            *$$ += "\n";
            *$$ += *$2;

            cout<<*$$<<"\n"<<endl; 
        }
	   ;
	   
statement: var_declaration {
            print_grammar_rule("statement","var_declaration");
    
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;
        }
	  | expression_statement {
            print_grammar_rule("statement","expression_statement");
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;
        }
	  | compound_statement {
            print_grammar_rule("statement","compound_statement");
        }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
            print_grammar_rule("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");
        }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE { 
            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
            
            $$ = new string();
            *$$ = "if";
            *$$ += "(";
            *$$ += *$3;
            *$$ += ")";
            *$$ += *$5;

            cout<<*$$<<"\n"<<endl;

        }
	  | IF LPAREN expression RPAREN statement ELSE statement {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");
        
            $$ = new string();
            *$$ = "if";
            *$$ += "(";
            *$$ += *$3;
            *$$ += ")";
            *$$ += *$5;
            *$$ += "else ";
            *$$ += *$7;

            cout<<*$$<<"\n"<<endl;
        
        }
	  | WHILE LPAREN expression RPAREN statement {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");
        }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");
        }
	  | RETURN expression SEMICOLON {
            print_grammar_rule("statement","RETURN expression SEMICOLON");

            $$ = new string();
            *$$ = "return";
            *$$ += " ";
            *$$ += *$2;
            *$$ += ";";

            cout<<*$$<<"\n"<<endl;
        }
	  ;
	  
expression_statement: SEMICOLON	{
                    print_grammar_rule("expression_statement","SEMICOLON");
                }		
			| expression SEMICOLON {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    $$ = new string();
                    *$$ = *$1;
                    *$$ += ";";

                    cout<<*$$<<"\n"<<endl;
                }
			;
	  
variable: ID { 
            print_grammar_rule("variable","ID");
            $$ = new string();
            *$$ = $1->key;
            cout<<*$$<<"\n"<<endl;
        }		
	 | ID LTHIRD expression RTHIRD {
            print_grammar_rule("variable","ID LTHIRD expression RTHIRD");
            
            $$ = new string();
            *$$ = $1->key;
            *$$ += "[";
            *$$ += *$3;
            *$$ += "]";

            cout<<*$$<<"\n"<<endl;
         }
	 ;
	 
 expression: logic_expression	{
                print_grammar_rule("expression","logic_expression");
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
            }
	   | variable ASSIGNOP logic_expression {
                print_grammar_rule("expression","variable ASSIGNOP logic_expression");
                $$ = new string();
                *$$ = *$1;
                *$$ += "=";
                *$$ += *$3;
                cout<<*$$<<"\n"<<endl;
            }	
	   ;


			 
logic_expression: rel_expression {
                print_grammar_rule("logic_expression","rel_expression");
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
            }	
		 | rel_expression LOGICOP rel_expression {
                print_grammar_rule("logic_expression","rel_expression LOGICOP rel_expression");
                $$ = new string();
                *$$ = *$1;
                *$$ += $2->key;
                *$$ += *$3;
                cout<<*$$<<"\n"<<endl;
            }	
		 ;
			
rel_expression: simple_expression {
                print_grammar_rule("rel_expression","simple_expression");
                $$ = new string();
                *$$ = *$1;
                 cout<<*$$<<"\n"<<endl;
            }
		| simple_expression RELOP simple_expression	{
                print_grammar_rule("rel_expression","simple_expression RELOP simple_expression");
                $$ = new string();
                *$$ = *$1;
                *$$ += $2->key;
                *$$ += *$3;
                cout<<*$$<<"\n"<<endl;
            }
		;
				
simple_expression: term {
                print_grammar_rule("simple_expression","term");
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
            }
		  | simple_expression ADDOP term {
               print_grammar_rule("simple_expression","simple_expression ADDOP term");
               $$ = new string();
               *$$ = *$1;
               *$$ += $2->key;
               *$$ += *$3;

               cout<<*$$<<"\n"<<endl;
            }
		  ;
					
term:	unary_expression {
            print_grammar_rule("term","unary_expression");
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;
        }
    |  term MULOP unary_expression {
            print_grammar_rule("term","term MULOP unary_expression");
            $$ = new string();
            *$$ = *$1;
            *$$ += $2->key;
            *$$ += *$3;
            cout<<*$$<<"\n"<<endl;
        }
    ;

unary_expression: ADDOP unary_expression  {
                print_grammar_rule("unary_expression","ADDOP unary_expression");
                
                $$ = new string();
                *$$ = $1->key;
                *$$ += *$2;
                cout<<*$$<<"\n"<<endl;
            }
		 | NOT unary_expression {
                print_grammar_rule("unary_expression","NOT unary_expression");
                
                $$ = new string();
                *$$ = *$2;
            }
		 | factor  { 
                print_grammar_rule("unary_expression","factor");
                
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
             }
		 ;
	
factor: variable {

            print_grammar_rule("factor","variable");
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;

        }
	| ID LPAREN argument_list RPAREN {
            print_grammar_rule("factor","ID LPAREN argument_list RPAREN");

            $$ = new string();
            *$$ = $1->key;
            *$$ += "( ";
            *$$ += *$3;
            *$$ += " )";
            cout<<*$$<<"\n"<<endl;

        }
	| LPAREN expression RPAREN {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            $$ = new string();
            *$$ = "(";
            *$$ += *$2;
            *$$ += ")";
            cout<<*$$<<"\n"<<endl;
        
        }
	| CONST_INT  { 
            print_grammar_rule("factor","CONST_INT");
            $$ = new string();
            *$$ = $1->key;
            cout<<*$$<<"\n"<<endl;
        }
	| CONST_FLOAT  { 
            print_grammar_rule("factor","CONST_FLOAT");
            $$ = new string();
            *$$ = $1->key; 
            cout<<*$$<<"\n"<<endl;
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

                    $$ = new string();
                    *$$ = *$1; 
                    cout<<*$$<<"\n"<<endl;
                }
			| {
                cout<<"WHAT IS THIS"<<endl;
            }   
			;
	
arguments: arguments COMMA logic_expression {

                print_grammar_rule("arguments","arguments COMMA logic_expression");
                
                $$ = new string();
                *$$ = *$1; 
                *$$ += " , "; 
                *$$ += *$3; 
                cout<<*$$<<"\n"<<endl;
            }
	    | logic_expression {

                print_grammar_rule("arguments","logic_expression");

                $$ = new string();
                *$$ = *$1; 
                cout<<*$$<<"\n"<<endl;
            
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
