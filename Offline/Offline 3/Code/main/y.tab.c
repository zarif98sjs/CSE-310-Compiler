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
#define ASSIGNOP 274
#define NOT 275
#define LPAREN 276
#define RPAREN 277
#define LCURL 278
#define RCURL 279
#define LTHIRD 280
#define RTHIRD 281
#define COMMA 282
#define SEMICOLON 283
#define ID 284
#define INT 285
#define FLOAT 286
#define VOID 287
#define ADDOP 288
#define MULOP 289
#define RELOP 290
#define LOGICOP 291
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
    // int ival;
    // double dval;

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
#define YYLAST   170

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
       0,    67,    67,    73,    82,    88,    89,    90,    93,   107,
     123,   138,   155,   169,   170,   180,   184,   194,   204,   218,
     219,   220,   223,   232,   246,   251,   265,   272,   284,   291,
     297,   300,   303,   307,   310,   313,   316,   329,   332,   342,
     348,   361,   367,   379,   385,   395,   401,   411,   417,   428,
     434,   444,   452,   456,   464,   471,   482,   492,   498,   504,
     507,   512,   519,   524,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "CHAR", "DOUBLE", "RETURN", "SWITCH", "CASE", "DEFAULT",
  "CONTINUE", "PRINTLN", "INCOP", "DECOP", "ASSIGNOP", "NOT", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON",
  "ID", "INT", "FLOAT", "VOID", "ADDOP", "MULOP", "RELOP", "LOGICOP",
  "CONST_INT", "CONST_FLOAT", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
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
      20,   -69,   -69,   -69,    15,    20,   -69,   -69,   -69,   -69,
      -3,   -69,   -69,     3,    40,   -12,    -2,    11,   -69,   -11,
      -6,    14,    22,    32,    60,   -69,   -69,     2,    20,   -69,
     -69,    24,    38,    43,    56,   121,    58,   121,   121,   -69,
     -69,    16,   121,   -69,   -69,   -69,   -69,    49,    96,   -69,
     -69,    36,    54,   -69,    50,    23,    51,   -69,   -69,   -69,
     -69,    65,    61,   121,    85,   121,    67,    71,    57,   -69,
      74,   121,   121,   -69,    78,   -69,   -69,   -69,   -69,   121,
     -69,   121,   121,   121,   121,   -69,   -69,    82,    85,    86,
     -69,    87,   -69,   -69,    88,    84,    89,   -69,   -69,    51,
      97,   -69,   132,   121,   132,    93,   -69,   121,   -69,   127,
     110,   -69,   -69,   -69,   132,   132,   -69,   -69
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
      36,     0,    56,    64,     0,    61,     0,    42,    44,    48,
      46,    50,     0,     0,     0,     0,    55,     0,    40,    32,
       0,    34,    35,    63,     0,     0,    33,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   131,   -69,   -69,   -69,    -5,    27,     8,
     -69,   -69,   -42,   -55,   -37,   -34,   -68,    59,    62,    64,
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
      19,    97,    24,    10,    26,    11,    27,    25,     1,     2,
       3,    28,    60,    21,    15,    24,    13,     9,    16,    87,
      59,    89,     9,   103,    68,    22,    61,    71,    96,   113,
      23,    72,    68,    29,    68,    68,    68,    68,    30,   101,
       1,     2,     3,    77,    78,    79,    82,    31,    83,    63,
     109,    62,   111,    32,    64,    33,    34,    17,    18,   110,
      68,    35,   116,   117,    77,    78,    36,    65,    74,    67,
      37,    38,    80,    24,    39,    84,    81,    86,    40,    41,
       1,     2,     3,    42,    85,    90,    92,    43,    44,    32,
      91,    33,    34,    16,   102,    37,    38,    35,   104,   105,
     106,   107,    36,    40,    41,   108,    37,    38,    42,    24,
      75,   112,    43,    44,    40,    41,     1,     2,     3,    42,
      82,   114,   115,    43,    44,    32,    12,    33,    34,     0,
      98,    37,    38,    35,     0,   100,    99,     0,    36,     0,
      41,     0,    37,    38,    42,    24,     0,     0,    43,    44,
      40,    41,     1,     2,     3,    42,     0,     0,     0,    43,
      44
};

