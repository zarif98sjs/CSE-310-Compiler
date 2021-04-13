/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "demo.y" /* yacc.c:339  */

#include<bits/stdc++.h>
#include <typeinfo>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

// #define YYSTYPE SymbolInfo*

extern FILE *yyin;

void yyerror(char *s){
	printf("%s\n",s);
}

int yyparse(void);
int yylex(void);

extern int line_count;


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


#line 104 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 1 "demo.y" /* yacc.c:355  */

    #include <bits/stdc++.h>

#line 138 "y.tab.c" /* yacc.c:355  */

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
#line 44 "demo.y" /* yacc.c:355  */

    SymbolInfo* symbol_info;
    SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    int ival;
    double dval;

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    72,    80,    86,    87,    88,    91,   105,
     120,   134,   140,   153,   154,   162,   166,   176,   181,   194,
     195,   196,   199,   209,   223,   227,   240,   245,   250,   253,
     256,   259,   262,   265,   268,   271,   274,   286,   287,   290,
     296,   308,   309,   314,   315,   318,   323,   326,   331,   341,
     346,   352,   353,   354,   361,   367,   370,   373,   376,   379,
     382,   387,   388,   391,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "CHAR", "DOUBLE", "RETURN", "SWITCH", "CASE", "DEFAULT",
  "CONTINUE", "PRINTLN", "INCOP", "DECOP", "RELOP", "ASSIGNOP", "LOGICOP",
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "ID", "INT", "FLOAT", "VOID", "ADDOP", "MULOP", "CONST_INT",
  "CONST_FLOAT", "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,   -69,   -69,   -69,    15,    32,   -69,   -69,   -69,   -69,
      12,   -69,   -69,    14,    50,   -12,    17,    28,   -69,   -11,
       1,    30,    39,    29,    52,   -69,   -69,     2,    32,   -69,
     -69,    34,     5,    53,    58,   146,    65,   146,   146,   -69,
     -69,    25,   146,   -69,   -69,   -69,   -69,    61,    88,   -69,
     -69,    33,    66,   -69,    74,    -9,    62,   -69,   -69,   -69,
     -69,    69,    73,   146,   141,   146,    67,    71,     0,   -69,
      79,   146,   146,   -69,    78,   -69,   -69,   -69,   -69,   146,
     -69,   146,   146,   146,   146,   -69,   -69,    82,   141,    83,
     -69,    84,   -69,   -69,    85,    86,    89,   -69,   -69,    77,
      62,   -69,   124,   146,   124,    94,   -69,   146,   -69,   112,
     104,   -69,   -69,   -69,   124,   124,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    20,    21,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    24,     0,     0,     0,     0,    18,     0,
       0,    15,     0,    22,     0,     9,    11,     0,     0,    14,
      25,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      37,    39,     0,    57,    58,    30,    28,     0,     0,    26,
      29,    54,     0,    41,    43,    45,    47,    49,    53,     8,
      10,    13,     0,     0,     0,     0,     0,     0,    54,    52,
       0,    62,     0,    51,    24,    16,    27,    59,    60,     0,
      38,     0,     0,     0,     0,    12,    23,     0,     0,     0,
      36,     0,    56,    64,     0,    61,     0,    42,    44,    46,
      48,    50,     0,     0,     0,     0,    55,     0,    40,    32,
       0,    34,    35,    63,     0,     0,    33,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,   126,   -69,   -69,   -69,    -3,    35,     8,
     -69,   -69,   -42,   -55,   -37,   -34,   -68,    51,    54,    55,
     -35,   -69,   -69,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    45,    46,    47,
      14,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    94,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    66,    69,    93,    70,    68,    76,    73,    10,    88,
      82,    97,    19,    10,    24,    11,    26,    77,    78,    25,
       1,     2,     3,    21,    60,    27,    83,    24,    63,    87,
      28,    89,    59,   103,    68,     9,    61,    15,    96,   113,
       9,    16,    68,    13,    68,    68,    68,    68,    71,   101,
      77,    78,    72,    79,    22,    32,    31,    33,    34,    23,
     109,    29,   111,    35,     1,     2,     3,    30,    36,   110,
      68,    62,   116,   117,    37,    38,    64,    24,    39,    17,
      18,    65,    40,    41,     1,     2,     3,    42,    67,    43,
      44,    32,    74,    33,    34,    81,    80,    90,    84,    35,
      85,    86,    91,    92,    36,    16,   102,   104,   105,   106,
      37,    38,    83,    24,    75,   107,   114,   108,    40,    41,
       1,     2,     3,    42,   112,    43,    44,    32,   115,    33,
      34,    12,    98,     0,     0,    35,    99,     0,   100,     0,
      36,     0,     0,     0,     0,     0,    37,    38,     0,    24,
       0,     0,     0,     0,    40,    41,     1,     2,     3,    42,
       0,    43,    44,    37,    38,     0,     0,     0,    37,    38,
       0,    40,    41,     0,     0,     0,    42,    41,    43,    44,
       0,    42,     0,    43,    44
};

