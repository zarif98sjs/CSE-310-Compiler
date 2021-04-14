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


#line 104 "demo.tab.c" /* yacc.c:339  */

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

#line 135 "demo.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    LOWER_THAN_ELSE = 260,
    FOR = 261,
    WHILE = 262,
    DO = 263,
    BREAK = 264,
    CHAR = 265,
    DOUBLE = 266,
    RETURN = 267,
    SWITCH = 268,
    CASE = 269,
    DEFAULT = 270,
    CONTINUE = 271,
    PRINTLN = 272,
    INCOP = 273,
    DECOP = 274,
    ASSIGNOP = 275,
    NOT = 276,
    LPAREN = 277,
    RPAREN = 278,
    LCURL = 279,
    RCURL = 280,
    LTHIRD = 281,
    RTHIRD = 282,
    COMMA = 283,
    SEMICOLON = 284,
    ID = 285,
    INT = 286,
    FLOAT = 287,
    VOID = 288,
    ADDOP = 289,
    MULOP = 290,
    RELOP = 291,
    LOGICOP = 292,
    CONST_INT = 293,
    CONST_FLOAT = 294
  };
#endif

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

#line 196 "demo.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 213 "demo.tab.c" /* yacc.c:358  */

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
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    76,    85,    91,    92,    93,    96,   110,
     126,   141,   158,   172,   173,   183,   187,   197,   207,   221,
     222,   223,   226,   235,   249,   254,   268,   275,   287,   294,
     300,   303,   306,   319,   334,   337,   340,   353,   356,   366,
     372,   385,   391,   403,   409,   419,   425,   435,   441,   452,
     458,   468,   476,   480,   488,   495,   506,   516,   522,   528,
     531,   536,   543,   548,   556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "LOWER_THAN_ELSE", "FOR",
  "WHILE", "DO", "BREAK", "CHAR", "DOUBLE", "RETURN", "SWITCH", "CASE",
  "DEFAULT", "CONTINUE", "PRINTLN", "INCOP", "DECOP", "ASSIGNOP", "NOT",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "ID", "INT", "FLOAT", "VOID", "ADDOP", "MULOP", "RELOP",
  "LOGICOP", "CONST_INT", "CONST_FLOAT", "$accept", "start", "program",
  "unit", "func_declaration", "func_definition", "parameter_list",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,   -65,   -65,   -65,    24,    17,   -65,   -65,   -65,   -65,
       5,   -65,   -65,   -12,    34,   -14,    13,    25,   -65,    -8,
       2,    29,    40,    48,    54,   -65,   -65,     4,    17,   -65,
     -65,    42,    77,    79,    81,    68,    82,    68,    68,   -65,
     -65,     0,    68,   -65,   -65,   -65,   -65,    84,    88,   -65,
     -65,    21,    86,   -65,    71,    18,    76,   -65,   -65,   -65,
     -65,    93,    89,    68,    43,    68,    95,   100,    78,   -65,
     108,    68,    68,   -65,   106,   -65,   -65,   -65,   -65,    68,
     -65,    68,    68,    68,    68,   -65,   -65,   110,    43,   112,
     -65,   113,   -65,   -65,   114,   117,   111,   -65,   -65,    76,
     107,   -65,   122,    68,   122,   118,   -65,    68,   -65,   -65,
     119,   -65,   -65,   -65,   122,   -65
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
       0,    34,    35,    63,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   135,   -65,   -65,   -65,    -7,    32,     8,
     -65,   -65,   -46,   -61,   -37,   -34,   -64,    67,    66,    75,
     -31,   -65,   -65,   -65
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
      68,    66,    76,    88,    70,    68,    69,    93,    10,    19,
      15,    73,    26,    10,    16,    97,    24,     1,     2,     3,
      60,    25,    71,    21,    11,    27,    72,   103,    24,    87,
      28,    89,     9,    59,    68,    13,    61,     9,    96,    77,
      78,    79,    68,   113,    68,    68,    68,    68,     1,     2,
       3,    22,    82,   101,    83,    23,   109,    32,   111,    29,
      33,    34,    17,    18,    37,    38,    35,    30,   115,   110,
      68,    36,    40,    41,    31,    37,    38,    42,    24,    39,
      62,    43,    44,    40,    41,     1,     2,     3,    42,    37,
      38,    32,    43,    44,    33,    34,    77,    78,    41,    63,
      35,    64,    42,    65,    67,    36,    43,    44,    81,    37,
      38,    84,    24,    75,    74,    80,    86,    40,    41,     1,
       2,     3,    42,    85,    90,    32,    43,    44,    33,    34,
      91,    92,    16,   102,    35,   104,   105,   106,   108,    36,
      12,    82,   114,    37,    38,   107,    24,   112,    98,   100,
       0,    40,    41,     1,     2,     3,    42,    99,     0,     0,
      43,    44
};

