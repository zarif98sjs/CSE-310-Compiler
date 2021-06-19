%option noyywrap

%x CHAR_STATE
%x STR_STATE
%x S_COMMENT_STATE
%x D_COMMENT_STATE

%{
#include<bits/stdc++.h>

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "Helper.h"

// #define YYSTYPE SymbolInfo*

#include "y.tab.h"

string res;
string res_plain;

string ans_char;
string ans_char_plain;

string comment;

char res_ch;

//////////////////////

extern YYSTYPE yylval;
extern SymbolTable *sym_tab;
void yyerror(char *);

extern ofstream logout;
extern ofstream errout;
extern int err_count;

int line_count = 1;
int error_count = 0;
int nl_inside = 0;

string cur_type;

void error_unrecognized(string s)
{
	logout<<"Error at line "<<line_count<<": "<<"Unrecognized character "<<s<<"\n"<<endl;
	errout<<"Error at line "<<line_count<<": "<<"Unrecognized character "<<s<<"\n"<<endl;
	err_count++;
}

void error_decimal_point(string s)
{
	logout<<"Error at line "<<line_count<<": "<<"Too many decimal points "<<s<<"\n"<<endl;
	errout<<"Error at line "<<line_count<<": "<<"Too many decimal points "<<s<<"\n"<<endl;
	err_count++;
}

void error_ill_formed(string s)
{
	logout<<"Error at line "<<line_count<<": "<<"Ill formed number "<<s<<"\n"<<endl;
	errout<<"Error at line "<<line_count<<": "<<"Ill formed number "<<s<<"\n"<<endl;
	err_count++;
}

void error_id(string s)
{
	logout<<"Error at line "<<line_count<<": "<<"Invalid prefix on ID or invalid suffix on Number "<<s<<"\n"<<endl;
	errout<<"Error at line "<<line_count<<": "<<"Invalid prefix on ID or invalid suffix on Number "<<s<<"\n"<<endl;
	err_count++;
}

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
"int" { SymbolInfo *s= new  SymbolInfo(yytext, "INT"); yylval.symbol_info = s; return INT;}
"char" {return CHAR;}
"float" { SymbolInfo *s= new  SymbolInfo(yytext, "FLOAT"); yylval.symbol_info = s; return FLOAT;} 
"double" {return DOUBLE;}
"void" { SymbolInfo *s= new  SymbolInfo(yytext, "VOID"); yylval.symbol_info = s; return VOID;}
"return" {return RETURN;}
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}
"continue" {return CONTINUE;}
"printf"	{return PRINTLN;}

{LETTER}{ALNUM}*	{
		SymbolInfo *s= new  SymbolInfo(yytext, "ID");
		yylval.symbol_info = s;
		return ID;
}

{DIGIT}+	{
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_INT");
				yylval.symbol_info = s;
				return CONST_INT;
			}

{DIGIT}+(\.{DIGIT}+)?([Ee][+-]?{DIGIT}+)?	{
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_FLOAT");
				yylval.symbol_info = s;
				return CONST_FLOAT;
			}

{DIGIT}*(\.{DIGIT}+)\.[0-9\.Ee+-]*(\.)* {
	error_decimal_point(yytext);

	SymbolInfo *s= new  SymbolInfo(yytext, "ERROR_FLOAT");
	yylval.symbol_info = s;
	return ERROR_FLOAT;
}

([0-9]*(\.[0-9]*)?[Ee][+-]?[0-9]*[0-9\.Ee+-]*(\.)*)|([0-9]+\.) {

	error_ill_formed(yytext);

	SymbolInfo *s= new  SymbolInfo(yytext, "ERROR_FLOAT");
	yylval.symbol_info = s;
	return ERROR_FLOAT;
}



{DIGIT}*(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?{LETTER}{ALNUM}* {
	
	error_id(yytext);

	SymbolInfo *s= new  SymbolInfo(yytext, "ID");
	yylval.symbol_info = s;
	return ID;
}

"+"|"-" { SymbolInfo *s= new  SymbolInfo(yytext, "ADDOP"); yylval.symbol_info = s; return ADDOP;}
"*"|"/"|"%"	{ SymbolInfo *s= new  SymbolInfo(yytext, "MULOP"); yylval.symbol_info = s; return MULOP;}
"++"	{return INCOP;}
"--"	{return DECOP;}

"<"|"<="|">"|">="|"=="|"!="	{ SymbolInfo *s= new  SymbolInfo(yytext, "RELOP"); yylval.symbol_info = s; return RELOP;}
"="	{return ASSIGNOP;}
"&&"|"||"	{ SymbolInfo *s= new  SymbolInfo(yytext, "LOGICOP"); yylval.symbol_info = s; return LOGICOP;}
"!"	{return NOT;}

"("	{return LPAREN;}
")"	{return RPAREN;}
"{"	{return LCURL;}
"}"	{return RCURL;}
"["	{return LTHIRD;}
"]" {return RTHIRD;}

","	{return COMMA;}
";"	{return SEMICOLON;}

\'	{
	ans_char.clear();
	ans_char_plain.clear();
	BEGIN CHAR_STATE;
	// logout<<"CHAR_STATE started"<<endl;
}