static const yytype_int8 yycheck[] =
{
      37,    35,    37,    71,    38,    42,    48,    42,     0,    64,
      19,    79,    24,     5,    25,     0,    19,    17,    18,    30,
      32,    33,    34,    15,    27,    24,    35,    25,    23,    63,
      29,    65,    30,    88,    71,     0,    28,    23,    72,   107,
       5,    27,    79,    31,    81,    82,    83,    84,    23,    84,
      17,    18,    27,    20,    37,     3,    27,     5,     6,    31,
     102,    31,   104,    11,    32,    33,    34,    28,    16,   103,
     107,    37,   114,   115,    22,    23,    23,    25,    26,    29,
      30,    23,    30,    31,    32,    33,    34,    35,    23,    37,
      38,     3,    31,     5,     6,    21,    30,    30,    36,    11,
      31,    28,    31,    24,    16,    27,    24,    24,    24,    24,
      22,    23,    35,    25,    26,    29,     4,    28,    30,    31,
      32,    33,    34,    35,    30,    37,    38,     3,    24,     5,
       6,     5,    81,    -1,    -1,    11,    82,    -1,    83,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,    37,    38,    22,    23,    -1,    -1,    -1,    22,    23,
      -1,    30,    31,    -1,    -1,    -1,    35,    31,    37,    38,
      -1,    35,    -1,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    34,    40,    41,    42,    43,    44,    47,
      48,     0,    42,    31,    49,    23,    27,    29,    30,    24,
      45,    48,    37,    31,    25,    30,    46,    24,    29,    31,
      28,    27,     3,     5,     6,    11,    16,    22,    23,    26,
      30,    31,    35,    37,    38,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    30,
      46,    48,    37,    23,    23,    23,    54,    23,    53,    59,
      54,    23,    27,    59,    31,    26,    51,    17,    18,    20,
      30,    21,    19,    35,    36,    31,    28,    54,    52,    54,
      30,    31,    24,    55,    61,    62,    54,    55,    56,    57,
      58,    59,    24,    52,    24,    24,    24,    29,    28,    51,
      54,    51,    30,    55,     4,    24,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      44,    44,    45,    45,    45,    45,    46,    46,    47,    48,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     1,
       1,     7,     5,     7,     5,     5,     3,     1,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "demo.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
	}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" program : program unit\n"<<endl; 
            
            *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "\n";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" program : unit\n"<<endl; 
            cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; 
        }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : var_declaration\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : func_declaration\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : func_definition\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 91 "demo.y" /* yacc.c:1646  */
    { 
                
                cout<<"At line no: "<<line_count<<" func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"<<endl; 
                
                // *$$ = *$1;
                // *$$ += " ";
                // *$$ += $2->key;
                // *$$ += "(";
                // *$$ += ")";
                // *$$ += ";";

                // cout<<*$$<<"\n"<<endl;
    
    }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n"<<endl; 
                
                *(yyval. temp_str ) = *(yyvsp[-4]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[-3].symbol_info)->key;
                *(yyval. temp_str ) += "(";
                *(yyval. temp_str ) += ")";
                *(yyval. temp_str ) += ";";

                cout<<*(yyval. temp_str )<<"\n"<<endl;

            }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<<endl;  
            
                *(yyval. temp_str ) = *(yyvsp[-5]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[-4].symbol_info)->key;
                *(yyval. temp_str ) += "(";
                *(yyval. temp_str ) += *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += ")";
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

                cout<<*(yyval. temp_str )<<"\n"<<endl;

            }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement\n"<<endl;  
            }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "demo.y" /* yacc.c:1646  */
    {

                cout<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier ID\n"<<endl;  

                *(yyval. temp_str ) = *(yyvsp[-3]. temp_str );
                *(yyval. temp_str ) += ",";
                *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[0].symbol_info)->key;

                cout<<*(yyval. temp_str )<<"\n"<<endl;

            }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" parameter_list : type_specifier ID\n"<<endl;  
                *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[0].symbol_info)->key;

                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 166 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" compound_statement : LCURL statements RCUR\n"<<endl;
                
                string temp = *(yyvsp[-1]. temp_str );

                *(yyval. temp_str ) = "{\n"; 
                *(yyval. temp_str ) += temp; 
                *(yyval. temp_str ) += "\n}"; 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" LCURL RCURL\n"<<endl; 
             }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 181 "demo.y" /* yacc.c:1646  */
    { 

            cout<<"At line no: "<<line_count<<" var_declaration --> type_specifier declaration_list SEMICOLON\n"<<endl; 

            *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += " ";
            *(yyval. temp_str ) += *(yyvsp[-1]. symbol_info_str );
            *(yyval. temp_str ) += ";";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 194 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : INT\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key; }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : FLOAT\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 196 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : VOID\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 199 "demo.y" /* yacc.c:1646  */
    { 
                    cout<<"At line no: "<<line_count<<" declaration_list COMMA ID\n"<<endl; 
                    
                    *(yyvsp[-2]. symbol_info_str ) += ",";
                    *(yyvsp[-2]. symbol_info_str ) += (yyvsp[0].symbol_info)->key;

                    cout<< *(yyvsp[-2]. symbol_info_str ) <<"\n"<<endl;

                    (yyval. symbol_info_str ) = (yyvsp[-2]. symbol_info_str );
                }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "demo.y" /* yacc.c:1646  */
    {
               cout<<"At line no: "<<line_count<<" declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n"<<endl; 
           
                *(yyvsp[-5]. symbol_info_str ) += ",";
                *(yyvsp[-5]. symbol_info_str ) += (yyvsp[-3].symbol_info)->key;
                *(yyvsp[-5]. symbol_info_str ) += "[";
                *(yyvsp[-5]. symbol_info_str ) += to_string((yyvsp[-1].ival));
                *(yyvsp[-5]. symbol_info_str ) += "]";

                cout<< *(yyvsp[-5]. symbol_info_str ) <<"\n"<<endl;

                (yyval. symbol_info_str ) = (yyvsp[-5]. symbol_info_str );
           
           }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 223 "demo.y" /* yacc.c:1646  */
    { 
               cout<<"At line no: "<<line_count<<" declaration_list : ID\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl;
                *(yyval. symbol_info_str ) = (yyvsp[0].symbol_info)->key;
               }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 228 "demo.y" /* yacc.c:1646  */
    {
               cout<<"At line no: "<<line_count<<" declaration_list : ID LTHIRD CONST_INT RTHIRD\n"<<endl;
           
                *(yyval. symbol_info_str ) = (yyvsp[-3].symbol_info)->key;
                *(yyval. symbol_info_str ) += "[";
                *(yyval. symbol_info_str ) += to_string((yyvsp[-1].ival));
                *(yyval. symbol_info_str ) += "]";

                cout<< *(yyval. symbol_info_str ) <<"\n"<<endl;
           }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 240 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statements : statement\n"<<endl;
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 245 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statements : statements statement\n"<<endl; 
        }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 250 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : var_declaration\n"<<endl; 
        }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 253 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : expression_statement\n"<<endl; 
        }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 256 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : compound_statement\n"<<endl; 
        }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 259 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<<endl; 
        }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 262 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement\n"<<endl; 
        }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 265 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement ELSE statemen\n"<<endl; 
        }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 268 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : WHILE LPAREN expression RPAREN statement\n"<<endl; 
        }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 271 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<<endl; 
        }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 274 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : RETURN expression SEMICOLON\n"<<endl; 
        
            *(yyval. temp_str ) = "return";
            *(yyval. temp_str ) += " ";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += ";";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 290 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" variable : ID\n"<<endl; 
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 296 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" variable : ID LTHIRD expression RTHIRD\n"<<endl; 
            cout<<"HEREEEE"<<endl;
            // *$$ = $1->key;
            // *$$ += "[";
            // *$$ += *$3;
            // *$$ += "]";

            // cout<<*$$<<"\n"<<endl;
         }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 318 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression\n"<<endl;
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                 cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 326 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" simple_expression : term\n"<<endl;
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 331 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
               *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
               *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
               *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

               cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 341 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" term : unary_expression\n"<<endl;
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 346 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" term : term MULOP unary_expressio\n"<<endl;
            // cout<<*$$<<"\n"<<endl;
        }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 354 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" unary_expression : factor\n"<<endl;
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 361 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable\n"<<endl;
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;

        }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 367 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : ID LPAREN argument_list RPAREN\n"<<endl; 
        }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 370 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : LPAREN expression RPAREN\n"<<endl; 
        }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 373 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" factor : CONST_INT\n"<<endl; 
        }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 376 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" factor : CONST_FLOAT\n"<<endl; 
        }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 379 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable INCOP\n"<<endl; 
        }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 382 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable DECOP\n"<<endl; 
        }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1924 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 395 "demo.y" /* yacc.c:1906  */


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