static const yytype_int8 yycheck[] =
{
      37,    35,    48,    64,    38,    42,    37,    71,     0,    23,
      22,    42,    19,     5,    26,    79,    24,    31,    32,    33,
      27,    29,    22,    15,     0,    23,    26,    88,    24,    63,
      28,    65,     0,    29,    71,    30,    28,     5,    72,    18,
      19,    20,    79,   107,    81,    82,    83,    84,    31,    32,
      33,    38,    34,    84,    36,    30,   102,     3,   104,    30,
       6,     7,    28,    29,    21,    22,    12,    27,   114,   103,
     107,    17,    29,    30,    26,    21,    22,    34,    24,    25,
      38,    38,    39,    29,    30,    31,    32,    33,    34,    21,
      22,     3,    38,    39,     6,     7,    18,    19,    30,    22,
      12,    22,    34,    22,    22,    17,    38,    39,    37,    21,
      22,    35,    24,    25,    30,    29,    27,    29,    30,    31,
      32,    33,    34,    30,    29,     3,    38,    39,     6,     7,
      30,    23,    26,    23,    12,    23,    23,    23,    27,    17,
       5,    34,    23,    21,    22,    28,    24,    29,    81,    83,
      -1,    29,    30,    31,    32,    33,    34,    82,    -1,    -1,
      38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    41,    42,    43,    44,    45,    48,
      49,     0,    43,    30,    50,    22,    26,    28,    29,    23,
      46,    49,    38,    30,    24,    29,    47,    23,    28,    30,
      27,    26,     3,     6,     7,    12,    17,    21,    22,    25,
      29,    30,    34,    38,    39,    47,    48,    49,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    29,
      47,    49,    38,    22,    22,    22,    55,    22,    54,    60,
      55,    22,    26,    60,    30,    25,    52,    18,    19,    20,
      29,    37,    34,    36,    35,    30,    27,    55,    53,    55,
      29,    30,    23,    56,    62,    63,    55,    56,    57,    59,
      58,    60,    23,    53,    23,    23,    23,    28,    27,    52,
      55,    52,    29,    56,    23,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63
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
#line 71 "demo.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
	}
#line 1384 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" program : program unit\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "\n";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1398 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" program : unit\n"<<endl; 
            cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; 
        }
#line 1407 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : var_declaration\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1413 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : func_declaration\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1419 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" unit : func_definition\n"<<endl; cout<<*(yyvsp[0]. temp_str )<<"\n"<<endl; }
#line 1425 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 96 "demo.y" /* yacc.c:1646  */
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
#line 1444 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "demo.y" /* yacc.c:1646  */
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
#line 1463 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "demo.y" /* yacc.c:1646  */
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
#line 1483 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "demo.y" /* yacc.c:1646  */
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
#line 1502 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "demo.y" /* yacc.c:1646  */
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
#line 1521 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 173 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" parameter_list : type_specifier ID\n"<<endl;  
                
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
                *(yyval. temp_str ) += " ";
                *(yyval. temp_str ) += (yyvsp[0].symbol_info)->key;

                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1536 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 187 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" compound_statement : LCURL statements RCUR\n"<<endl;
                
                // string temp = *$2;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = "{\n"; 
                *(yyval. temp_str ) += *(yyvsp[-1]. temp_str ); 
                *(yyval. temp_str ) += "\n}"; 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1551 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 197 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" LCURL RCURL\n"<<endl; 

                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = "{\n";  
                *(yyval. temp_str ) += "\n}"; 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1564 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "demo.y" /* yacc.c:1646  */
    { 

            cout<<"At line no: "<<line_count<<" var_declaration : type_specifier declaration_list SEMICOLON\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += " ";
            *(yyval. temp_str ) += *(yyvsp[-1]. symbol_info_str );
            *(yyval. temp_str ) += ";";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1581 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 221 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : INT\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key; }
