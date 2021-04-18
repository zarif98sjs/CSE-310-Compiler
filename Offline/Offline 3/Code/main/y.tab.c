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
#include "Helper.h"

// #define YYSTYPE SymbolInfo*

extern FILE *yyin;

void yyerror(string s){
	cout<<s<<"\n"<<endl;
}

int yyparse(void);
int yylex(void);

extern int line_count;

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// SYMBOL TABLE //////////////////////////////////////////////////

int hashF(string s)
{
    int h = 0;
    for(int i=0;i<(int)s.size();i++)
    {
        h = (h + s[i]);
    }
    return h;
}

int bucket_size = 30;
SymbolTable *sym_tab = new SymbolTable(bucket_size,hashF);

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// FUNCTION PARAMETER  ///////////////////////////////////////////

bool is_function_now = false;
vector<SymbolInfo>function_params;


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// ERROR HANDLING ///////////////////////////////////////////////

string do_implicit_typecast(string left_op,string right_op)
{
    if(left_op == "void" || right_op == "void") return "error";

    if(left_op == "float" || right_op == "float") return "float";

    return "int";
}

bool is_param_typecast_ok(string og_p,string pass_p)
{
    if(og_p == "void") return pass_p == "void";
    if(og_p == "int") return pass_p == "int";
    if(og_p == "float") return pass_p != "void";
}

bool check_assignop(string left_op,string right_op)
{

    if(left_op == "void" || right_op == "void") return false;

    if(left_op == "int" && right_op =="int_array") return true;
    if(left_op == "int_array" && right_op =="int") return true;

    if(left_op == "float" && right_op =="float_array") return true;
    if(left_op == "float_array" && right_op =="float") return true;

    if(left_op == "int" && right_op !="int") return false;

    return true;
}

void print_grammar_rule(string left_part,string right_part)
{
    cout<<"At line no: "<<line_count<<" "<<left_part<<" : "<<right_part<<"\n"<<endl; 
}

void print_log_text(string log_text)
{
    cout<<log_text<<"\n"<<endl;
}

void error_multiple_declaration(string error_symbol)
{
    cout<<"Error at Line "<<line_count<<": Multiple Declaration of "<<error_symbol<<"\n"<<endl;
}

void error_array_size_float()
{
    cout<<"Error at Line "<<line_count<<": Non-integer Array Size\n"<<endl;
}

void error_array_index_float()
{
    cout<<"Error at Line "<<line_count<<": Non-integer Array Index\n"<<endl;
}

void error_type_cast()
{
    cout<<"Error at Line "<<line_count<<": operand is void\n"<<endl;
}

void error_type_cast_mod()
{
    cout<<"Error at Line "<<line_count<<": non-integer operand on modulus operator\n"<<endl;
}

void error_undeclared_variable(string var_name)
{
    cout<<"Error at Line "<<line_count<<": Undeclared Variable: "<<var_name<<"\n"<<endl;
}

void error_type_mismatch()
{
    cout<<"Error at Line "<<line_count<<": Type Mismatch\n"<<endl;
}



#line 195 "y.tab.c" /* yacc.c:339  */

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

#line 229 "y.tab.c" /* yacc.c:355  */

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
/* Tokens.  */
#define IF 258
#define ELSE 259
#define LOWER_THAN_ELSE 260
#define FOR 261
#define WHILE 262
#define DO 263
#define BREAK 264
#define CHAR 265
#define DOUBLE 266
#define RETURN 267
#define SWITCH 268
#define CASE 269
#define DEFAULT 270
#define CONTINUE 271
#define PRINTLN 272
#define INCOP 273
#define DECOP 274
#define ASSIGNOP 275
#define NOT 276
#define LPAREN 277
#define RPAREN 278
#define LCURL 279
#define RCURL 280
#define LTHIRD 281
#define RTHIRD 282
#define COMMA 283
#define SEMICOLON 284
#define ID 285
#define INT 286
#define FLOAT 287
#define VOID 288
#define ADDOP 289
#define MULOP 290
#define RELOP 291
#define LOGICOP 292
#define CONST_INT 293
#define CONST_FLOAT 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 135 "demo.y" /* yacc.c:355  */

    SymbolInfo* symbol_info;
    // SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    Helper* helper;
    // int ival;
    // double dval;

