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

int bucket_size = 7;
SymbolTable *table = new SymbolTable(bucket_size,hashF);;

%}


%union{
    SymbolInfo* symbol_info;
    SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    // int ival;
    // double dval;
}

%token <ival> IF ELSE LOWER_THAN_ELSE FOR WHILE DO BREAK CHAR DOUBLE RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN INCOP DECOP ASSIGNOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
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
            cout<<"At line no: "<<line_count<<" program : program unit\n"<<endl; 
            
            $$ = new string();
            *$$ = *$1;
            *$$ += "\n";
            *$$ += *$2;
            cout<<*$$<<"\n"<<endl; 
        }
	| unit { 
            cout<<"At line no: "<<line_count<<" program : unit\n"<<endl; 
            cout<<*$1<<"\n"<<endl; 
        }
	;
	
unit: var_declaration { cout<<"At line no: "<<line_count<<" unit : var_declaration\n"<<endl; cout<<*$1<<"\n"<<endl; }
     | func_declaration { cout<<"At line no: "<<line_count<<" unit : func_declaration\n"<<endl; cout<<*$1<<"\n"<<endl; }
     | func_definition { cout<<"At line no: "<<line_count<<" unit : func_definition\n"<<endl; cout<<*$1<<"\n"<<endl; }
     ;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON { 
                
                cout<<"At line no: "<<line_count<<" func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"<<endl; 
                
                // *$$ = *$1;
                // *$$ += " ";
                // *$$ += $2->key;
                // *$$ += "(";
                // *$$ += ")";
                // *$$ += ";";

                // cout<<*$$<<"\n"<<endl;
    
            }
		| type_specifier ID LPAREN RPAREN SEMICOLON { 
                cout<<"At line no: "<<line_count<<" func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n"<<endl; 
                
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
                cout<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<<endl;  
                
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
                cout<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement\n"<<endl;  

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

                cout<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier ID\n"<<endl;  

                $$ = new string();
                *$$ = *$1;
                *$$ += ",";
                *$$ += *$3;
                *$$ += " ";
                *$$ += $4->key;

                cout<<*$$<<"\n"<<endl;

            }
		| parameter_list COMMA type_specifier
 		| type_specifier ID  { 
                cout<<"At line no: "<<line_count<<" parameter_list : type_specifier ID\n"<<endl;  
                
                $$ = new string();
                *$$ = *$1;
                *$$ += " ";
                *$$ += $2->key;

                cout<<*$$<<"\n"<<endl;
             }
		| type_specifier
 		;

 		
compound_statement: LCURL statements RCURL {
                cout<<"At line no: "<<line_count<<" compound_statement : LCURL statements RCUR\n"<<endl;
                
                // string temp = *$2;
                $$ = new string();
                *$$ = "{\n"; 
                *$$ += *$2; 
                *$$ += "\n}"; 
                cout<<*$$<<"\n"<<endl;
             }
 		    | LCURL RCURL {
                cout<<"At line no: "<<line_count<<" LCURL RCURL\n"<<endl; 

                $$ = new string();
                *$$ = "{\n";  
                *$$ += "\n}"; 
                cout<<*$$<<"\n"<<endl;
             }
 		    ;
 		    
var_declaration: type_specifier declaration_list SEMICOLON { 

            cout<<"At line no: "<<line_count<<" var_declaration : type_specifier declaration_list SEMICOLON\n"<<endl; 
            
            $$ = new string();
            *$$ = *$1;
            *$$ += " ";
            *$$ += *$2;
            *$$ += ";";

            cout<<*$$<<"\n"<<endl;
        }
 		 ;
 		 
type_specifier: INT  { cout<<"At line no: "<<line_count<<" type_specifier : INT\n"<<endl; cout<<$1->key<<"\n"<<endl; *$$ = $1->key; }
 		| FLOAT { cout<<"At line no: "<<line_count<<" type_specifier : FLOAT\n"<<endl; cout<<$1->key<<"\n"<<endl; *$$ = $1->key;}
 		| VOID { cout<<"At line no: "<<line_count<<" type_specifier : VOID\n"<<endl; cout<<$1->key<<"\n"<<endl; *$$ = $1->key;}
 		;
 		