#line 1587 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : FLOAT\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;}
#line 1593 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "demo.y" /* yacc.c:1646  */
    { cout<<"At line no: "<<line_count<<" type_specifier : VOID\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;}
#line 1599 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 226 "demo.y" /* yacc.c:1646  */
    { 
                    cout<<"At line no: "<<line_count<<" declaration_list COMMA ID\n"<<endl; 
                    
                    (yyval. symbol_info_str ) = new string();
                    *(yyval. symbol_info_str ) = *(yyvsp[-2]. symbol_info_str );
                    *(yyval. symbol_info_str ) += ",";
                    *(yyval. symbol_info_str ) += (yyvsp[0].symbol_info)->key;
                    cout<< *(yyval. symbol_info_str ) <<"\n"<<endl;
                }
#line 1613 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 235 "demo.y" /* yacc.c:1646  */
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
#line 1632 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "demo.y" /* yacc.c:1646  */
    { 
               cout<<"At line no: "<<line_count<<" declaration_list : ID\n"<<endl; cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl;
                (yyval. symbol_info_str ) = new string();
                *(yyval. symbol_info_str ) = (yyvsp[0].symbol_info)->key;
               }
#line 1642 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 255 "demo.y" /* yacc.c:1646  */
    {
               cout<<"At line no: "<<line_count<<" declaration_list : ID LTHIRD CONST_INT RTHIRD\n"<<endl;
           
                (yyval. symbol_info_str ) = new string();
                *(yyval. symbol_info_str ) = (yyvsp[-3].symbol_info)->key;
                *(yyval. symbol_info_str ) += "[";
                *(yyval. symbol_info_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. symbol_info_str ) += "]";

                cout<< *(yyval. symbol_info_str ) <<"\n"<<endl;
           }
#line 1658 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 268 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statements : statement\n"<<endl;
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1670 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 275 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statements : statements statement\n"<<endl; 
        
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "\n";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

            cout<<*(yyval. temp_str )<<"\n"<<endl; 
        }
#line 1685 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 287 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : var_declaration\n"<<endl; 
    
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1697 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 294 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : expression_statement\n"<<endl; 
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1708 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 300 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : compound_statement\n"<<endl; 
        }
#line 1716 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 303 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<<endl; 
        }
#line 1724 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 306 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = "if";
            *(yyval. temp_str ) += "(";
            *(yyval. temp_str ) += *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += ")";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

            cout<<*(yyval. temp_str )<<"\n"<<endl;

        }
#line 1742 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 319 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement ELSE statemen\n"<<endl; 
        
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = "if";
            *(yyval. temp_str ) += "(";
            *(yyval. temp_str ) += *(yyvsp[-4]. temp_str );
            *(yyval. temp_str ) += ")";
            *(yyval. temp_str ) += *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += "else ";
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        
        }
#line 1762 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 334 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : WHILE LPAREN expression RPAREN statement\n"<<endl; 
        }
#line 1770 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 337 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<<endl; 
        }
#line 1778 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 340 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" statement : RETURN expression SEMICOLON\n"<<endl; 

            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = "return";
            *(yyval. temp_str ) += " ";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += ";";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1794 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 353 "demo.y" /* yacc.c:1646  */
    {
                    cout<<"At line no: "<<line_count<<" expression_statement : SEMICOLON\n"<<endl; 
                }
#line 1802 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 356 "demo.y" /* yacc.c:1646  */
    {
                    cout<<"At line no: "<<line_count<<" expression_statement : expression SEMICOLON\n"<<endl; 
                    (yyval. temp_str ) = new string();
                    *(yyval. temp_str ) = *(yyvsp[-1]. temp_str );
                    *(yyval. temp_str ) += ";";

                    cout<<*(yyval. temp_str )<<"\n"<<endl;
                }
#line 1815 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 366 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" variable : ID\n"<<endl; 
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1826 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 372 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" variable : ID LTHIRD expression RTHIRD\n"<<endl; 
            
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[-3].symbol_info)->key;
            *(yyval. temp_str ) += "[";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += "]";

            cout<<*(yyval. temp_str )<<"\n"<<endl;
         }
