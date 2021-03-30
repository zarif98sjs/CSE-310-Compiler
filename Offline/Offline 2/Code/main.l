%option noyywrap

%x CHAR_STATE
%x STR_STATE

%{

#include <iostream>
#include <fstream>
using namespace std;

int line_count=1;

ofstream logout;
ofstream tokenout;

string res;

string CAP(string s)
{
	for(auto &ch:s) ch = toupper(ch);
	return s;
}

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE \n
ALNUM [A-Za-z_0-9]
ALL_EXCEPT_BACKSLASH [^\\]

%%

{NEWLINE} {line_count++;}

if|else|for|while|do|break|int|char|float|double|void|return|switch|case|default|continue	{
				tokenout<<"<"<<CAP(yytext)<<">";
				logout<<"Line no "<< line_count <<": TOKEN " <<"<"<<CAP(yytext)<< ">"<<" Lexeme "<<yytext<<" found\n";
	 		}

{DIGIT}+	{
				tokenout<<"<CONST_INT,"<<yytext<<">";
				logout<<"Line no "<< line_count <<": TOKEN " <<"<CONST_INT>"<<" Lexeme "<<yytext<<" found\n";
			}

{DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?	{
				tokenout<<"<CONST_FLOAT,"<<yytext<<">";
				logout<<"Line no "<< line_count <<": TOKEN " <<"<CONST_FLOAT>"<<" Lexeme "<<yytext<<" found\n";
			}

{LETTER}{ALNUM}*	{
		tokenout<<"<ID,"<<yytext<<">";
		logout<<"Line no "<< line_count <<": TOKEN " <<"<ID>"<<" Lexeme "<<yytext<<" found\n";
}

\'	{
	BEGIN CHAR_STATE;
	logout<<"CHAR_STATE started"<<endl;
}


\"	{
	res.clear();
	BEGIN STR_STATE;
	logout<<"STR_STATE started"<<endl;
}	


<CHAR_STATE>\\\'\'|\\\\\'|\\n\'|\\t\'|\\a\'|\\f\'|\\r\'|\\b\'|\\v\'|\\0\' {
	yytext[strlen(yytext)-1] = 0; 
	logout<<yytext<<endl;
	logout<<"CHAR_STATE ended"<<endl;
	BEGIN INITIAL;
}

<CHAR_STATE>\\\' {
	logout<<"ERROR single case"<<yytext<<endl;
	BEGIN INITIAL;
}

<CHAR_STATE>(.\') {
	yytext[strlen(yytext)-1] = 0; 
	logout<<"OKAY "<<yytext<<endl;
	BEGIN INITIAL;
}


<CHAR_STATE>..+\' {
	logout<<"ERROR "<<yytext<<endl;
	BEGIN INITIAL;
}

<CHAR_STATE>.+ {
	logout<<"ERROR QUOTE NOT END "<<yytext<<endl;
	BEGIN INITIAL;
}


<STR_STATE>\\a          res += '\a';
<STR_STATE>\\b          res += '\b';
<STR_STATE>\\f          res += '\f';
<STR_STATE>\\n          res += '\n';
<STR_STATE>\\r          res += '\r';
<STR_STATE>\\t          res += '\t';
<STR_STATE>\\v          res += '\v';
<STR_STATE>\\\\         res += '\\';
<STR_STATE>\\\"         res += '\"';
<STR_STATE>\\\n         { logout<<"OK ESCAPE"<<endl; }
<STR_STATE>\n         	{ logout<<"Not Finished ERROR"<<endl; BEGIN(INITIAL);}

<STR_STATE>\"           {
                         logout<< "Found a string: " << res << endl;
                         BEGIN(INITIAL);
                     	}
<STR_STATE>.            {res += yytext[0];}

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

	tokenout.close();
	logout.close();

	return 0;
}