#line 329 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 346 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

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
       0,   161,   161,   167,   177,   184,   185,   186,   189,   230,
     262,   262,   333,   357,   377,   380,   396,   401,   418,   439,
     455,   486,   487,   488,   491,   511,   535,   567,   581,   601,
     628,   635,   647,   654,   660,   663,   666,   679,   695,   698,
     701,   714,   717,   730,   757,   796,   807,   830,   841,   860,
     871,   890,   902,   920,   932,   962,   974,   986,   999,  1011,
    1083,  1096,  1108,  1119,  1122,  1127,  1138,  1144,  1159
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
  "unit", "func_declaration", "func_definition", "$@1", "parameter_list",
  "compound_statement", "dummy_scope_function", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
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

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,   -77,   -77,   -77,    35,    24,   -77,   -77,   -77,   -77,
      -3,   -77,   -77,    26,   -12,   -11,    27,    29,   -77,     4,
      -9,    34,    16,    54,    56,   -77,   -77,   -77,    57,    24,
     -77,   -77,   -77,    36,    66,   -77,    68,    71,    75,    81,
      87,    88,    89,     2,    91,     2,     2,   -77,   -77,    28,
       2,   -77,   -77,   -77,   -77,    84,   100,   -77,   -77,    43,
      86,   -77,    79,    17,    83,   -77,   -77,   -77,   -77,   -77,
     -77,     2,    55,     2,    90,    93,    61,   -77,    97,     2,
       2,   -77,   101,   -77,   -77,   -77,   -77,     2,   -77,     2,
       2,     2,     2,   103,    55,   105,   -77,   112,   -77,   -77,
     113,   114,   116,   -77,   -77,    83,   110,   -77,   134,     2,
     134,   118,   -77,     2,   -77,   141,   125,   -77,   -77,   -77,
     134,   134,   -77,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    22,    23,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,     0,     0,     0,    20,     0,
       0,    16,     0,     0,    24,    19,     9,    12,    10,     0,
      15,    28,    29,     0,     0,     8,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    41,    43,
       0,    61,    62,    34,    32,     0,     0,    30,    33,    58,
       0,    45,    47,    49,    51,    53,    57,    11,    13,    25,
      26,     0,     0,     0,     0,     0,    58,    56,     0,    66,
       0,    55,    27,    17,    31,    63,    64,     0,    42,     0,
       0,     0,     0,     0,     0,     0,    40,     0,    60,    68,
       0,    65,     0,    46,    48,    52,    50,    54,     0,     0,
       0,     0,    59,     0,    44,    36,     0,    38,    39,    67,
       0,     0,    37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   144,   -77,   -77,   -77,   -77,   -10,   -77,
      13,    10,   -77,   -77,   -50,   -64,   -45,   -42,   -76,    63,
      59,    64,   -43,   -77,   -77,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    36,    20,    53,    34,
      54,    55,    14,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   100,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    74,    77,    99,    78,    76,    84,    81,    94,    27,
      10,   103,    19,     9,    28,    10,    17,    18,     9,    29,
       1,     2,     3,    45,    46,    21,    67,    13,    25,    93,
     109,    95,    49,    26,    76,    11,    50,   119,   102,    37,
      51,    52,    76,    31,    76,    76,    76,    76,    15,   107,
      79,    90,    16,    91,    80,     1,     2,     3,   115,    24,
     117,    85,    86,    87,    30,    22,    23,   116,    76,    40,
     122,   123,    41,    42,    38,    39,    45,    46,    43,    85,
      86,    32,    33,    44,    48,    49,    35,    45,    46,    50,
      25,    47,    25,    51,    52,    48,    49,     1,     2,     3,
      50,    68,    69,    40,    51,    52,    41,    42,    70,    71,
      72,    73,    43,    75,    82,    88,    89,    44,    92,    96,
      98,    45,    46,    97,    25,    83,   108,    16,   110,    48,
      49,     1,     2,     3,    50,   111,   112,    40,    51,    52,
      41,    42,   113,   114,    90,   120,    43,   118,   121,    12,
     106,    44,   104,     0,   105,    45,    46,     0,    25,     0,
       0,     0,     0,    48,    49,     1,     2,     3,    50,     0,
       0,     0,    51,    52
};

