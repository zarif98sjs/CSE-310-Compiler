/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_DEMO_TAB_H_INCLUDED
# define YY_YY_DEMO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "demo.y" /* yacc.c:1909  */

    #include <bits/stdc++.h>

#line 48 "demo.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    CHAR = 264,
    DOUBLE = 265,
    RETURN = 266,
    SWITCH = 267,
    CASE = 268,
    DEFAULT = 269,
    CONTINUE = 270,
    PRINTLN = 271,
    INCOP = 272,
    DECOP = 273,
    ASSIGNOP = 274,
    NOT = 275,
    LPAREN = 276,
    RPAREN = 277,
    LCURL = 278,
    RCURL = 279,
    LTHIRD = 280,
    RTHIRD = 281,
    COMMA = 282,
    SEMICOLON = 283,
    ID = 284,
    INT = 285,
    FLOAT = 286,
    VOID = 287,
    ADDOP = 288,
    MULOP = 289,
    RELOP = 290,
    LOGICOP = 291,
    CONST_INT = 292,
    CONST_FLOAT = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "demo.y" /* yacc.c:1909  */

    SymbolInfo* symbol_info;
    SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    // int ival;
    // double dval;

#line 108 "demo.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DEMO_TAB_H_INCLUDED  */