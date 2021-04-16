%{
#include<bits/stdc++.h>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "Helper.h"

// #define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

SymbolTable *table;


void yyerror(char *s)
{
	//write your code
}


%}

%union{
	int ival;
	SymbolInfo* si;
	vector<SymbolInfo*>* vs;
	Helper* helper;
}

%token <ival> SEMICOLON 
%token <si> INT ID 

%type <helper> declaration_list

// %left 
// %right

// %nonassoc 


%%

start: program
	{
		//write your code in this block in all the similar blocks below
	}
	;

program: unit { cout<<"program: unit\n"<<endl;}
	;
	
unit: var_declaration { cout<<"unit: var_declaration\n"<<endl;}
     ;
         
var_declaration: type_specifier {cout<<"actionnn"<<endl;} declaration_list SEMICOLON { 
				cout<<"var_declaration: type_specifier declaration_list SEMICOLON\n"<<endl;

				$3->print();
			}
 		 ;
 		 
type_specifier: INT { cout<<"type_specifier: INT\n"<<endl;}
 		;
 		
declaration_list: ID { 
				cout<<"declaration_list : ID\n"<<endl; 
				cout<<$1->key<<"\n"<<endl;

				$$ = new Helper();
				
				$$->text = $1->key;
				$$->v.push_back($1);
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

