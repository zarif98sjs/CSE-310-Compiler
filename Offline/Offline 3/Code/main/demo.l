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

int line_count = 1;
int error_count = 0;
int nl_inside = 0;

%}


WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z_]
DIGIT [0-9]
NEWLINE [\r]?\n
ALNUM [A-Za-z_0-9]
ALL_EXCEPT_BACKSLASH [^\\]

%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"do" {return DO;}
"break" {return BREAK;}
"int" {return INT;}
"char" {return CHAR;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"void" {return VOID;}
"return" {return RETURN;}
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}
"continue" {return CONTINUE;}
"println"	{return PRINTLN;}

{DIGIT}+	{
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_INT");
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}

{DIGIT}+(\.{DIGIT}+)?([Ee][+-]?{DIGIT}+)?	{
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_FLOAT");
				yylval = (YYSTYPE)s;
				return CONST_FLOAT;
			}

{DIGIT}*(\.{DIGIT}+)\.[0-9\.Ee+-]*(\.)* {
	error_count++;
	cout<<"Error at line no "<< line_count <<": Too many decimal points "<<yytext<<"\n"<<endl;
}

([0-9]*(\.[0-9]*)?[Ee][+-]?[0-9]*[0-9\.Ee+-]*(\.)*)|([0-9]+\.) {
	error_count++;
	cout<<"Error at line no "<< line_count <<": Ill formed number "<<yytext<<"\n"<<endl;
}

{LETTER}{ALNUM}*	{
		SymbolInfo *s= new  SymbolInfo(yytext, "ID");
		yylval = (YYSTYPE)s;
		return ID;
}

{DIGIT}*(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?{LETTER}{ALNUM}* {
	error_count++;
	cout<<"Error at line no "<< line_count <<": Invalid prefix on ID or invalid suffix on Number "<<yytext<<"\n"<<endl;
}

"+"|"-"	{return ADDOP;}
"*"|"/"|"%"	{return MULOP;}
"++"	{return INCOP;}
"--"	{return DECOP;}

"<"|"<="|">"|">="|"=="|"!="	{return RELOP;}
"="	{return ASSIGNOP;}
"&&"|"||"	{return LOGICOP;}
"!"	{return NOT;}

"("	{return LPAREN;}
")"	{return RPAREN;}
"{"	{return LCURL;}
"}"	{return RCURL;}
"["	{return LTHIRD;}
"]" {return RTHIRD;}

","	{return COMMA;}
";"	{return SEMICOLON;}

%%