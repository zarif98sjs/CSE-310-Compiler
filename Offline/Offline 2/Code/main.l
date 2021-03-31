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

using namespace std;

int line_count = 1;
int nl_inside = 0;

ofstream logout;
ofstream tokenout;

string res;
string res_plain;

string comment;

char res_ch;

string CAP(string s)
{
	for(auto &ch:s) ch = toupper(ch);
	return s;
}

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
SymbolTable sym_tab(bucket_size,hashF);

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE \n
ALNUM [A-Za-z_0-9]
ALL_EXCEPT_BACKSLASH [^\\]

%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

if|else|for|while|do|break|int|char|float|double|void|return|switch|case|default|continue	{
				tokenout<<"<"<<CAP(yytext)<<">";
				logout<<"Line no "<< line_count <<": Token " <<"<"<<CAP(yytext)<< ">"<<" Lexeme "<<yytext<<" found\n"<<endl;
	 		}

{DIGIT}+	{
				tokenout<<"<CONST_INT,"<<yytext<<">";
				logout<<"Line no "<< line_count <<": Token " <<"<CONST_INT>"<<" Lexeme "<<yytext<<" found\n"<<endl;
			
				if(sym_tab.insert_symbol(SymbolInfo(yytext,"CONST_INT"),logout))
				{
					sym_tab.print_all_scope(logout);
				}

			}

{DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?	{
				tokenout<<"<CONST_FLOAT,"<<yytext<<">";
				logout<<"Line no "<< line_count <<": Token " <<"<CONST_FLOAT>"<<" Lexeme "<<yytext<<" found\n"<<endl;
			
				if(sym_tab.insert_symbol(SymbolInfo(yytext,"CONST_FLOAT"),logout))
				{
					sym_tab.print_all_scope(logout);
				}
			}

{LETTER}{ALNUM}*	{
		tokenout<<"<ID,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<ID>"<<" Lexeme "<<yytext<<" found\n"<<endl;
		
		if(sym_tab.insert_symbol(SymbolInfo(yytext,"ID"),logout))
		{
			sym_tab.print_all_scope(logout);
		}
}

"+"|"-"	{
		tokenout<<"<ADDOP,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<ADDOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"*"|"/"|"%"	{
		tokenout<<"<MULOP,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<MULOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"++"|"--"	{
		tokenout<<"<INCOP,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<INCOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"<"|"<="|">"|">="|"=="|"!="	{
		tokenout<<"<RELOP,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<RELOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"="	{
		tokenout<<"<ASSIGNOP,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<ASSIGNOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"&&"|"||"	{
		tokenout<<"<LOGICOP,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<LOGICOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"!"	{
		tokenout<<"<NOT,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<NOT>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"("	{
		tokenout<<"<LPAREN,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<LPAREN>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

")"	{
		tokenout<<"<RPAREN,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<RPAREN>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"{"	{
		tokenout<<"<LCURL,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<LCURL>"<<" Lexeme "<<yytext<<" found\n"<<endl;

		sym_tab.enter_scope();
}

"}"	{
		tokenout<<"<RCURL,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<RCURL>"<<" Lexeme "<<yytext<<" found\n"<<endl;

		sym_tab.exit_scope();
}

"["	{
		tokenout<<"<LTHIRD,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<LTHIRD>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

"]"	{
		tokenout<<"<RTHIRD,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<RTHIRD>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

","	{
		tokenout<<"<COMMA,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<COMMA>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

";"	{
		tokenout<<"<SEMICOLON,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": Token " <<"<SEMICOLON>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}

\'	{
	BEGIN CHAR_STATE;
	// logout<<"CHAR_STATE started"<<endl;
}


\"	{
	res.clear();
	res_plain.clear();

	nl_inside = 0;

	BEGIN STR_STATE;
	// logout<<"STR_STATE started"<<endl;
}	

\/\/	{
	comment.clear();
	comment += "//";

	nl_inside = 0;

	BEGIN S_COMMENT_STATE;
	// logout<<"S_COMMENT_STATE started"<<endl;
}	

\/\*\*	{
	comment.clear();
	comment += "/**";

	nl_inside = 0;

	BEGIN D_COMMENT_STATE;
	// logout<<"D_COMMENT_STATE started"<<endl;
}	

<CHAR_STATE>\\\'\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\'';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\\\\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\\';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\n\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\n';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\t\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\t';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}


<CHAR_STATE>\\a\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\a';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\f\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\f';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\r\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\r';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}


<CHAR_STATE>\\b\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\b';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\v\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\v';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\0\' {

	string for_print(yytext); for_print = "'"+for_print;
	res_ch = '\0';

	tokenout<<"<CHAR_CONST,"<<res_ch<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<res_ch<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	
	BEGIN INITIAL;
}

<CHAR_STATE>\\\' {
	logout<<"ERROR single case"<<yytext<<endl;
	BEGIN INITIAL;
}

<CHAR_STATE>(.\') {

	string for_print(yytext); for_print = "'"+for_print;

	yytext[strlen(yytext)-1] = 0; 

	tokenout<<"<CHAR_CONST,"<<yytext<<">";
	logout<<"Line no "<< line_count <<": Token " <<"<CONST_CHAR>"<<" Lexeme "<<for_print<<" found --> <CHAR_CONST,"<<yytext<<">\n"<<endl;

	if(sym_tab.insert_symbol(SymbolInfo(for_print,"CONST_CHAR"),logout))
	{
		sym_tab.print_all_scope(logout);
	}
	BEGIN INITIAL;
}


<CHAR_STATE>..+\' {
	logout<<"ERROR LONG CHAR "<<yytext<<endl;
	BEGIN INITIAL;
}

<CHAR_STATE>\n {
	logout<<"ERROR QUOTE NOT END "<<yytext<<endl;
	line_count++;
	BEGIN INITIAL;
}

<CHAR_STATE><<EOF>> {
	logout<<"ERROR QUOTE NOT END "<<yytext<<endl;
	BEGIN INITIAL;
}


<STR_STATE>\\a			res += "\a", res_plain +="\\a";
<STR_STATE>\\b          res += "\b", res_plain +="\\b";
<STR_STATE>\\f          res += "\f", res_plain +="\\f";
<STR_STATE>\\n          res += "\n", res_plain +="\\n";
<STR_STATE>\\r          res += "\r", res_plain +="\\r";
<STR_STATE>\\t          res += "\t", res_plain +="\\t";
<STR_STATE>\\v          res += "\v", res_plain +="\\v";
<STR_STATE>\\\\         res += "\\", res_plain +="\\\\";
<STR_STATE>\\\"         res += "\"", res_plain +="\\\"";
<STR_STATE>\\\n         { 
	nl_inside++;
	res_plain += "\\\n" ;
	// logout<<"OK ESCAPE"<<endl; 
	}
<STR_STATE>\n         	{ 
		nl_inside++;
		logout<<"Not Finished ERROR"<<endl;

		line_count += nl_inside;
		nl_inside = 0;

		BEGIN(INITIAL);
	}
<STR_STATE><<EOF>>      { 
		logout<<"Not Finished ERROR"<<endl;

		line_count += nl_inside;
		nl_inside = 0;
		 
		BEGIN(INITIAL);
	}

<STR_STATE>\"           {
							string for_print = "\"";
							for_print += res_plain;
							for_print += "\"";

                         	logout<<"Line no "<< line_count <<": Token " <<"<STRING>"<<" Lexeme "<<for_print<<" found --> <STRING,\""<<res<<"\">\n"<<endl;
                         	
							line_count += nl_inside;
							nl_inside = 0;
							 
							BEGIN(INITIAL);
                     	}

<STR_STATE>.            {res += yytext[0]; res_plain+= yytext[0];}



<S_COMMENT_STATE>\\\n         { 
	nl_inside++;
	logout<<"OK ESCAPE SINGLE COMMENT"<<endl; 
	}
<S_COMMENT_STATE>\n           { 
		
		// logout<<"SINGLE COMMENT FINISHED "<<comment<<endl; 
		nl_inside++;
		logout<<"Line no "<< line_count <<": Token " <<"<COMMENT>"<<" Lexeme "<<comment<<" found\n"<<endl;
		
		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}
<S_COMMENT_STATE><<EOF>>      { 

		// logout<<"SINGLE COMMENT FINISHED "<<comment<<endl; 
		logout<<"Line no "<< line_count <<": Token " <<"<COMMENT>"<<" Lexeme "<<comment<<" found\n"<<endl;

		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}

<S_COMMENT_STATE>\\           { comment += "\\";}
<S_COMMENT_STATE>.            { comment += yytext[0];} 



<D_COMMENT_STATE>\*\*\/       { 
		//logout<<"DOUBLE COMMENT FINISHED "<<comment<<endl; 
		comment += "**/";
		logout<<"Line no "<< line_count <<": Token " <<"<COMMENT>"<<" Lexeme "<<comment<<" found\n"<<endl;
		
		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}
<D_COMMENT_STATE><<EOF>>       { 
		logout<<"DOUBLE COMMENT NOT FINISHED ERROR"<<comment<<endl; 
		
		line_count += nl_inside;
		nl_inside = 0;
		
		BEGIN(INITIAL);
	}

<D_COMMENT_STATE>\n            { nl_inside++; comment += "\n";} 
<D_COMMENT_STATE>.            { comment += yytext[0];} 

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

	tokenout.open("token.txt");
	logout.open("log.txt");

	yyin= fin;
	yylex();
	fclose(yyin);

	sym_tab.print_all_scope(logout);

	logout<<"Total lines: "<<line_count<<endl;

	tokenout.close();
	logout.close();


	return 0;
}
