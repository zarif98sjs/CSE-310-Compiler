%{
#include<bits/stdc++.h>

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

#define YYSTYPE SymbolInfo*

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

%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN CONST_INT CONST_FLOAT ID ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON

%%

start: program
	{
		//write your code in this block in all the similar blocks below
	}
	;

program: program unit 
	| unit
	;
	
unit: var_declaration
     | func_declaration
     | func_definition
     ;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON { cout<<"func_declaration --> type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl; }
		| type_specifier ID LPAREN RPAREN SEMICOLON { cout<<"func_declaration --> type_specifier ID LPAREN RPAREN SEMICOLON"<<endl; }
		;
		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement { cout<<"func_definition --> type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl; }
		| type_specifier ID LPAREN RPAREN compound_statement { cout<<"func_definition --> type_specifier ID LPAREN RPAREN compound_statement "<<endl; }
 		;				


parameter_list: parameter_list COMMA type_specifier ID
		| parameter_list COMMA type_specifier
 		| type_specifier ID  { cout<<"parameter_list --> type_specifier ID"<<endl; }
		| type_specifier
 		;

 		
compound_statement: LCURL statements RCURL
 		    | LCURL RCURL
 		    ;
 		    
var_declaration: type_specifier declaration_list SEMICOLON { cout<<"At line no: "<<line_count<<" var_declaration --> type_specifier declaration_list SEMICOLON"<<endl; }
 		 ;
 		 
type_specifier: INT  { cout<<"At line no: "<<line_count<<" type_specifier : INT\n"<<endl; cout<<"int\n"<<endl;}
 		| FLOAT { cout<<"At line no: "<<line_count<<" type_specifier : FLOAT\n"<<endl; cout<<"float\n"<<endl;}
 		| VOID { cout<<"At line no: "<<line_count<<" type_specifier : VOID\n"<<endl; cout<<"void\n"<<endl;}
 		;
 		
declaration_list: declaration_list COMMA ID { 
                    cout<<"At line no: "<<line_count<<" declaration_list COMMA ID\n"<<endl; 
                    vector<string> temp = $1;
                    temp.push_back($3->key);
                    $$ = temp;

                    while(!temp.empty())
                    {
                        cout<<temp.back()<<endl;
                        temp.pop_back();
                    }
                }
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
 		  | ID { 
               cout<<"At line no: "<<line_count<<" declaration_list : ID\n"<<endl; cout<<$1->key<<"\n"<<endl;
               $$ = vector<string>();
               $$.push_back($1->key);
               }
 		  | ID LTHIRD CONST_INT RTHIRD
 		  ;
 		  
statements: statement
	   | statements statement
	   ;
	   
statement: var_declaration
	  | expression_statement
	  | compound_statement
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  | IF LPAREN expression RPAREN statement
	  | IF LPAREN expression RPAREN statement ELSE statement
	  | WHILE LPAREN expression RPAREN statement
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  | RETURN expression SEMICOLON
	  ;
	  
expression_statement: SEMICOLON			
			| expression SEMICOLON 
			;
	  
variable: ID { cout<<"variable --> ID"<<endl; }		
	 | ID LTHIRD expression RTHIRD 
	 ;
	 
 expression: logic_expression	
	   | variable ASSIGNOP logic_expression 	
	   ;
			
logic_expression: rel_expression 	
		 | rel_expression LOGICOP rel_expression 	
		 ;
			
rel_expression: simple_expression 
		| simple_expression RELOP simple_expression	
		;
				
simple_expression: term 
		  | simple_expression ADDOP term 
		  ;
					
term:	unary_expression
    |  term MULOP unary_expression
    ;

unary_expression: ADDOP unary_expression  
		 | NOT unary_expression 
		 | factor  { cout<<"unary_expression --> factor"<<endl; }
		 ;
	
factor: variable 
	| ID LPAREN argument_list RPAREN
	| LPAREN expression RPAREN
	| CONST_INT  { cout<<"factor --> CONST_INT"<<endl; }
	| CONST_FLOAT  { cout<<"factor --> CONST_FLOAT"<<endl; }
	| variable INCOP 
	| variable DECOP
	;
	
argument_list: arguments
			|
			;
	
arguments: arguments COMMA logic_expression
	    | logic_expression
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
