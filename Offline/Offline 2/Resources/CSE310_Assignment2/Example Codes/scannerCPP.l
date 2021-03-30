%option noyywrap

%{
// #include<stdio.h>
// #include<stdlib.h>

#include <iostream>
#include <fstream>
using namespace std;

int line_count=1;

ofstream logout;
ofstream tokenout;

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE \n

%%

{NEWLINE} {line_count++;}

"if" {
		tokenout<<"<IF>";
		logout<<"Line no"<< line_count <<": TOKEN <IF> Lexeme"<<yytext<<" found\n";
	 } 
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
