%{
#include<bits/stdc++.h>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

// #define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

void yyerror(char *s)
{
	//write your code
}


%}

%union{
	int ival;
	SymbolInfo* si;
	vector<SymbolInfo*>* vs;
}

%token  SEMICOLON
%token <si> INT ID 

%type <vs> declaration_list

// %left 
// %right

%nonassoc THEN 
%nonassoc ELSE


%%

start : program
	{
		//write your code in this block in all the similar blocks below
	}
	;

program: unit { cout<<"program: unit"<<endl; }
	;
	
unit: var_declaration { cout<<"unit : var_declaration"<<endl; }
     ;
        
var_declaration: type_specifier declaration_list SEMICOLON { 
			cout<<"var_declaration: type_specifier declaration_list SEMICOLON"<<endl; 
			
			cout<<"Vector size : "<<$2->size()<<endl;
			cout<<$2->back()->key<<endl;
	}
 		 ;
 		  
type_specifier: INT  { cout<<"type_specifier	: INT"<<endl; }
 		;
 		
declaration_list: ID { 
			cout<<"declaration_list : ID "<<endl; 
			cout<<$1->key<<endl;

			$$ = new vector<SymbolInfo*>();

			$$->push_back($1);
			$$->push_back($1);
		}
 		  ;

%%
int main(int argc,char *argv[])
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

	
	return 0;
}