static const yytype_int8 yycheck[] =
{
      45,    43,    45,    79,    46,    50,    56,    50,    72,    19,
       0,    87,    23,     0,    23,     5,    28,    29,     5,    28,
      31,    32,    33,    21,    22,    15,    36,    30,    24,    71,
      94,    73,    30,    29,    79,     0,    34,   113,    80,    29,
      38,    39,    87,    27,    89,    90,    91,    92,    22,    92,
      22,    34,    26,    36,    26,    31,    32,    33,   108,    30,
     110,    18,    19,    20,    30,    38,    39,   109,   113,     3,
     120,   121,     6,     7,    38,    39,    21,    22,    12,    18,
      19,    27,    26,    17,    29,    30,    29,    21,    22,    34,
      24,    25,    24,    38,    39,    29,    30,    31,    32,    33,
      34,    30,    27,     3,    38,    39,     6,     7,    27,    22,
      22,    22,    12,    22,    30,    29,    37,    17,    35,    29,
      23,    21,    22,    30,    24,    25,    23,    26,    23,    29,
      30,    31,    32,    33,    34,    23,    23,     3,    38,    39,
       6,     7,    28,    27,    34,     4,    12,    29,    23,     5,
      91,    17,    89,    -1,    90,    21,    22,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    41,    42,    43,    44,    45,    50,
      51,     0,    43,    30,    52,    22,    26,    28,    29,    23,
      47,    51,    38,    39,    30,    24,    29,    48,    23,    28,
      30,    27,    27,    26,    49,    29,    46,    51,    38,    39,
       3,     6,     7,    12,    17,    21,    22,    25,    29,    30,
      34,    38,    39,    48,    50,    51,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    48,    30,    27,
      27,    22,    22,    22,    57,    22,    56,    62,    57,    22,
      26,    62,    30,    25,    54,    18,    19,    20,    29,    37,
      34,    36,    35,    57,    55,    57,    29,    30,    23,    58,
      64,    65,    57,    58,    59,    61,    60,    62,    23,    55,
      23,    23,    23,    28,    27,    54,    57,    54,    29,    58,
       4,    23,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      46,    45,    45,    47,    47,    47,    47,    48,    48,    49,
      50,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     5,     4,     3,     2,     1,     4,     3,     0,
       3,     1,     1,     1,     3,     6,     6,     1,     4,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
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
#line 162 "demo.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
	}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 167 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("program","program unit");

            (yyval. helper ) = new Helper();
            (yyval. helper )->text = (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += "\n";
            (yyval. helper )->text += (yyvsp[0]. helper )->text;

            print_log_text((yyval. helper )->text); 
        }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 177 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("program","unit");

            print_log_text((yyvsp[0]. helper )->text); 
        }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 184 "demo.y" /* yacc.c:1646  */
    { print_grammar_rule("unit","var_declaration"); print_log_text((yyvsp[0]. helper )->text); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 185 "demo.y" /* yacc.c:1646  */
    { print_grammar_rule("unit","func_declaration"); print_log_text((yyvsp[0]. helper )->text);  }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 186 "demo.y" /* yacc.c:1646  */
    { print_grammar_rule("unit","func_definition"); print_log_text((yyvsp[0]. helper )->text);  }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 189 "demo.y" /* yacc.c:1646  */
    { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-5]. helper )->text;
                (yyval. helper )->text += " ";
                (yyval. helper )->text += (yyvsp[-4].symbol_info)->key;
                (yyval. helper )->text += "(";
                (yyval. helper )->text += (yyvsp[-2]. helper )->text;
                (yyval. helper )->text += ")";
                (yyval. helper )->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-4].symbol_info)->setVarType((yyvsp[-5]. helper )->text);
                (yyvsp[-4].symbol_info)->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    (yyvsp[-4].symbol_info)->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*(yyvsp[-4].symbol_info)))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-4].symbol_info)->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration((yyvsp[-4].symbol_info)->key);
                }

                print_log_text((yyval. helper )->text);

                // clear param_info
                function_params.clear();
    
            }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 230 "demo.y" /* yacc.c:1646  */
    { 

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-4]. helper )->text;
                (yyval. helper )->text += " ";
                (yyval. helper )->text += (yyvsp[-3].symbol_info)->key;
                (yyval. helper )->text += "(";
                (yyval. helper )->text += ")";
                (yyval. helper )->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-3].symbol_info)->setVarType((yyvsp[-4]. helper )->text);
                (yyvsp[-3].symbol_info)->isFunction = true;
                
                if(sym_tab->insert_symbol(*(yyvsp[-3].symbol_info)))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-3].symbol_info)->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration((yyvsp[-3].symbol_info)->key);
                }

                print_log_text((yyval. helper )->text);
            }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 262 "demo.y" /* yacc.c:1646  */
    {is_function_now = true;}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 262 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-6]. helper )->text;
                (yyval. helper )->text += " ";
                (yyval. helper )->text += (yyvsp[-5].symbol_info)->key;
                (yyval. helper )->text += "(";
                (yyval. helper )->text += (yyvsp[-3]. helper )->text;
                (yyval. helper )->text += ")";
                (yyval. helper )->text += (yyvsp[0]. helper )->text; 

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-5].symbol_info)->setVarType((yyvsp[-6]. helper )->text);
                (yyvsp[-5].symbol_info)->isFunction = true;

                // update parrameter type
                for(auto temp_s : function_params)
                {
                    (yyvsp[-5].symbol_info)->param_v.push_back(temp_s.var_type);
                }

                if(!sym_tab->insert_symbol(*(yyvsp[-5].symbol_info)))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-5].symbol_info)->key);

                    if(ret_symbol->isFunctionDeclaration == false){
                        error_multiple_declaration((yyvsp[-5].symbol_info)->key);
                    }
                    else{

                        // declared before , now definition happening

                        // check if any clash between declaration and definition

                        if(ret_symbol->var_type != (yyvsp[-5].symbol_info)->var_type)
                        {
                            cout<<"Error : Function return type conflict (Declaration vs Definition)"<<endl;
                        }

                        if(ret_symbol->param_v.size() != (yyvsp[-5].symbol_info)->param_v.size())
                        {
                            cout<<"Error : Parameter number conflict (Declaration vs Definition)"<<endl;
                        }
                        else
                        {
                            for(int i=0;i<ret_symbol->param_v.size();i++)
                            {
                                if(ret_symbol->param_v[i] != (yyvsp[-5].symbol_info)->param_v[i]){
                                    cout<<"Error : Parameter type conflict (Declaration vs Definition)"<<endl;
                                    break;
                                }
                            }
                        }


                        // the following line is commented out because in case of clash , use the declaration info 
                        // ret_symbol->param_v = $2->param_v;
                        ret_symbol->isFunctionDeclaration = false; // declaration + 
                    }
                }

                print_log_text((yyval. helper )->text);

                // clear temp function params
                is_function_now = false;
                function_params.clear();

            }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 333 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN RPAREN compound_statement");

                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-4]. helper )->text;
                (yyval. helper )->text += " ";
                (yyval. helper )->text += (yyvsp[-3].symbol_info)->key;
                (yyval. helper )->text += "(";
                (yyval. helper )->text += ")";
                (yyval. helper )->text += (yyvsp[0]. helper )->text;

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-3].symbol_info)->setVarType((yyvsp[-4]. helper )->text);
                (yyvsp[-3].symbol_info)->isFunction = true;
                sym_tab->insert_symbol(*(yyvsp[-3].symbol_info));

                print_log_text((yyval. helper )->text);
            
            }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 357 "demo.y" /* yacc.c:1646  */
    {

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-3]. helper )->text;
                (yyval. helper )->text += ",";
                (yyval. helper )->text += (yyvsp[-1]. helper )->text;
                (yyval. helper )->text += " ";
                (yyval. helper )->text += (yyvsp[0].symbol_info)->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                (yyvsp[0].symbol_info)->setVarType((yyvsp[-1]. helper )->text);
                function_params.push_back(*(yyvsp[0].symbol_info));

                print_log_text((yyval. helper )->text);

            }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 377 "demo.y" /* yacc.c:1646  */
    {
             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");
        }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 380 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("parameter_list","type_specifier ID");
                
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-1]. helper )->text;
                (yyval. helper )->text += " ";
                (yyval. helper )->text += (yyvsp[0].symbol_info)->key;

                // insert parameter ID to Parameter SymbolTable with VAR_TYPE
                (yyvsp[0].symbol_info)->setVarType((yyvsp[-1]. helper )->text);
                function_params.push_back(*(yyvsp[0].symbol_info));

                print_log_text((yyval. helper )->text);
             }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 396 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("parameter_list","type_specifier");
        }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 401 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = "{\n"; 
                (yyval. helper )->text += (yyvsp[-1]. helper )->text; 
                (yyval. helper )->text += "\n}"; 

                print_log_text((yyval. helper )->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

             }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 418 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");

                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = "{\n";  
                (yyval. helper )->text += "\n}"; 

                print_log_text((yyval. helper )->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

                // // clear temp function params
                // is_function_now = false;
                // function_params.clear();
             }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 439 "demo.y" /* yacc.c:1646  */
    {

                    sym_tab->enter_scope(); 

                    if(is_function_now)
                    {
                        for(auto el:function_params)
                        {
                            // insert ID
                            cout<<"INSIDE FUNCTIONNN"<<endl;
                            sym_tab->insert_symbol(el);
                        }
                    }
                }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 455 "demo.y" /* yacc.c:1646  */
    { 

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
            (yyval. helper ) = new Helper();

            // update text
            (yyval. helper )->text = (yyvsp[-2]. helper )->text;
            (yyval. helper )->text += " ";
            (yyval. helper )->text += (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += ";";

            sym_tab->print_all_scope();

            // insert all declaration_list ID to SymbolTable with VAR_TYPE
            for(auto el:(yyvsp[-1]. helper )->v)
            {
                if(el->var_type == "array") el->setVarType((yyvsp[-2]. helper )->text + "_array") , cout<<"ARRAY"<<endl; 
                else el->setVarType((yyvsp[-2]. helper )->text); 
                
                if(!sym_tab->insert_symbol(*el)) // already present in current scope
                {
                    error_multiple_declaration(el->key);
                }

            }

            print_log_text((yyval. helper )->text);
        }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 486 "demo.y" /* yacc.c:1646  */
    { print_grammar_rule("type_specifier","INT"); cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; (yyval. helper )->text = (yyvsp[0].symbol_info)->key; }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 487 "demo.y" /* yacc.c:1646  */
    { print_grammar_rule("type_specifier","FLOAT"); cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; (yyval. helper )->text = (yyvsp[0].symbol_info)->key;}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 488 "demo.y" /* yacc.c:1646  */
    { print_grammar_rule("type_specifier","VOID"); cout<<(yyvsp[0].symbol_info)->key<<"\n"<<endl; (yyval. helper )->text = (yyvsp[0].symbol_info)->key;}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 491 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("declaration_list","declaration_list COMMA ID");
                    
                    (yyval. helper ) = new Helper();

                    // update text
                    (yyval. helper )->text = (yyvsp[-2]. helper )->text;
                    (yyval. helper )->text += ",";
                    (yyval. helper )->text += (yyvsp[0].symbol_info)->key;

                    // update type
                    (yyval. helper )->HelperType = (yyvsp[-2]. helper )->HelperType;

                    // init update vector
                    (yyval. helper )->v = (yyvsp[-2]. helper )->v;
                    (yyval. helper )->v.push_back((yyvsp[0].symbol_info));
                    (yyval. helper )->print();

                    print_log_text((yyval. helper )->text);
            }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 511 "demo.y" /* yacc.c:1646  */
    {
               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-5]. helper )->text;
                (yyval. helper )->text += ",";
                (yyval. helper )->text += (yyvsp[-3].symbol_info)->key;
                (yyval. helper )->text += "[";
                (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                (yyval. helper )->text += "]";

                // update type
                (yyval. helper )->HelperType = (yyvsp[-5]. helper )->HelperType;

                // init & update vector
                (yyval. helper )->v = (yyvsp[-5]. helper )->v;
                (yyvsp[-3].symbol_info)->setVarType("array");
                (yyval. helper )->v.push_back((yyvsp[-3].symbol_info));
                (yyval. helper )->print();

                print_log_text((yyval. helper )->text);
           }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 535 "demo.y" /* yacc.c:1646  */
    {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                ***/

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-5]. helper )->text;
                (yyval. helper )->text += ",";
                (yyval. helper )->text += (yyvsp[-3].symbol_info)->key;
                (yyval. helper )->text += "[";
                (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                (yyval. helper )->text += "]";

                // update type
                (yyval. helper )->HelperType = (yyvsp[-5]. helper )->HelperType;

                // int & update vector
                (yyval. helper )->v = (yyvsp[-5]. helper )->v;
                (yyvsp[-3].symbol_info)->setVarType("array");
                (yyval. helper )->v.push_back((yyvsp[-3].symbol_info));
                (yyval. helper )->print();

                error_array_size_float();

                print_log_text((yyval. helper )->text);
           
            }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 567 "demo.y" /* yacc.c:1646  */
    {     
                    print_grammar_rule("declaration_list","ID");

                    (yyval. helper ) = new Helper();

                    // update text
                    (yyval. helper )->text = (yyvsp[0].symbol_info)->key;

                    // init vector
                    (yyval. helper )->v.push_back((yyvsp[0].symbol_info));

                    print_log_text((yyval. helper )->text);

            }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 581 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_INT RTHIRD");

                    (yyval. helper ) = new Helper();

                    // update text
                    (yyval. helper )->text = (yyvsp[-3].symbol_info)->key;
                    (yyval. helper )->text += "[";
                    (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                    (yyval. helper )->text += "]";

                    // init vector
                    (yyvsp[-3].symbol_info)->setVarType("array");
                    (yyval. helper )->v.push_back((yyvsp[-3].symbol_info));
                    cout<<"PRINT"<<endl;
                    (yyval. helper )->print();

                    print_log_text((yyval. helper )->text);
            }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 601 "demo.y" /* yacc.c:1646  */
    {

                    /***
                        THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    ***/

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_FLOAT RTHIRD");

                    (yyval. helper ) = new Helper();

                    // update text
                    (yyval. helper )->text = (yyvsp[-3].symbol_info)->key;
                    (yyval. helper )->text += "[";
                    (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                    (yyval. helper )->text += "]";

                    // init vector
                    (yyval. helper )->v.push_back((yyvsp[-3].symbol_info));

                    error_array_size_float();

                    print_log_text((yyval. helper )->text);


           }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 628 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statement");
            
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = (yyvsp[0]. helper )->text;
            print_log_text((yyval. helper )->text); 
        }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 635 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements statement");
        
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += "\n";
            (yyval. helper )->text += (yyvsp[0]. helper )->text;

            print_log_text((yyval. helper )->text); 
        }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 647 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","var_declaration");
    
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = (yyvsp[0]. helper )->text;
            print_log_text((yyval. helper )->text);
        }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 654 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","expression_statement");
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = (yyvsp[0]. helper )->text;
            print_log_text((yyval. helper )->text);
        }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 660 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","compound_statement");
        }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 663 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");
        }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 666 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
            
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = "if";
            (yyval. helper )->text += "(";
            (yyval. helper )->text += (yyvsp[-2]. helper )->text;
            (yyval. helper )->text += ")";
            (yyval. helper )->text += (yyvsp[0]. helper )->text;

            print_log_text((yyval. helper )->text);

        }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 679 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");
        
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = "if";
            (yyval. helper )->text += "(";
            (yyval. helper )->text += (yyvsp[-4]. helper )->text;
            (yyval. helper )->text += ")";
            (yyval. helper )->text += (yyvsp[-2]. helper )->text;
            (yyval. helper )->text += "else ";
            (yyval. helper )->text += (yyvsp[0]. helper )->text;

            print_log_text((yyval. helper )->text);
        
        }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 695 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");
        }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 698 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");
        }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 701 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","RETURN expression SEMICOLON");

            (yyval. helper ) = new Helper();
            (yyval. helper )->text = "return";
            (yyval. helper )->text += " ";
            (yyval. helper )->text += (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += ";";

            print_log_text((yyval. helper )->text);
        }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 714 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","SEMICOLON");
                }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 717 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    
                    (yyval. helper ) = new Helper();

                    // update text
                    (yyval. helper )->text = (yyvsp[-1]. helper )->text;
                    (yyval. helper )->text += ";";

                    print_log_text((yyval. helper )->text);
                }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 730 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("variable","ID");
            (yyval. helper ) = new Helper();

            // update text
            (yyval. helper )->text = (yyvsp[0].symbol_info)->key;

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[0].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[0].symbol_info)->key);
                (yyval. helper )->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int_array" || ret_symbol->var_type == "float_array")
                {
                   error_type_mismatch();
                }

                 (yyval. helper )->setHelperType(ret_symbol->var_type);
            }

            print_log_text((yyval. helper )->text);
        }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 757 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("variable","ID LTHIRD expression RTHIRD");
            
            (yyval. helper ) = new Helper();

            // update text
            (yyval. helper )->text = (yyvsp[-3].symbol_info)->key;
            (yyval. helper )->text += "[";
            (yyval. helper )->text += (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += "]";

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-3].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[-3].symbol_info)->key);
                (yyval. helper )->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int" || ret_symbol->var_type == "float")
                {
                   error_type_mismatch();
                }

                (yyval. helper )->setHelperType(ret_symbol->var_type);
                cout<<"HelperType : "<<(yyval. helper )->HelperType<<endl;
            }

            if((yyvsp[-1]. helper )->HelperType != "int")
            {
                error_array_index_float();
            }

            print_log_text((yyval. helper )->text);
         }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 796 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("expression","logic_expression");

                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[0]. helper )->text;
                // update vector : push up
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                print_log_text((yyval. helper )->text);
            }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 807 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("expression","variable ASSIGNOP logic_expression");
                
                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[-2]. helper )->text;
                (yyval. helper )->text += "=";
                (yyval. helper )->text += (yyvsp[0]. helper )->text;

                //check error
                if(!check_assignop((yyvsp[-2]. helper )->HelperType,(yyvsp[0]. helper )->HelperType))
                {
                    cout<<(yyvsp[-2]. helper )->HelperType<<" ---- "<<(yyvsp[0]. helper )->HelperType<<endl;
                    error_type_mismatch();
                }

                print_log_text((yyval. helper )->text);
            }
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 830 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("logic_expression","rel_expression");

                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[0]. helper )->text;
                // update vector : push up
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                print_log_text((yyval. helper )->text);
            }
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 841 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("logic_expression","rel_expression LOGICOP rel_expression");
                
                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[-2]. helper )->text;
                (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                (yyval. helper )->text += (yyvsp[0]. helper )->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast((yyvsp[-2]. helper )->HelperType,(yyvsp[0]. helper )->HelperType);
                if(typecast_ret != "error") (yyval. helper )->setHelperType("int"); // ALWAYS INT
                else error_type_cast();
                cout<<"Implicit Typecast : "<<(yyval. helper )->HelperType<<"\n"<<endl;
                
                print_log_text((yyval. helper )->text);
            }
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 860 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("rel_expression","simple_expression");

                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[0]. helper )->text;
                // update vector : push up
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                print_log_text((yyval. helper )->text);
            }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 871 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("rel_expression","simple_expression RELOP simple_expression");
                
                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[-2]. helper )->text;
                (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                (yyval. helper )->text += (yyvsp[0]. helper )->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast((yyvsp[-2]. helper )->HelperType,(yyvsp[0]. helper )->HelperType);
                if(typecast_ret != "error") (yyval. helper )->setHelperType("int"); // ALWAYS INT
                else error_type_cast();
                cout<<"Implicit Typecast : "<<(yyval. helper )->HelperType<<"\n"<<endl;

                print_log_text((yyval. helper )->text);
            }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 890 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("simple_expression","term");

                    (yyval. helper ) = new Helper();
                    // update text
                    (yyval. helper )->text = (yyvsp[0]. helper )->text;
                    // update vector : push up
                    (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                    print_log_text((yyval. helper )->text);
            }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 902 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("simple_expression","simple_expression ADDOP term");

                    (yyval. helper ) = new Helper();
                    // update text
                    (yyval. helper )->text = (yyvsp[-2]. helper )->text;
                    (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
                    (yyval. helper )->text += (yyvsp[0]. helper )->text;
                    // do implicit typecast
                    string typecast_ret = do_implicit_typecast((yyvsp[-2]. helper )->HelperType,(yyvsp[0]. helper )->HelperType);
                    if(typecast_ret != "error") (yyval. helper )->setHelperType(typecast_ret);
                    else error_type_cast();
                    cout<<"Implicit Typecast : "<<(yyval. helper )->HelperType<<"\n"<<endl;

                    print_log_text((yyval. helper )->text);
            }
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 920 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("term","unary_expression");

            (yyval. helper ) = new Helper();
            // update text
            (yyval. helper )->text = (yyvsp[0]. helper )->text;
            // update vector : push up
            (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

            print_log_text((yyval. helper )->text);
    }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 932 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("term","term MULOP unary_expression");

            (yyval. helper ) = new Helper();
            // update text
            (yyval. helper )->text = (yyvsp[-2]. helper )->text;
            (yyval. helper )->text += (yyvsp[-1].symbol_info)->key;
            (yyval. helper )->text += (yyvsp[0]. helper )->text;
            // implicit typecast
            string typecast_ret = do_implicit_typecast((yyvsp[-2]. helper )->HelperType,(yyvsp[0]. helper )->HelperType);

            if((yyvsp[-1].symbol_info)->key == "%") // both operand should be integer
            {
                if(typecast_ret != "int")
                {
                    error_type_cast_mod();
                }
            }
            else
            {
                if(typecast_ret != "error") (yyval. helper )->setHelperType(typecast_ret);
                else error_type_cast();
                cout<<"Implicit Typecast : "<<(yyval. helper )->HelperType<<"\n"<<endl;
            }

            print_log_text((yyval. helper )->text);
    }
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 962 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("unary_expression","ADDOP unary_expression");
                
                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[-1].symbol_info)->key;
                (yyval. helper )->text += (yyvsp[0]. helper )->text;
                // implicit typecast
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                print_log_text((yyval. helper )->text);
            }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 974 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("unary_expression","NOT unary_expression");
                
                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = "!";
                (yyval. helper )->text += (yyvsp[0]. helper )->text;
                // implicit typecast
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                print_log_text((yyval. helper )->text);
            }
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 986 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("unary_expression","factor");
                
                (yyval. helper ) = new Helper();
                // update text
                (yyval. helper )->text = (yyvsp[0]. helper )->text;
                // implicit typecast
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

                print_log_text((yyval. helper )->text);
            }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 999 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","variable");

            (yyval. helper ) = new Helper();
            // update text
            (yyval. helper )->text = (yyvsp[0]. helper )->text;
            // implicit typecast
            (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;

            print_log_text((yyval. helper )->text);
        }
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1011 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","ID LPAREN argument_list RPAREN");

            (yyval. helper ) = new Helper();
            // update text
            (yyval. helper )->text = (yyvsp[-3].symbol_info)->key;
            (yyval. helper )->text += "( ";
            (yyval. helper )->text += (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += " )";

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-3].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[-3].symbol_info)->key);
                (yyval. helper )->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->isFunction == false)
                {
                    (yyval. helper )->setHelperType("NULL");
                    cout<<"Error : Not a function"<<endl;
                    break;
                }


                (yyval. helper )->setHelperType(ret_symbol->var_type);

                if(ret_symbol->isFunctionDeclaration) // only declared , no definition
                {
                    cout<<"Error : Function not implemented"<<endl;
                }
                else // other errors
                {
                    // printing function param_list
                    cout<<"OG Param : ";
                    for(auto s:ret_symbol->param_v)
                    {
                        cout<<s<<" , ";
                    }
                    cout<<endl;

                    // printing argument_list
                    cout<<"Called Args : ";
                    for(auto s:(yyvsp[-1]. helper )->param_v)
                    {
                        cout<<s<<" , ";
                    }
                    cout<<endl;

                    if(ret_symbol->param_v.size() != (yyvsp[-1]. helper )->param_v.size())
                    {
                        cout<<"Error : Parameter number conflict"<<endl;
                    }
                    else
                    {
                        for(int i=0;i<ret_symbol->param_v.size();i++)
                        {
                            if(!is_param_typecast_ok(ret_symbol->param_v[i],(yyvsp[-1]. helper )->param_v[i])){
                                cout<<"Error : Parameter type conflict"<<endl;
                                break;
                            }
                        }
                    }
                }
            }

            print_log_text((yyval. helper )->text);
        }
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1083 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            (yyval. helper ) = new Helper();
            // update text
            (yyval. helper )->text = "(";
            (yyval. helper )->text += (yyvsp[-1]. helper )->text;
            (yyval. helper )->text += ")";

            print_log_text((yyval. helper )->text);
        
        }
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1096 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("factor","CONST_INT");

            // update text
            (yyval. helper ) = new Helper();
            (yyval. helper )->text = (yyvsp[0].symbol_info)->key;

            // pass up
            (yyval. helper )->setHelperType("int");

            print_log_text((yyval. helper )->text);
        }
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1108 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("factor","CONST_FLOAT");

            (yyval. helper ) = new Helper();
            // update text
            (yyval. helper )->text = (yyvsp[0].symbol_info)->key;
            // pass up
            (yyval. helper )->setHelperType("float");

            print_log_text((yyval. helper )->text);
        }
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1119 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable INCOP");
        }
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1122 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable DECOP");
        }
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1127 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("argument_list","arguments");

                    (yyval. helper ) = new Helper();
                    (yyval. helper )->text = (yyvsp[0]. helper )->text;

                    (yyval. helper )->param_v = (yyvsp[0]. helper )->param_v; 

                    print_log_text((yyval. helper )->text);
                }
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1138 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("argument_list","");
                (yyval. helper ) = new Helper();
            }