#line 1842 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 385 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" expression : logic_expression\n"<<endl; 
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1853 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 391 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" expression : variable ASSIGNOP logic_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += "=";
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1866 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 403 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" logic_expression : rel_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1877 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 409 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" logic_expression : rel_expression LOGICOP rel_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1890 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 419 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                 cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1901 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 425 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" rel_expression : simple_expression RELOP simple_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
                *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1914 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 435 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" simple_expression : term\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1925 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 441 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
               (yyval. temp_str ) = new string();
               *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
               *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
               *(yyval. temp_str ) += *(yyvsp[0]. temp_str );

               cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1939 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 452 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" term : unary_expression\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1950 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 458 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" term : term MULOP unary_expressio\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[-2]. temp_str );
            *(yyval. temp_str ) += (yyvsp[-1].symbol_info)->key;
            *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 1963 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 468 "demo.y" /* yacc.c:1646  */
    {
                
                cout<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = (yyvsp[-1].symbol_info)->key;
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 1976 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 476 "demo.y" /* yacc.c:1646  */
    {
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            }
#line 1985 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 480 "demo.y" /* yacc.c:1646  */
    { 
                cout<<"At line no: "<<line_count<<" unary_expression : factor\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
                cout<<*(yyval. temp_str )<<"\n"<<endl;
             }
#line 1996 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 488 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = *(yyvsp[0]. temp_str );
            cout<<*(yyval. temp_str )<<"\n"<<endl;

        }
#line 2008 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 495 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : ID LPAREN argument_list RPAREN\n"<<endl; 

            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[-3].symbol_info)->key;
            *(yyval. temp_str ) += "( ";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += " )";
            cout<<*(yyval. temp_str )<<"\n"<<endl;

        }
#line 2024 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 506 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : LPAREN expression RPAREN\n"<<endl; 

            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = "(";
            *(yyval. temp_str ) += *(yyvsp[-1]. temp_str );
            *(yyval. temp_str ) += ")";
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        
        }
#line 2039 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 516 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" factor : CONST_INT\n"<<endl; 
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key;
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 2050 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 522 "demo.y" /* yacc.c:1646  */
    { 
            cout<<"At line no: "<<line_count<<" factor : CONST_FLOAT\n"<<endl;
            (yyval. temp_str ) = new string();
            *(yyval. temp_str ) = (yyvsp[0].symbol_info)->key; 
            cout<<*(yyval. temp_str )<<"\n"<<endl;
        }
#line 2061 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 528 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable INCOP\n"<<endl; 
        }
#line 2069 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 531 "demo.y" /* yacc.c:1646  */
    {
            cout<<"At line no: "<<line_count<<" factor : variable DECOP\n"<<endl; 
        }
#line 2077 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 536 "demo.y" /* yacc.c:1646  */
    {
                    cout<<"At line no: "<<line_count<<" arguments : arguments\n"<<endl;

                    (yyval. temp_str ) = new string();
                    *(yyval. temp_str ) = *(yyvsp[0]. temp_str ); 
                    cout<<*(yyval. temp_str )<<"\n"<<endl;
                }
#line 2089 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 543 "demo.y" /* yacc.c:1646  */
    {
                cout<<"WHAT IS THIS"<<endl;
            }
#line 2097 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 548 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" arguments : arguments COMMA logic_expression\n"<<endl;
                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[-2]. temp_str ); 
                *(yyval. temp_str ) += " , "; 
                *(yyval. temp_str ) += *(yyvsp[0]. temp_str ); 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            }
#line 2110 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 556 "demo.y" /* yacc.c:1646  */
    {
                cout<<"At line no: "<<line_count<<" arguments : logic_expression\n"<<endl;

                (yyval. temp_str ) = new string();
                *(yyval. temp_str ) = *(yyvsp[0]. temp_str ); 
                cout<<*(yyval. temp_str )<<"\n"<<endl;
            
            }
#line 2123 "demo.tab.c" /* yacc.c:1646  */
    break;


#line 2127 "demo.tab.c" /* yacc.c:1646  */
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
#line 566 "demo.y" /* yacc.c:1906  */


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
