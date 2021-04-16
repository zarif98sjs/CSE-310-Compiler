%{
#include<bits/stdc++.h>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

// #define YYSTYPE SymbolInfo*

#include "y.tab.h"


using namespace std;

extern YYSTYPE yylval;
extern SymbolTable *table;
void yyerror(char *);

int line_count=1;
int error=0;

%}


digit [0-9]
letter [A-Za-z]
delim [ \t\r\f\v]
newline \n
ws [delim]+
id (_|{letter})(_|{letter}|{digit})*
integer {digit}+
number {digit}*(\.{digit}+)?(E[+-]?{digit}+)?
ADDOP [+-] 
MULOP [*/%]

%%

{delim}+	{}
{newline} {line_count++;}

"int" 	{
			SymbolInfo* s= new SymbolInfo(yytext,"INT"); 
			yylval.si = s;
			return INT;
		}
";"	{return SEMICOLON;}

{id} 	{	 
							
			SymbolInfo* s= new SymbolInfo(yytext,"ID");
			yylval.si = s;
							
			return ID;
		}


%%

int yywrap(void)
{
	return 1;
}