declaration_list: declaration_list COMMA ID { 
                    cout<<"At line no: "<<line_count<<" declaration_list COMMA ID\n"<<endl; 
                    
                    $$ = new string();
                    *$$ = *$1;
                    *$$ += ",";
                    *$$ += $3->key;
                    cout<< *$$ <<"\n"<<endl;
                }
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
               cout<<"At line no: "<<line_count<<" declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n"<<endl; 
           
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
               cout<<"At line no: "<<line_count<<" declaration_list : ID\n"<<endl; cout<<$1->key<<"\n"<<endl;
                $$ = new string();
                *$$ = $1->key;
               }
 		  | ID LTHIRD CONST_INT RTHIRD
           {
               cout<<"At line no: "<<line_count<<" declaration_list : ID LTHIRD CONST_INT RTHIRD\n"<<endl;
           
                $$ = new string();
                *$$ = $1->key;
                *$$ += "[";
                *$$ += $3->key;
                *$$ += "]";

                cout<< *$$ <<"\n"<<endl;
           }
 		  ;
 		  
statements: statement {
            cout<<"At line no: "<<line_count<<" statements : statement\n"<<endl;
            
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl; 
        }
	   | statements statement {
            cout<<"At line no: "<<line_count<<" statements : statements statement\n"<<endl; 
        
            $$ = new string();
            *$$ = *$1;
            *$$ += "\n";
            *$$ += *$2;

            cout<<*$$<<"\n"<<endl; 
        }
	   ;
	   
statement: var_declaration {
            cout<<"At line no: "<<line_count<<" statement : var_declaration\n"<<endl; 
    
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;
        }
	  | expression_statement {
            cout<<"At line no: "<<line_count<<" statement : expression_statement\n"<<endl; 
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;
        }
	  | compound_statement {
            cout<<"At line no: "<<line_count<<" statement : compound_statement\n"<<endl; 
        }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
            cout<<"At line no: "<<line_count<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<<endl; 
        }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement\n"<<endl; 
            
            $$ = new string();
            *$$ = "if";
            *$$ += "(";
            *$$ += *$3;
            *$$ += ")";
            *$$ += *$5;

            cout<<*$$<<"\n"<<endl;

        }
	  | IF LPAREN expression RPAREN statement ELSE statement {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement ELSE statemen\n"<<endl; 
        
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
            cout<<"At line no: "<<line_count<<" statement : WHILE LPAREN expression RPAREN statement\n"<<endl; 
        }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
            cout<<"At line no: "<<line_count<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<<endl; 
        }
	  | RETURN expression SEMICOLON {
            cout<<"At line no: "<<line_count<<" statement : RETURN expression SEMICOLON\n"<<endl; 

            $$ = new string();
            *$$ = "return";
            *$$ += " ";
            *$$ += *$2;
            *$$ += ";";

            cout<<*$$<<"\n"<<endl;
        }
	  ;
	  
expression_statement: SEMICOLON	{
                    cout<<"At line no: "<<line_count<<" expression_statement : SEMICOLON\n"<<endl; 
                }		
			| expression SEMICOLON {
                    cout<<"At line no: "<<line_count<<" expression_statement : expression SEMICOLON\n"<<endl; 
                    $$ = new string();
                    *$$ = *$1;
                    *$$ += ";";

                    cout<<*$$<<"\n"<<endl;
                }
			;
	  
variable: ID { 
            cout<<"At line no: "<<line_count<<" variable : ID\n"<<endl; 
            $$ = new string();
            *$$ = $1->key;
            cout<<*$$<<"\n"<<endl;
        }		
	 | ID LTHIRD expression RTHIRD {
            cout<<"At line no: "<<line_count<<" variable : ID LTHIRD expression RTHIRD\n"<<endl; 
            
            $$ = new string();
            *$$ = $1->key;
            *$$ += "[";
            *$$ += *$3;
            *$$ += "]";

            cout<<*$$<<"\n"<<endl;
         }
	 ;
	 
 expression: logic_expression	{
                cout<<"At line no: "<<line_count<<" expression : logic_expression\n"<<endl; 
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
            }
	   | variable ASSIGNOP logic_expression {
                cout<<"At line no: "<<line_count<<" expression : variable ASSIGNOP logic_expression\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                *$$ += "=";
                *$$ += *$3;
                cout<<*$$<<"\n"<<endl;
            }	
	   ;


			 