static const yytype_int8 yycheck[] =
{
      37,    35,    37,    71,    38,    42,    48,    42,     0,    64,
      22,    79,    23,     5,    19,     0,    22,    28,    30,    31,
      32,    27,    27,    15,    21,    23,    29,     0,    25,    63,
      28,    65,     5,    88,    71,    37,    28,    21,    72,   107,
      29,    25,    79,    29,    81,    82,    83,    84,    26,    84,
      30,    31,    32,    17,    18,    19,    33,    25,    35,    21,
     102,    37,   104,     3,    21,     5,     6,    27,    28,   103,
     107,    11,   114,   115,    17,    18,    16,    21,    29,    21,
      20,    21,    28,    23,    24,    34,    36,    26,    28,    29,
      30,    31,    32,    33,    29,    28,    22,    37,    38,     3,
      29,     5,     6,    25,    22,    20,    21,    11,    22,    22,
      22,    27,    16,    28,    29,    26,    20,    21,    33,    23,
      24,    28,    37,    38,    28,    29,    30,    31,    32,    33,
      33,     4,    22,    37,    38,     3,     5,     5,     6,    -1,
      81,    20,    21,    11,    -1,    83,    82,    -1,    16,    -1,
      29,    -1,    20,    21,    33,    23,    -1,    -1,    37,    38,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    32,    40,    41,    42,    43,    44,    47,
      48,     0,    42,    29,    49,    21,    25,    27,    28,    22,
      45,    48,    37,    29,    23,    28,    46,    22,    27,    29,
      26,    25,     3,     5,     6,    11,    16,    20,    21,    24,
      28,    29,    33,    37,    38,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    28,
      46,    48,    37,    21,    21,    21,    54,    21,    53,    59,
      54,    21,    25,    59,    29,    24,    51,    17,    18,    19,
      28,    36,    33,    35,    34,    29,    26,    54,    52,    54,
      28,    29,    22,    55,    61,    62,    54,    55,    56,    58,
      57,    59,    22,    52,    22,    22,    22,    27,    26,    51,
      54,    51,    28,    55,     4,    22,    51,    51
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
#line 68 "demo.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
	}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" program : program unit\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "\n";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 82 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" program : unit\n"<<endl; 
            cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; 
        }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : var_declaration\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : func_declaration\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : func_definition\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "demo.y" /* yacc.c:1646  */
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
#line 107 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n"<<endl; 
                
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-4]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[-3].symbol_info)->key;
                *(yyval. temp_str ) += "(";
                *(yyval. temp_str ) += ")";
                *(yyval. temp_str ) += ";";

                cout<<*(yyval. temp_str )<<"\n"<<endl;

            }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<<endl;  
                
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-5]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[-4].symbol_info)->key;
                *(yyval. temp_str ) += "(";
                *(yyval. temp_str ) += *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += ")";
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

                cout<<*(yyval. temp_str )<<"\n"<<endl;

            }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement\n"<<endl;  

                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-4]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[-3].symbol_info)->key;
                *(yyval. temp_str ) += "(";
                *(yyval. temp_str ) += ")";
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

                cout<<*(yyval. temp_str )<<"\n"<<endl;
            
            }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 155 "demo.y" /* yacc.c:1646  */
    {

                cout<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier ID\n"<<endl;  

                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-3]. temp_str );
                *(yyval. temp_str ) += ",";
                *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[0].symbol_info)->key;

                cout<<*(yyval. temp_str )<<"\n"<<endl;

            }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" parameter_list : type_specifier ID\n"<<endl;  
                
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[0].symbol_info)->key;

                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" compound_statement : LCURL statements RCUR\n"<<endl;
                
                // string temp = *$2;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = "{\n"; 
                *(yyval. temp_str ) += *(yyvsp[-1]. temp_str ); 
                *(yyval. temp_str ) += "\n}"; 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" LCURL RCURL\n"<<endl; 

                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = "{\n";  
                *(yyval. temp_str ) += "\n}"; 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "demo.y" /* yacc.c:1646  */
    { 

            cout<<"At line no: "<<line_count<<" var_declaration : type_specifier declaration_list SEMICOLON\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += " ";
            *(yyval. temp_str ) += *(yyvsp[-1]. symbol_info_str );
            *(yyval. temp_str ) += ";";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 218 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : INT\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key; }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 219 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : FLOAT\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : VOID\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 223 "demo.y" /* yacc.c:1646  */
    { 
                    cout<<"At line no: "<<line_count<<" declaration_list COMMA ID\n"<<endl; 
                    
                    (yyval. symbol_info_str ) = new string();
                    *(yyval. symbol_info_str ) = *(yyvsp[-2]. symbol_info_str );
                    *(yyval. symbol_info_str ) += ",";
                    *(yyval. symbol_info_str ) += (yyvsp[0].symbol_info)->key;
                    cout<< *(yyval. symbol_info_str ) <<"\n"<<endl;
                }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "demo.y" /* yacc.c:1646  */
    {
               cout<<"At line no: "<<line_count<<" declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n"<<endl; 
           
                (yyval. symbol_info_str ) = new string();
                *(yyval. symbol_info_str ) = *(yyvsp[-5]. symbol_info_str );
                *(yyval. symbol_info_str ) += ",";
                *(yyval. symbol_info_str ) += (yyvsp[-3].symbol_info)->key;
                *(yyval. symbol_info_str ) += "[";
                *(yyval. symbol_info_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. symbol_info_str ) += "]";

                cout<< *(yyval. symbol_info_str ) <<"\n"<<endl;
           
           }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "demo.y" /* yacc.c:1646  */
    { 
               cout<<"At line no: "<<line_count<<" declaration_list : ID\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl;
                (yyval. symbol_info_str ) = new string();
                *(yyval. symbol_info_str ) = (yyvsp[0].symbol_info)->key;
               }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 252 "demo.y" /* yacc.c:1646  */
    {
               cout<<"At line no: "<<line_count<<" declaration_list : ID LTHIRD CONST_INT RTHIRD\n"<<endl;
           
                (yyval. symbol_info_str ) = new string();
                *(yyval. symbol_info_str ) = (yyvsp[-3].symbol_info)->key;
                *(yyval. symbol_info_str ) += "[";
                *(yyval. symbol_info_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. symbol_info_str ) += "]";

                cout<< *(yyval. symbol_info_str ) <<"\n"<<endl;
           }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 265 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statements : statement\n"<<endl;
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 272 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statements : statements statement\n"<<endl; 
        
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "\n";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 284 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : var_declaration\n"<<endl; 
    
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 291 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : expression_statement\n"<<endl; 
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 297 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : compound_statement\n"<<endl; 
        }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 300 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<<endl; 
        }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 303 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement\n"<<endl; 
        
        }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 307 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement ELSE statemen\n"<<endl; 
        }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 310 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : WHILE LPAREN expression RPAREN statement\n"<<endl; 
        }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 313 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<<endl; 
        }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 316 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : RETURN expression SEMICOLON\n"<<endl; 

            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = "return";
            *(yyval. temp_str ) += " ";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += ";";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 329 "demo.y" /* yacc.c:1646  */
    {
                    cout<<"At line no: "<<line_count<<" expression_statement : SEMICOLON\n"<<endl; 
                }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 332 "demo.y" /* yacc.c:1646  */
    {
                    cout<<"At line no: "<<line_count<<" expression_statement : expression SEMICOLON\n"<<endl; 
                    (yyval. temp_str ) = new string();
                    *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
                    *(yyval. temp_str ) += ";";

                    cout<<*(yyval. temp_str )<<"\n"<<endl;
                }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 342 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" variable : ID\n"<<endl; 
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 348 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" variable : ID LTHIRD expression RTHIRD\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[-3].symbol_info)->key;
            *(yyval. temp_str ) += "[";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "]";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
         }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 361 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" expression : logic_expression\n"<<endl; 
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 367 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" expression : variable ASSIGNOP logic_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += "=";
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 379 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" logic_expression : rel_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 385 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" logic_expression : rel_expression LOGICOP rel_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 395 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                 cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 401 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression RELOP simple_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 411 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" simple_expression : term\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 417 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
               (yyval. temp_str ) = new string();
               *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
               *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
               *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

               cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 428 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" term : unary_expression\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 434 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" term : term MULOP unary_expressio\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 444 "demo.y" /* yacc.c:1646  */
    {
                
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = (yyvsp[-1].symbol_info)->key;
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 452 "demo.y" /* yacc.c:1646  */
    {
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 456 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" unary_expression : factor\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 464 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;

        }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 471 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : ID LPAREN argument_list RPAREN\n"<<endl; 

            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[-3].symbol_info)->key;
            *(yyval. temp_str ) += "( ";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += " )";
            cout<<*(yyval. temp_str )<<"\n"<<endl;

        }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 482 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : LPAREN expression RPAREN\n"<<endl; 

            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = "(";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += ")";
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        
        }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 492 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" factor : CONST_INT\n"<<endl; 
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 498 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" factor : CONST_FLOAT\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key; 
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 504 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable INCOP\n"<<endl; 
        }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 507 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable DECOP\n"<<endl; 
        }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 512 "demo.y" /* yacc.c:1646  */
    {
                    cout<<"At line no: "<<line_count<<" arguments : arguments\n"<<endl;

                    (yyval. temp_str ) = new string();
                    *(yyval. temp_str ) = *(yyvsp[0]. temp_str ); 
                    cout<<*(yyval. temp_str )<<"\n"<<endl;
                }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 519 "demo.y" /* yacc.c:1646  */
    {
                cout<<"WHAT IS THIS"<<endl;
            }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 524 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" arguments : arguments COMMA logic_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str ); 
                *(yyval. temp_str ) += " , "; 
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str ); 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 532 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" arguments : logic_expression\n"<<endl;

                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str ); 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            
            }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2147 "y.tab.c" /* yacc.c:1646  */
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
#line 542 "demo.y" /* yacc.c:1906  */


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
