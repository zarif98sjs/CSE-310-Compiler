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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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

#line 48 "y.tab.h" /* yacc.c:1909  */

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
    RELOP = 274,
    ASSIGNOP = 275,
    LOGICOP = 276,
    NOT = 277,
    LPAREN = 278,
    RPAREN = 279,
    LCURL = 280,
    RCURL = 281,
    LTHIRD = 282,
    RTHIRD = 283,
    COMMA = 284,
    SEMICOLON = 285,
    ID = 286,
    INT = 287,
    FLOAT = 288,
    VOID = 289,
    ADDOP = 290,
    MULOP = 291,
    CONST_INT = 292,
    CONST_FLOAT = 293
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define CHAR 264
#define DOUBLE 265
#define RETURN 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define CONTINUE 270
#define PRINTLN 271
#define INCOP 272
#define DECOP 273
#define RELOP 274
#define ASSIGNOP 275
#define LOGICOP 276
#define NOT 277
#define LPAREN 278
#define RPAREN 279
#define LCURL 280
#define RCURL 281
#define LTHIRD 282
#define RTHIRD 283
#define COMMA 284
#define SEMICOLON 285
#define ID 286
#define INT 287
#define FLOAT 288
#define VOID 289
#define ADDOP 290
#define MULOP 291
#define CONST_INT 292
#define CONST_FLOAT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "demo.y" /* yacc.c:1909  */

    SymbolInfo* symbol_info;
    SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    int ival;
    double dval;

#line 145 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