logic_expression: rel_expression {
                cout<<"At line no: "<<line_count<<" logic_expression : rel_expression\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
            }	
		 | rel_expression LOGICOP rel_expression {
                cout<<"At line no: "<<line_count<<" logic_expression : rel_expression LOGICOP rel_expression\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                *$$ += $2->key;
                *$$ += *$3;
                cout<<*$$<<"\n"<<endl;
            }	
		 ;
			
rel_expression: simple_expression {
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                 cout<<*$$<<"\n"<<endl;
            }
		| simple_expression RELOP simple_expression	{
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression RELOP simple_expression\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                *$$ += $2->key;
                *$$ += *$3;
                cout<<*$$<<"\n"<<endl;
            }
		;
				
simple_expression: term {
                cout<<"At line no: "<<line_count<<" simple_expression : term\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
            }
		  | simple_expression ADDOP term {
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
               $$ = new string();
               *$$ = *$1;
               *$$ += $2->key;
               *$$ += *$3;

               cout<<*$$<<"\n"<<endl;
            }
		  ;
					
term:	unary_expression {
            cout<<"At line no: "<<line_count<<" term : unary_expression\n"<<endl;
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;
        }
    |  term MULOP unary_expression {
            cout<<"At line no: "<<line_count<<" term : term MULOP unary_expressio\n"<<endl;
            $$ = new string();
            *$$ = *$1;
            *$$ += $2->key;
            *$$ += *$3;
            cout<<*$$<<"\n"<<endl;
        }
    ;

unary_expression: ADDOP unary_expression  {
                
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
                $$ = new string();
                *$$ = $1->key;
                *$$ += *$2;
                cout<<*$$<<"\n"<<endl;
            }
		 | NOT unary_expression {
                $$ = new string();
                *$$ = *$2;
            }
		 | factor  { 
                cout<<"At line no: "<<line_count<<" unary_expression : factor\n"<<endl;
                $$ = new string();
                *$$ = *$1;
                cout<<*$$<<"\n"<<endl;
             }
		 ;
	
factor: variable {
            cout<<"At line no: "<<line_count<<" factor : variable\n"<<endl;
            $$ = new string();
            *$$ = *$1;
            cout<<*$$<<"\n"<<endl;

        }
	| ID LPAREN argument_list RPAREN {
            cout<<"At line no: "<<line_count<<" factor : ID LPAREN argument_list RPAREN\n"<<endl; 

            $$ = new string();
            *$$ = $1->key;
            *$$ += "( ";
            *$$ += *$3;
            *$$ += " )";
            cout<<*$$<<"\n"<<endl;

        }
	| LPAREN expression RPAREN {
            cout<<"At line no: "<<line_count<<" factor : LPAREN expression RPAREN\n"<<endl; 

            $$ = new string();
            *$$ = "(";
            *$$ += *$2;
            *$$ += ")";
            cout<<*$$<<"\n"<<endl;
        
        }
	| CONST_INT  { 
            cout<<"At line no: "<<line_count<<" factor : CONST_INT\n"<<endl; 
            $$ = new string();
            *$$ = $1->key;
            cout<<*$$<<"\n"<<endl;
        }
	| CONST_FLOAT  { 
            cout<<"At line no: "<<line_count<<" factor : CONST_FLOAT\n"<<endl;
            $$ = new string();
            *$$ = $1->key; 
            cout<<*$$<<"\n"<<endl;
        }
	| variable INCOP {
            cout<<"At line no: "<<line_count<<" factor : variable INCOP\n"<<endl; 
        }
	| variable DECOP {
            cout<<"At line no: "<<line_count<<" factor : variable DECOP\n"<<endl; 
        }
	;
	
argument_list: arguments {
                    cout<<"At line no: "<<line_count<<" arguments : arguments\n"<<endl;

                    $$ = new string();
                    *$$ = *$1; 
                    cout<<*$$<<"\n"<<endl;
                }
			| {
                cout<<"WHAT IS THIS"<<endl;
            }   
			;
	
arguments: arguments COMMA logic_expression {
                cout<<"At line no: "<<line_count<<" arguments : arguments COMMA logic_expression\n"<<endl;
                $$ = new string();
                *$$ = *$1; 
                *$$ += " , "; 
                *$$ += *$3; 
                cout<<*$$<<"\n"<<endl;
            }
	    | logic_expression {
                cout<<"At line no: "<<line_count<<" arguments : logic_expression\n"<<endl;

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
