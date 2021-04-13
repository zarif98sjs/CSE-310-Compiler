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

%token NEWLINE NUMBER PLUS MINUS SLASH ASTERISK LPAREN RPAREN ID


%%
input:              /* empty string */
    | input line
    ;
line: NEWLINE
    | expr NEWLINE           { cout<<$1->key<<endl;cout<<"inside line"<<endl; }
    ;
expr: expr PLUS term         { cout<<"inside expr1"<<endl; }
    | expr MINUS term        { cout<<"inside expr2"<<endl; }
    | term
    ;
term: term ASTERISK factor   { cout<<"inside term1"<<endl;; }
    | term SLASH factor       { cout<<"inside term2"<<endl; }
    | factor
    ;
factor:  LPAREN expr RPAREN { cout<<"inside factor1"<<endl; }
      | NUMBER { cout<<"inside factor2"<<endl; }
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