\"	{
	res.clear();
	res_plain.clear();

	nl_inside = 0;

	BEGIN STR_STATE;
}	

\/\/	{
	comment.clear();
	comment += "//";

	nl_inside = 0;

	BEGIN S_COMMENT_STATE;
}	

\/\*	{
	comment.clear();
	comment += "/*";

	nl_inside = 0;

	BEGIN D_COMMENT_STATE;
}	

<CHAR_STATE>\\\\         ans_char += "\\", ans_char_plain +="\\\\";
<CHAR_STATE>\\\'         ans_char += "\'", ans_char_plain +="\\\'";
<CHAR_STATE>\\\"         ans_char += "\"", ans_char_plain +="\\\"";
<CHAR_STATE>\\a			 ans_char += "\a", ans_char_plain +="\\a";
<CHAR_STATE>\\b          ans_char += "\b", ans_char_plain +="\\b";
<CHAR_STATE>\\f          ans_char += "\f", ans_char_plain +="\\f";
<CHAR_STATE>\\n          ans_char += "\n", ans_char_plain +="\\n";
<CHAR_STATE>\\r          ans_char += "\r", ans_char_plain +="\\r";
<CHAR_STATE>\\t          ans_char += "\t", ans_char_plain +="\\t";
<CHAR_STATE>\\v          ans_char += "\v", ans_char_plain +="\\v";
<CHAR_STATE>\\0			 ans_char += "\0", ans_char_plain +="\\0";


<CHAR_STATE><<EOF>> {
	string for_print = "'"; 
	for_print += ans_char_plain;

	error_count++;

	BEGIN INITIAL;
}

<CHAR_STATE>\'	{

	string for_print = "'"; 
	for_print += ans_char_plain;
	for_print += "'";

	if((int)ans_char.size()==0)
	{
		if(ans_char_plain=="\\0")
		{

		}
		else
		{
			error_count++;
		}
	}
	else if((int)ans_char.size()==1)
	{

	}
	else
	{
			error_count++;
			BEGIN INITIAL;
	}

	BEGIN INITIAL;
}

<CHAR_STATE>[\r]?\n {

	string for_print = "'"; 
	for_print += ans_char_plain;

	error_count++;

	line_count++;
	BEGIN INITIAL;
}

<CHAR_STATE>.		ans_char += yytext[0] , ans_char_plain += yytext[0];


<STR_STATE>\\\\         res += "\\", res_plain +="\\\\";
<STR_STATE>\\\'         res += "\'", res_plain +="\\\'";
<STR_STATE>\\\"         res += "\"", res_plain +="\\\"";
<STR_STATE>\\a			res += "\a", res_plain +="\\a";
<STR_STATE>\\b          res += "\b", res_plain +="\\b";
<STR_STATE>\\f          res += "\f", res_plain +="\\f";
<STR_STATE>\\n          res += "\n", res_plain +="\\n";
<STR_STATE>\\r          res += "\r", res_plain +="\\r";
<STR_STATE>\\t          res += "\t", res_plain +="\\t";
<STR_STATE>\\v          res += "\v", res_plain +="\\v";
<STR_STATE>\\0         	res += "\0", res_plain +="\\0";

<STR_STATE>\\\r\n         { 
	nl_inside++;
	res_plain += "\\\r\n" ;
	}
<STR_STATE>\\\n         { 
	nl_inside++;
	res_plain += "\\\n" ;
	}
<STR_STATE>[\r]?\n { 
		nl_inside++;
		error_count++;

		line_count += nl_inside;
		nl_inside = 0;

		BEGIN(INITIAL);
	}
<STR_STATE><<EOF>>      { 
		error_count++;

		line_count += nl_inside;
		nl_inside = 0;
		 
		BEGIN(INITIAL);
	}

<STR_STATE>\"           {
							string for_print = "\"";
							for_print += res_plain;
							for_print += "\"";
							
                         	
							line_count += nl_inside;
							nl_inside = 0;
							 
							BEGIN(INITIAL);
                     	}

<STR_STATE>.            {res += yytext[0]; res_plain+= yytext[0];}

<S_COMMENT_STATE>\\\r\n         { 
	nl_inside++;
	comment += "\\\r\n";
	}

<S_COMMENT_STATE>\\\n         { 
	nl_inside++;
	comment += "\\\n";
	}

<S_COMMENT_STATE>[\r]?\n           { 
		
		nl_inside++;
		
		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}
<S_COMMENT_STATE><<EOF>>      { 

		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}

<S_COMMENT_STATE>\\           { comment += "\\";}
<S_COMMENT_STATE>.            { comment += yytext[0];} 


<D_COMMENT_STATE>\*\/       { 
		comment += "*/";
		
		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}

<D_COMMENT_STATE><<EOF>>       { 

		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}

<D_COMMENT_STATE>\r            { comment += "\r";} 
<D_COMMENT_STATE>\n            { nl_inside++; comment += "\n";} 
<D_COMMENT_STATE>.            { comment += yytext[0];} 

. {
	error_unrecognized(yytext);
}


%%