#line 2773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1144 "demo.y" /* yacc.c:1646  */
    {

                print_grammar_rule("arguments","arguments COMMA logic_expression");
                
                (yyval. helper ) = new Helper();
                (yyval. helper )->text = (yyvsp[-2]. helper )->text; 
                (yyval. helper )->text += " , "; 
                (yyval. helper )->text += (yyvsp[0]. helper )->text;

                // update vector
                (yyval. helper )->param_v = (yyvsp[-2]. helper )->param_v; 
                (yyval. helper )->param_v.push_back((yyvsp[-2]. helper )->HelperType);

                print_log_text((yyval. helper )->text);
            }
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1159 "demo.y" /* yacc.c:1646  */
    {

                print_grammar_rule("arguments","logic_expression");

                (yyval. helper ) = new Helper();

                // update text
                (yyval. helper )->text = (yyvsp[0]. helper )->text; 
                // update helper type
                (yyval. helper )->HelperType = (yyvsp[0]. helper )->HelperType;
                // init vector
                (yyval. helper )->param_v.push_back((yyvsp[0]. helper )->HelperType);

                print_log_text((yyval. helper )->text);

            }
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2818 "y.tab.c" /* yacc.c:1646  */
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
#line 1177 "demo.y" /* yacc.c:1906  */


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
