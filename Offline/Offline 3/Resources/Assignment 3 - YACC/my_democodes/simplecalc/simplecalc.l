%option noyywrap

%{
#include<bits/stdc++.h>

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

#define YYSTYPE SymbolInfo*

#include "y.tab.h"

extern YYSTYPE yylval;
extern SymbolTable *table;
void yyerror(char *);

int line_count=1;
int error=0;

%}


WS [ \t]+
DIGIT [0-9]
NUMBER [-]?{DIGIT}+(\.{DIGIT}+)?
LETTER [A-Za-z]
ID (_|{LETTER})(_|{LETTER}|{DIGIT})*

%%

{NUMBER}  {
	SymbolInfo *s= new  SymbolInfo(yytext,"CONST_FLOAT");
	yylval = (YYSTYPE)s;
	return NUMBER;
	  }

"+"       { 
	SymbolInfo *s= new  SymbolInfo(yytext, "PLUS");
	yylval = (YYSTYPE)s;
	return PLUS; 
	}
"-"       { return MINUS; }
"/"       { return SLASH; }
"*"       { return ASTERISK; }
"("       { return LPAREN; }
")"       { return RPAREN; }
"\n"      { return NEWLINE; }
{ID} 		{	 
				
				SymbolInfo *s= table->lookup(yytext);
				if(s==NULL)
				{					
					s= new SymbolInfo(yytext,"ID");
				}
				yylval = (YYSTYPE)s;
							
				return ID;
			}
{WS} { /* No action and no return */}
