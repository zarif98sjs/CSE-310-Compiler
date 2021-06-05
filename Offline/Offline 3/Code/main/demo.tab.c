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

ofstream logout;
ofstream errout;

// #define YYSTYPE SymbolInfo*

extern FILE *yyin;

void yyerror(string s){
	cout<<s<<"\n"<<endl;
}

int yyparse(void);
int yylex(void);

extern int line_count;
int err_count = 0;

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
    if(left_op == "NULL" || right_op == "NULL") return "NULL"; // already reported , now supressing more errors

    if(left_op == "void" || right_op == "void") return "error";

    if((left_op == "float" || left_op == "float_array") && (right_op == "float" || right_op == "float_array")) return "float";
    if((left_op == "float" || left_op == "float_array") && (right_op == "int" || right_op == "int_array")) return "float";
    if((left_op == "int" || left_op=="int_array") && (right_op == "float" || right_op == "float_array")) return "float";
    if((left_op == "int" || left_op=="int_array") && (right_op == "int" || right_op == "int_array")) return "int";

    return "error";
}

bool is_param_typecast_ok(string og_p,string pass_p)
{
    if(pass_p == "NULL") return true; // already error reported and converted to NULL , this is made true to supress more error

    if(og_p == "void") return pass_p == "void";
    if(og_p == "int") return (pass_p == "int" || pass_p == "int_array");
    if(og_p == "float") return pass_p != "void";
}

bool check_assignop(string left_op,string right_op)
{
    if(left_op == "NULL" || right_op == "NULL") return true; // already error reported and converted to NULL , this is made true to supress more error

    if(left_op == "void" || right_op == "void") return false;
    if(left_op == "" || right_op == "") return false;

    if((left_op == "int" || left_op == "int_array") && (right_op == "int" || right_op == "int_array") ) return true;
    
    if((left_op == "float" || left_op == "float_array") && (right_op != "void") )return true;

    return false;
}

void print_grammar_rule(string left_part,string right_part)
{
    cout<<"Line "<<line_count<<": "<<left_part<<" : "<<right_part<<"\n"<<endl; 
}

void print_log_text(string log_text)
{
    cout<<log_text<<"\n"<<endl;
}

void error_multiple_declaration(string error_symbol)
{
    cout<<"Error at line "<<line_count<<": Multiple declaration of "<<error_symbol<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Multiple declaration of "<<error_symbol<<"\n"<<endl;
    err_count++;
}

void error_array_size_float()
{
    cout<<"Error at line "<<line_count<<": Non-integer Array Size\n"<<endl;
    errout<<"Error at line "<<line_count<<": Non-integer Array Size\n"<<endl;
    err_count++;
}

void error_array_index_invalid()
{
    cout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer\n"<<endl;
    errout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer\n"<<endl;
    err_count++;
}

void error_type_cast()
{
    cout<<"Error at line "<<line_count<<": Incompatible Operand\n"<<endl;
    errout<<"Error at line "<<line_count<<": Incompatible Operand\n"<<endl;
    err_count++;
}

void error_type_cast_mod()
{
    cout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator\n"<<endl;
    errout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator\n"<<endl;
    err_count++;
}

void error_undeclared_variable(string var_name)
{
    cout<<"Error at line "<<line_count<<": Undeclared variable "<<var_name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Undeclared variable "<<var_name<<"\n"<<endl;
    err_count++;
}

void error_undeclared_function(string var_name)
{
    cout<<"Error at line "<<line_count<<": Undeclared function "<<var_name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Undeclared function "<<var_name<<"\n"<<endl;
    err_count++;
}

void error_type_mismatch(string msg="")
{
    cout<<"Error at line "<<line_count<<": Type Mismatch "<<msg<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Type Mismatch "<<msg<<"\n"<<endl;
    err_count++;
}

void error_function_parameter_type(int param_id,string extra_s="")
{
    cout<<"Error at line "<<line_count<<": "<<param_id<<"th argument mismatch in function "<<extra_s<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<param_id<<"th argument mismatch in function "<<extra_s<<"\n"<<endl;
    err_count++;
}

void error_function_parameter_number(string name,bool declaration_definition_clash = false)
{
    if(declaration_definition_clash){
        cout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<name<<"\n"<<endl;
        errout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<name<<"\n"<<endl;
    }
    else{
        cout<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<name<<"\n"<<endl;
        errout<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<name<<"\n"<<endl;
    }

    err_count++;
}

void error_function_not_implemented()
{
    cout<<"Error at line "<<line_count<<": Function not implemented\n"<<endl;
    errout<<"Error at line "<<line_count<<": Function not implemented\n"<<endl;
    err_count++;
}

void error_function_return_condflict(string name)
{
    cout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<name<< "\n"<<endl;
    err_count++;
}


void error_not_function(string f_name)
{
    cout<<"Error at line "<<line_count<<": "<<f_name<<" not a function\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<f_name<<" not a function\n"<<endl;
    err_count++;
}

void error_var_type()
{
    cout<<"Error at line "<<line_count<<": Variable type cannot be void\n"<<endl;
    errout<<"Error at line "<<line_count<<": Variable type cannot be void\n"<<endl;
    err_count++;
}

void error_not_array(string name)
{
    cout<<"Error at line "<<line_count<<": "<<name<<" not an array\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<name<<" not an array\n"<<endl;
    err_count++;
}

///////////////////////////////////////////

void insert_function_to_global(SymbolInfo* temp_s,string var_type)
{
    // insert function ID to SymbolTable with VAR_TYPE
    temp_s->setVarType(var_type);
    temp_s->isFunction = true;

    // update parameter type
    for(auto temp_p : function_params)
    {
        temp_s->param_v.push_back(temp_p.var_type);
    }

    if(!sym_tab->insert_symbol(*temp_s))
    {
        SymbolInfo* ret_symbol = sym_tab->lookup(temp_s->key);

        if(ret_symbol->isFunctionDeclaration == false){
            error_multiple_declaration(temp_s->key);
        }
        else{

            // declared before , now definition happening

            // check if any clash between declaration and definition

            if(ret_symbol->var_type != temp_s->var_type)
            {
                error_function_return_condflict(temp_s->key);
            }

            if(ret_symbol->param_v.size() != temp_s->param_v.size())
            {
                error_function_parameter_number(temp_s->key,true);
            }
            else
            {
                for(int i=0;i<ret_symbol->param_v.size();i++)
                {
                    if(ret_symbol->param_v[i] != temp_s->param_v[i]){
                        error_function_parameter_type(i+1,temp_s->key);
                        break;
                    }
                }
            }

            // the following line is commented out because in case of clash , use the declaration info 
            // ret_symbol->param_v = $2->param_v;
            ret_symbol->isFunctionDeclaration = false; // declaration + 
        }

        // cout<<"Dec -> "<<ret_symbol->key<<" :: "<<ret_symbol->isFunctionDeclaration<<endl;
    }
    else{

        // Finalizing Definition

        SymbolInfo* ret_symbol = sym_tab->lookup(temp_s->key);
        ret_symbol->isFunctionDeclaration = false;
        // cout<<"Dec ->> "<<ret_symbol->key<<" :: "<<ret_symbol->isFunctionDeclaration<<endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  FREE   MEMORY /////////////////////////////////////////

void erm_s(SymbolInfo* s) // erase memory of SymbolInfo pointer
{
    if(s!=NULL) free(s);
}

void erm_h(Helper* h) // erase memory of Helper pointer
{
    if(h!=NULL) free(h);
}



#line 358 "demo.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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

#line 389 "demo.tab.c" /* yacc.c:355  */

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
#line 299 "demo.y" /* yacc.c:355  */

    SymbolInfo* symbol_info;
    // SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    Helper* helper;
    // int ival;
    // double dval;

#line 451 "demo.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 468 "demo.tab.c" /* yacc.c:358  */

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
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

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
       0,   331,   331,   346,   358,   370,   379,   388,   399,   442,
     490,   524,   566,   566,   589,   589,   618,   618,   645,   645,
     679,   701,   728,   747,   772,   790,   809,   828,   848,   867,
     886,   901,   920,   954,   992,  1002,  1012,  1024,  1047,  1076,
    1104,  1138,  1174,  1214,  1229,  1252,  1280,  1290,  1302,  1317,
    1327,  1337,  1347,  1364,  1379,  1398,  1413,  1427,  1440,  1456,
    1464,  1479,  1511,  1555,  1568,  1593,  1606,  1636,  1649,  1679,
    1693,  1723,  1737,  1782,  1797,  1811,  1826,  1840,  1914,  1931,
    1945,  1958,  1969,  1982,  1995,  2001,  2018
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "unit", "func_declaration", "func_definition", "$@1", "$@2", "$@3",
  "$@4", "parameter_list", "compound_statement", "dummy_scope_function",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,  -104,  -104,  -104,    25,    26,  -104,  -104,  -104,  -104,
       2,  -104,  -104,    -6,    16,     7,   -10,    41,    30,  -104,
      32,    42,    33,    47,    54,    65,    63,  -104,    48,    66,
    -104,    70,   -13,    76,    26,  -104,  -104,  -104,    73,    34,
    -104,    70,  -104,  -104,    86,    26,  -104,    70,    91,    45,
      95,    99,  -104,    79,  -104,    70,    97,  -104,  -104,   101,
     106,  -104,  -104,   181,   107,   117,   127,    68,   133,   136,
     136,  -104,  -104,    -3,   136,  -104,  -104,  -104,  -104,   126,
     113,  -104,  -104,    44,   131,  -104,   124,    31,   128,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   147,   136,   102,   136,
    -104,   138,   132,    69,  -104,   142,   136,   136,  -104,   156,
     215,  -104,  -104,  -104,  -104,   136,  -104,   136,   136,   136,
     136,   249,  -104,   150,   102,   160,  -104,   166,  -104,  -104,
     167,   163,   165,  -104,  -104,  -104,  -104,   128,   161,  -104,
     249,   136,   249,   168,  -104,   136,  -104,   190,   173,  -104,
    -104,  -104,   249,   249,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    35,    36,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    43,     0,     0,     0,     0,     0,    32,
       0,    16,     0,    25,     0,     0,     0,    33,    37,    18,
      10,     0,     0,    12,     0,    24,    44,    45,    38,     0,
      11,     0,    31,    17,    14,     0,     8,     0,    22,     0,
       0,     0,    19,     0,     9,     0,    23,    13,    20,     0,
       0,    39,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    59,    61,     0,    79,    80,    51,    49,     0,
       0,    46,    50,    76,     0,    63,    65,    67,    69,    71,
      75,    15,    21,    40,    42,    30,     0,     0,     0,     0,
      58,     0,     0,    76,    74,     0,    84,     0,    73,    43,
       0,    26,    47,    81,    82,     0,    60,     0,     0,     0,
       0,     0,    29,     0,     0,     0,    57,     0,    78,    86,
       0,    83,     0,    28,    48,    64,    66,    70,    68,    72,
       0,     0,     0,     0,    77,     0,    62,    53,     0,    55,
      56,    85,     0,     0,    54,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,   194,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,   -20,  -104,    13,     9,  -104,   137,   -74,   -72,   -69,
     -66,  -103,    84,    85,    89,   -67,  -104,  -104,  -104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    47,    55,    31,    41,
      22,    77,    53,    78,    79,    14,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   130,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     103,   101,   104,   129,   105,   103,   112,   108,    20,    10,
      44,    43,   135,     9,    10,    45,    15,    17,     9,   106,
      16,    52,   112,   107,    23,    11,   124,    57,    24,    25,
      21,   123,    13,   125,    32,    91,   134,   103,     1,     2,
       3,   132,   151,    48,    18,    19,   103,   134,   103,   103,
     103,   103,   141,   139,    56,    29,    33,     1,     2,     3,
      28,    34,   113,   114,   115,   118,   147,   119,   149,    26,
      27,    30,    50,    51,    39,   148,   103,    35,   154,   155,
      63,    36,    64,    59,    60,    65,    66,   113,   114,    69,
      70,    67,    37,    38,    42,    40,    68,   100,    73,    49,
      69,    70,    74,    42,    71,    46,    75,    76,    72,    73,
       1,     2,     3,    74,   110,    54,    64,    75,    76,    65,
      66,    58,    61,    69,    70,    67,    62,    92,    93,    97,
      68,    72,    73,    94,    69,    70,    74,    42,   111,    98,
      75,    76,    72,    73,     1,     2,     3,    74,   121,    99,
      64,    75,    76,    65,    66,   102,   109,    69,    70,    67,
     116,   117,   127,   120,    68,   128,    73,   126,    69,    70,
      74,    42,   122,   140,    75,    76,    72,    73,     1,     2,
       3,    74,    16,   142,    64,    75,    76,    65,    66,   143,
     144,   145,   146,    67,   152,   118,   153,   150,    68,    12,
      96,   136,    69,    70,   138,    42,    95,   137,     0,     0,
      72,    73,     1,     2,     3,    74,     0,     0,    64,    75,
      76,    65,    66,     0,     0,     0,     0,    67,     0,     0,
       0,     0,    68,     0,     0,     0,    69,    70,     0,    42,
     133,     0,     0,     0,    72,    73,     1,     2,     3,    74,
       0,     0,    64,    75,    76,    65,    66,     0,     0,     0,
       0,    67,     0,     0,     0,     0,    68,     0,     0,     0,
      69,    70,     0,    42,     0,     0,     0,     0,    72,    73,
       1,     2,     3,    74,     0,     0,     0,    75,    76
};

static const yytype_int16 yycheck[] =
{
      69,    67,    69,   106,    70,    74,    80,    74,     1,     0,
      23,    31,   115,     0,     5,    28,    22,     1,     5,    22,
      26,    41,    96,    26,    15,     0,    98,    47,    38,    39,
      23,    97,    30,    99,     1,    55,   110,   106,    31,    32,
      33,   107,   145,    34,    28,    29,   115,   121,   117,   118,
     119,   120,   124,   120,    45,    23,    23,    31,    32,    33,
      30,    28,    18,    19,    20,    34,   140,    36,   142,    28,
      29,    29,    38,    39,    26,   141,   145,    30,   152,   153,
       1,    27,     3,    38,    39,     6,     7,    18,    19,    21,
      22,    12,    27,    30,    24,    29,    17,    29,    30,    26,
      21,    22,    34,    24,    25,    29,    38,    39,    29,    30,
      31,    32,    33,    34,     1,    29,     3,    38,    39,     6,
       7,    30,    27,    21,    22,    12,    27,    30,    27,    22,
      17,    29,    30,    27,    21,    22,    34,    24,    25,    22,
      38,    39,    29,    30,    31,    32,    33,    34,     1,    22,
       3,    38,    39,     6,     7,    22,    30,    21,    22,    12,
      29,    37,    30,    35,    17,    23,    30,    29,    21,    22,
      34,    24,    25,    23,    38,    39,    29,    30,    31,    32,
      33,    34,    26,    23,     3,    38,    39,     6,     7,    23,
      23,    28,    27,    12,     4,    34,    23,    29,    17,     5,
      63,   117,    21,    22,   119,    24,    25,   118,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,     3,    38,
      39,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    -1,     3,    38,    39,     6,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      21,    22,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    41,    42,    43,    44,    45,    53,
      54,     0,    43,    30,    55,    22,    26,     1,    28,    29,
       1,    23,    50,    54,    38,    39,    28,    29,    30,    23,
      29,    48,     1,    23,    28,    30,    27,    27,    30,    26,
      29,    49,    24,    51,    23,    28,    29,    46,    54,    26,
      38,    39,    51,    52,    29,    47,    54,    51,    30,    38,
      39,    27,    27,     1,     3,     6,     7,    12,    17,    21,
      22,    25,    29,    30,    34,    38,    39,    51,    53,    54,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    51,    30,    27,    27,    25,    56,    22,    22,    22,
      29,    60,    22,    59,    65,    60,    22,    26,    65,    30,
       1,    25,    57,    18,    19,    20,    29,    37,    34,    36,
      35,     1,    25,    60,    58,    60,    29,    30,    23,    61,
      67,    68,    60,    25,    57,    61,    62,    64,    63,    65,
      23,    58,    23,    23,    23,    28,    27,    57,    60,    57,
      29,    61,     4,    23,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      44,    44,    46,    45,    47,    45,    48,    45,    49,    45,
      50,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    52,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     7,
       5,     6,     0,     7,     0,     8,     0,     6,     0,     7,
       4,     5,     3,     4,     2,     1,     4,     3,     5,     5,
       4,     0,     3,     4,     1,     1,     1,     3,     4,     6,
       7,     6,     7,     1,     4,     4,     1,     2,     3,     1,
       1,     1,     7,     5,     7,     5,     5,     3,     2,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
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
  switch (yytype)
    {
          case 30: /* ID  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1426 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 31: /* INT  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1432 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 32: /* FLOAT  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1438 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 33: /* VOID  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1444 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 34: /* ADDOP  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1450 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 35: /* MULOP  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1456 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 36: /* RELOP  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1462 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 37: /* LOGICOP  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1468 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 38: /* CONST_INT  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1474 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 39: /* CONST_FLOAT  */
#line 322 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info)); cout<<"Destructor SymbolInfo"<<endl; }
#line 1480 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 41: /* start  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1486 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 42: /* program  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1492 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 43: /* unit  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1498 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 44: /* func_declaration  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1504 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 45: /* func_definition  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1510 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* parameter_list  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1516 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* compound_statement  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1522 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 53: /* var_declaration  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1528 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* type_specifier  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1534 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* declaration_list  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1540 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* statements  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1546 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* statement  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1552 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* expression_statement  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1558 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* variable  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1564 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* expression  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1570 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* logic_expression  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1576 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* rel_expression  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1582 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* simple_expression  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1588 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* term  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1594 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* unary_expression  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1600 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* factor  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1606 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* argument_list  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1612 "demo.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* arguments  */
#line 321 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper)); cout<<"Destructor Helper"<<endl; }
#line 1618 "demo.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
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
#line 332 "demo.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below

        print_grammar_rule("start","program");

        (yyval.helper) = new Helper();
        (yyval.helper)->text = (yyvsp[0].helper)->text;

        // print_log_text($$->text);
        
        erm_h((yyvsp[0].helper));
	}
#line 1893 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 346 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("program","program unit");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 

            erm_h((yyvsp[-1].helper)); erm_h((yyvsp[0].helper));
        }
#line 1910 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 358 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("program","unit");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 

            erm_h((yyvsp[0].helper));
        }
#line 1925 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 370 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","var_declaration"); 

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 
            erm_h((yyvsp[0].helper)); 
        }
#line 1939 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 379 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","func_declaration"); 

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyvsp[0].helper)->text);  
            erm_h((yyvsp[0].helper)); 
        }
#line 1953 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 388 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","func_definition");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyvsp[0].helper)->text); 
            erm_h((yyvsp[0].helper)); 
        }
#line 1967 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 399 "demo.y" /* yacc.c:1646  */
    { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-4].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += (yyvsp[-2].helper)->text;
                (yyval.helper)->text += ")";
                (yyval.helper)->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-4].symbol_info)->setVarType((yyvsp[-5].helper)->text);
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

                print_log_text((yyval.helper)->text);

                // clear param_info
                function_params.clear();

                erm_h((yyvsp[-5].helper)); erm_s((yyvsp[-4].symbol_info)) ; erm_h((yyvsp[-2].helper));
    
        }
#line 2015 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 442 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo(int x-y);
                **/
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list error RPAREN SEMICOLON");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-6].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-5].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += (yyvsp[-3].helper)->text;
                (yyval.helper)->text += ")";
                (yyval.helper)->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-5].symbol_info)->setVarType((yyvsp[-6].helper)->text);
                (yyvsp[-5].symbol_info)->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    (yyvsp[-5].symbol_info)->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*(yyvsp[-5].symbol_info)))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-5].symbol_info)->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration((yyvsp[-5].symbol_info)->key);
                }

                print_log_text((yyval.helper)->text);

                // clear param_info
                function_params.clear();

                erm_h((yyvsp[-6].helper)); erm_s((yyvsp[-5].symbol_info)) ; erm_h((yyvsp[-3].helper));
    
        }
#line 2068 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 490 "demo.y" /* yacc.c:1646  */
    { 

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-4].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-3].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += ")";
                (yyval.helper)->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-3].symbol_info)->setVarType((yyvsp[-4].helper)->text);
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

                print_log_text((yyval.helper)->text);

                function_params.clear();

                erm_h((yyvsp[-4].helper)); erm_s((yyvsp[-3].symbol_info)) ; 
            }
#line 2107 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 524 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo(-);
                **/

                print_grammar_rule("func_declaration","type_specifier ID LPAREN error RPAREN SEMICOLON");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-4].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += ")";
                (yyval.helper)->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-4].symbol_info)->setVarType((yyvsp[-5].helper)->text);
                (yyvsp[-4].symbol_info)->isFunction = true;
                
                if(sym_tab->insert_symbol(*(yyvsp[-4].symbol_info)))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-4].symbol_info)->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration((yyvsp[-4].symbol_info)->key);
                }

                print_log_text((yyval.helper)->text);

                function_params.clear();

                erm_h((yyvsp[-5].helper)); erm_s((yyvsp[-4].symbol_info)) ; 
            }
#line 2151 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 566 "demo.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-3].symbol_info),(yyvsp[-4].helper)->text);}
#line 2157 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 566 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-6].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-5].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += (yyvsp[-3].helper)->text;
                (yyval.helper)->text += ")";
                (yyval.helper)->text += (yyvsp[0].helper)->text; 

                print_log_text((yyval.helper)->text);

                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h((yyvsp[-6].helper)); erm_h((yyvsp[-3].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-5].symbol_info));
            }
#line 2185 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 589 "demo.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-4].symbol_info),(yyvsp[-5].helper)->text);}
#line 2191 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 589 "demo.y" /* yacc.c:1646  */
    { 
                
                /**
                    To handle cases like :
                        void foo(int x-y){}
                **/
                
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list error RPAREN compound_statement");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-7].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-6].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += (yyvsp[-4].helper)->text;
                (yyval.helper)->text += ")";
                (yyval.helper)->text += (yyvsp[0].helper)->text; 

                print_log_text((yyval.helper)->text);

                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h((yyvsp[-7].helper)); erm_h((yyvsp[-4].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-6].symbol_info));
        }
#line 2225 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 618 "demo.y" /* yacc.c:1646  */
    {is_function_now = true;insert_function_to_global((yyvsp[-2].symbol_info),(yyvsp[-3].helper)->text);}
#line 2231 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 618 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN RPAREN compound_statement");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-4].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += ")";
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                // insert function ID to SymbolTable with VAR_TYPE
                (yyvsp[-4].symbol_info)->setVarType((yyvsp[-5].helper)->text);
                (yyvsp[-4].symbol_info)->isFunction = true;
                sym_tab->insert_symbol(*(yyvsp[-4].symbol_info));

                print_log_text((yyval.helper)->text);
            
                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h((yyvsp[-5].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-4].symbol_info));
            }
#line 2263 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 645 "demo.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-3].symbol_info),(yyvsp[-4].helper)->text);}
#line 2269 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 645 "demo.y" /* yacc.c:1646  */
    {
                
                /**
                    To handle cases like :
                        void foo(-){}
                **/
                
                cout<<"inside func_definition syntax_error 1"<<endl;

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-6].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-5].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += ")";
                (yyval.helper)->text += (yyvsp[0].helper)->text; 

                print_log_text((yyval.helper)->text);

                // clear temp function params
                is_function_now = false;
                function_params.clear();

                yyclearin;
                yyerrok;

                erm_h((yyvsp[-6].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-5].symbol_info));
        }
#line 2305 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 679 "demo.y" /* yacc.c:1646  */
    {

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-3].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[-1].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[0].symbol_info)->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                (yyvsp[0].symbol_info)->setVarType((yyvsp[-1].helper)->text);
                function_params.push_back(*(yyvsp[0].symbol_info));

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-3].helper)); erm_h((yyvsp[-1].helper));
                erm_s((yyvsp[0].symbol_info));
            }
#line 2332 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 701 "demo.y" /* yacc.c:1646  */
    {

                /**
                    To handle errors like:
                    void foo(int x-y,int z){}
                **/

               print_grammar_rule("parameter_list","parameter_list error COMMA type_specifier ID");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-4].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[-1].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[0].symbol_info)->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                (yyvsp[0].symbol_info)->setVarType((yyvsp[-1].helper)->text);
                function_params.push_back(*(yyvsp[0].symbol_info));

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-4].helper)); erm_h((yyvsp[-1].helper));
                erm_s((yyvsp[0].symbol_info));
        }
#line 2364 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 728 "demo.y" /* yacc.c:1646  */
    {
             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-2].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
                temp_s.var_type = (yyvsp[0].helper)->text;

                function_params.push_back(temp_s);

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
        }
#line 2388 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 747 "demo.y" /* yacc.c:1646  */
    {

            /**
                To handle cases like:
                    void foo(int x-y,int);
            **/

             print_grammar_rule("parameter_list","parameter_list error COMMA type_specifier");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-3].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
                temp_s.var_type = (yyvsp[0].helper)->text;

                function_params.push_back(temp_s);

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-3].helper)); erm_h((yyvsp[0].helper));
        }
#line 2418 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 772 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("parameter_list","type_specifier ID");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-1].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[0].symbol_info)->key;

                // insert parameter ID to Parameter SymbolTable with VAR_TYPE
                (yyvsp[0].symbol_info)->setVarType((yyvsp[-1].helper)->text);
                function_params.push_back(*(yyvsp[0].symbol_info));

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-1].helper)); erm_s((yyvsp[0].symbol_info));
        }
#line 2441 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 790 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("parameter_list","type_specifier");

            (yyval.helper) = new Helper();

            // update text
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
            temp_s.var_type = (yyvsp[0].helper)->text;

            function_params.push_back(temp_s);

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 2463 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 809 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-1].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

                erm_h((yyvsp[-1].helper));

            }
#line 2487 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 828 "demo.y" /* yacc.c:1646  */
    {

                print_grammar_rule("compound_statement","LCURL statements RCURL");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n";  
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

                // // clear temp function params
                // is_function_now = false;
                // function_params.clear();
             }
#line 2512 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 848 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements error RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-2].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

                erm_h((yyvsp[-2].helper));

            }
#line 2536 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 867 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL error statements RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-1].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope();
                sym_tab->exit_scope();

                erm_h((yyvsp[-1].helper));

            }
#line 2560 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 886 "demo.y" /* yacc.c:1646  */
    {
                
                print_grammar_rule("compound_statement","LCURL error RCURL");

                (yyval.helper) = new Helper();

                 // update text
                (yyval.helper)->text = "{\n";  
                (yyval.helper)->text += "\n}";

                print_log_text((yyval.helper)->text); 

             }
#line 2578 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 901 "demo.y" /* yacc.c:1646  */
    {

                    sym_tab->enter_scope(); 

                    if(is_function_now)
                    {
                        for(auto el:function_params)
                        {
                            // insert ID
                            // cout<<"INSIDE FUNCTIONNN"<<endl;
                            if(!sym_tab->insert_symbol(el)) // already present in current scope
                            {
                                error_multiple_declaration(el.key);
                            }
                        }
                    }
                }
#line 2600 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 920 "demo.y" /* yacc.c:1646  */
    { 

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
            (yyval.helper) = new Helper();

            // update text
            (yyval.helper)->text = (yyvsp[-2].helper)->text;
            (yyval.helper)->text += " ";
            (yyval.helper)->text += (yyvsp[-1].helper)->text;
            (yyval.helper)->text += ";";

            if((yyvsp[-2].helper)->text == "void"){
                error_var_type();
            }
            else{
                // insert all declaration_list ID to SymbolTable with VAR_TYPE
                for(auto el:(yyvsp[-1].helper)->v)
                {
                    if(el->var_type == "array") el->setVarType((yyvsp[-2].helper)->text + "_array") ; 
                    else el->setVarType((yyvsp[-2].helper)->text); 
                    
                    if(!sym_tab->insert_symbol(*el)) // already present in current scope
                    {
                        error_multiple_declaration(el->key);
                    }

                }
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[-1].helper));
        }
#line 2639 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 954 "demo.y" /* yacc.c:1646  */
    { 

            /**
                To handle errors like :
                    int x-y;
                    int x[10]-y;
                    int x[10.5]-y;
            **/            

            print_grammar_rule("var_declaration","type_specifier declaration_list error SEMICOLON");
            
            (yyval.helper) = new Helper();

            // update text
            (yyval.helper)->text = (yyvsp[-3].helper)->text;
            (yyval.helper)->text += " ";
            (yyval.helper)->text += (yyvsp[-2].helper)->text;
            (yyval.helper)->text += ";";

            // insert all declaration_list ID to SymbolTable with VAR_TYPE
            for(auto el:(yyvsp[-2].helper)->v)
            {
                if(el->var_type == "array") el->setVarType((yyvsp[-3].helper)->text + "_array") ; 
                else el->setVarType((yyvsp[-3].helper)->text); 
                
                if(!sym_tab->insert_symbol(*el)) // already present in current scope
                {
                    error_multiple_declaration(el->key);
                }

            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-3].helper)); erm_h((yyvsp[-2].helper));
        }
#line 2680 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 992 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","INT"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key; 

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 2695 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1002 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","FLOAT"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key; 

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 2710 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1012 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","VOID"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 2725 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1024 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("declaration_list","declaration_list COMMA ID");
                    
                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[-2].helper)->text;
                    (yyval.helper)->text += ",";
                    (yyval.helper)->text += (yyvsp[0].symbol_info)->key;

                    // update type
                    (yyval.helper)->HelperType = (yyvsp[-2].helper)->HelperType;

                    // init update vector
                    (yyval.helper)->v = (yyvsp[-2].helper)->v;
                    (yyval.helper)->v.push_back((yyvsp[0].symbol_info));
                    // $$->print();

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[-2].helper)); 
                    // erm_s($3); // can't delete this as we will need it later to insert
            }
#line 2753 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1047 "demo.y" /* yacc.c:1646  */
    {

                /**
                To handle errors like :
                    int x-y,z;
                **/    

                print_grammar_rule("declaration_list","declaration_list error COMMA ID");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-3].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[0].symbol_info)->key;

                // update type
                (yyval.helper)->HelperType = (yyvsp[-3].helper)->HelperType;

                // init update vector
                (yyval.helper)->v = (yyvsp[-3].helper)->v;
                (yyval.helper)->v.push_back((yyvsp[0].symbol_info));
                // $$->print();

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-3].helper)); 
                // erm_s($4);
            }
#line 2787 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1076 "demo.y" /* yacc.c:1646  */
    {
               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[-3].symbol_info)->key;
                (yyval.helper)->text += "[";
                (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += "]";

                // update type
                (yyval.helper)->HelperType = (yyvsp[-5].helper)->HelperType;

                // init & update vector
                (yyval.helper)->v = (yyvsp[-5].helper)->v;
                (yyvsp[-3].symbol_info)->setVarType("array");
                (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                // $$->print();

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-5].helper)); 
                // erm_s($3); 
                erm_s((yyvsp[-1].symbol_info));
           }
#line 2820 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1104 "demo.y" /* yacc.c:1646  */
    {

               /**
                To handle errors like :
                    int x-y,z[10];
                **/  

               print_grammar_rule("declaration_list","declaration_list error COMMA ID LTHIRD CONST_INT RTHIRD");
           
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-6].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[-3].symbol_info)->key;
                (yyval.helper)->text += "[";
                (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += "]";

                // update type
                (yyval.helper)->HelperType = (yyvsp[-6].helper)->HelperType;

                // init & update vector
                (yyval.helper)->v = (yyvsp[-6].helper)->v;
                (yyvsp[-3].symbol_info)->setVarType("array");
                (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                // $$->print();

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-6].helper)); 
                // erm_s($4); 
                erm_s((yyvsp[-1].symbol_info));
           }
#line 2859 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1138 "demo.y" /* yacc.c:1646  */
    {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                ***/

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[-3].symbol_info)->key;
                (yyval.helper)->text += "[";
                (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += "]";

                // update type
                (yyval.helper)->HelperType = (yyvsp[-5].helper)->HelperType;

                // int & update vector
                (yyval.helper)->v = (yyvsp[-5].helper)->v;
                (yyvsp[-3].symbol_info)->setVarType("array");
                (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                // $$->print();

                error_array_size_float();

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-5].helper)); 
                // erm_s($3); 
                erm_s((yyvsp[-1].symbol_info));
           
            }
#line 2900 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1174 "demo.y" /* yacc.c:1646  */
    {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    
                    Also,
                    To handle errors like :
                    int x-y,z[10.5];
                ***/

               print_grammar_rule("declaration_list","declaration_list error COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-6].helper)->text;
                (yyval.helper)->text += ",";
                (yyval.helper)->text += (yyvsp[-3].symbol_info)->key;
                (yyval.helper)->text += "[";
                (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += "]";

                // update type
                (yyval.helper)->HelperType = (yyvsp[-6].helper)->HelperType;

                // int & update vector
                (yyval.helper)->v = (yyvsp[-6].helper)->v;
                (yyvsp[-3].symbol_info)->setVarType("array");
                (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                // $$->print();

                error_array_size_float();

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-6].helper)); 
                // erm_s($4); 
                erm_s((yyvsp[-1].symbol_info));
           
            }
#line 2945 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1214 "demo.y" /* yacc.c:1646  */
    {     
                    print_grammar_rule("declaration_list","ID");

                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

                    // init vector
                    (yyval.helper)->v.push_back((yyvsp[0].symbol_info));

                    print_log_text((yyval.helper)->text);

                    // erm_s($1);
            }
#line 2965 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1229 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_INT RTHIRD");

                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[-3].symbol_info)->key;
                    (yyval.helper)->text += "[";
                    (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                    (yyval.helper)->text += "]";

                    // init vector
                    (yyvsp[-3].symbol_info)->setVarType("array");
                    (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                    // cout<<"PRINT"<<endl;
                    // $$->print();

                    print_log_text((yyval.helper)->text);

                    // erm_s($1); 
                    erm_s((yyvsp[-1].symbol_info));
            }
#line 2993 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1252 "demo.y" /* yacc.c:1646  */
    {

                    /***
                        THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    ***/

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_FLOAT RTHIRD");

                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[-3].symbol_info)->key;
                    (yyval.helper)->text += "[";
                    (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                    (yyval.helper)->text += "]";

                    // init vector
                    (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));

                    error_array_size_float();

                    print_log_text((yyval.helper)->text);

                    // erm_s($1); 
                    erm_s((yyvsp[-1].symbol_info));
           }
#line 3024 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1280 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statement");
            
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));  
        }
#line 3039 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1290 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements statement");
        
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));  erm_h((yyvsp[0].helper));   
        }
#line 3056 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1302 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements error statement");
        
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-2].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper));  erm_h((yyvsp[0].helper));   
        }
#line 3073 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1317 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","var_declaration");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3088 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1327 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","expression_statement");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3103 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1337 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","compound_statement");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3118 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1347 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = "for";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-4].helper)->text;
            (yyval.helper)->text += (yyvsp[-3].helper)->text;
            (yyval.helper)->text += (yyvsp[-2].helper)->text;
            (yyval.helper)->text += ")";
            (yyval.helper)->text += (yyvsp[0].helper)->text;
            
            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-4].helper)); erm_h((yyvsp[-3].helper)); erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
        }
#line 3140 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1364 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
            
            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = "if";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-2].helper)->text;
            (yyval.helper)->text += ")";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper)); 
        }
#line 3160 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1379 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
        
            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = "if";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-4].helper)->text;
            (yyval.helper)->text += ")";
            (yyval.helper)->text += (yyvsp[-2].helper)->text;
            (yyval.helper)->text += "\nelse ";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-4].helper)); erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
        
        }
#line 3184 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1398 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = "while";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-2].helper)->text;
            (yyval.helper)->text += ")";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper)); 
        }
#line 3204 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1413 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = "printf";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-2].symbol_info)->key;
            (yyval.helper)->text += ")";
            (yyval.helper)->text += ";";

            print_log_text((yyval.helper)->text);
            
            erm_s((yyvsp[-2].symbol_info));
        }
#line 3223 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1427 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","RETURN expression SEMICOLON");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = "return";
            (yyval.helper)->text += " ";
            (yyval.helper)->text += (yyvsp[-1].helper)->text;
            (yyval.helper)->text += ";";

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper)); 
        }
#line 3241 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1440 "demo.y" /* yacc.c:1646  */
    {

            /***
                EXTRA RULE ADDED 
            ***/

            print_grammar_rule("statement","RETURN SEMICOLON");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = "return";
            (yyval.helper)->text += ";";

            print_log_text((yyval.helper)->text);
        }
#line 3260 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1456 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","SEMICOLON");

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = ";";

                    print_log_text((yyval.helper)->text);
                }
#line 3273 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1464 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    
                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[-1].helper)->text;
                    (yyval.helper)->text += ";";

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[-1].helper));
                }
#line 3291 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1479 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("variable","ID");
            (yyval.helper) = new Helper();

            // update text
            (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[0].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[0].symbol_info)->key);
                (yyval.helper)->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int_array" || ret_symbol->var_type == "float_array")
                {
                    error_type_mismatch(ret_symbol->key + " is an array"); // should i change this to indexing
                    (yyval.helper)->setHelperType("NULL");
                }
                else{
                    (yyval.helper)->setHelperType(ret_symbol->var_type);
                }
                //  cout<<"Helper : "<<$$->HelperType<<endl;
            }

            print_log_text((yyval.helper)->text);

            erm_s((yyvsp[0].symbol_info));
        }
#line 3328 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1511 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("variable","ID LTHIRD expression RTHIRD");
            
            (yyval.helper) = new Helper();

            // update text
            (yyval.helper)->text = (yyvsp[-3].symbol_info)->key;
            (yyval.helper)->text += "[";
            (yyval.helper)->text += (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "]";

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-3].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[-3].symbol_info)->key);
                (yyval.helper)->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int" || ret_symbol->var_type == "float")
                {
                    error_not_array(ret_symbol->key);
                    (yyval.helper)->setHelperType("NULL");
                }
                else{
                    (yyval.helper)->setHelperType(ret_symbol->var_type);
                }
                // cout<<"HelperType : "<<$$->HelperType<<endl;
            }

            if((yyvsp[-1].helper)->HelperType != "int")
            {
                error_array_index_invalid();
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
            erm_s((yyvsp[-3].symbol_info));
         }
#line 3375 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1555 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("expression","logic_expression");

                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // update vector : push up
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
            }
#line 3393 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1568 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("expression","variable ASSIGNOP logic_expression");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-2].helper)->text;
                (yyval.helper)->text += "=";
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                //check error
                cout<<(yyvsp[-2].helper)->HelperType<<" ---- "<<(yyvsp[0].helper)->HelperType<<endl;
                if(!check_assignop((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType))
                {
                    error_type_mismatch();
                }

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
            }
#line 3419 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1593 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("logic_expression","rel_expression");

                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // update vector : push up
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper)); 
            }
#line 3437 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1606 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("logic_expression","rel_expression LOGICOP rel_expression");
                
                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[-2].helper)->text;
                (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType);

                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") (yyval.helper)->setHelperType("int"); // ALWAYS INT
                    else error_type_cast() , (yyval.helper)->setHelperType("NULL");
                    cout<<"Implicit Typecast : "<<(yyval.helper)->HelperType<<"\n"<<endl;
                }
                else
                {
                    (yyval.helper)->setHelperType("NULL");
                }

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 3470 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1636 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("rel_expression","simple_expression");

                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // update vector : push up
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
            }
#line 3488 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1649 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("rel_expression","simple_expression RELOP simple_expression");
                
                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[-2].helper)->text;
                (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType);

                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") (yyval.helper)->setHelperType("int"); // ALWAYS INT
                    else error_type_cast() , (yyval.helper)->setHelperType("NULL");
                    cout<<"Implicit Typecast : "<<(yyval.helper)->HelperType<<"\n"<<endl;
                }
                else
                {
                    (yyval.helper)->setHelperType("NULL");
                }

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 3521 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1679 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("simple_expression","term");

                    (yyval.helper) = new Helper();
                    // update text
                    (yyval.helper)->text = (yyvsp[0].helper)->text;
                    // update vector : push up
                    (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[0].helper));
            }
#line 3540 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1693 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("simple_expression","simple_expression ADDOP term");

                    (yyval.helper) = new Helper();
                    // update text
                    (yyval.helper)->text = (yyvsp[-2].helper)->text;
                    (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                    (yyval.helper)->text += (yyvsp[0].helper)->text;
                    // do implicit typecast
                    cout<<(yyvsp[-2].helper)->HelperType<<" --- "<<(yyvsp[0].helper)->HelperType<<endl;
                    string typecast_ret = do_implicit_typecast((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType);

                    if(typecast_ret != "NULL")
                    {
                        if(typecast_ret != "error") (yyval.helper)->setHelperType(typecast_ret);
                        else error_type_cast() , (yyval.helper)->setHelperType("NULL");
                        cout<<"Implicit Typecast : "<<(yyval.helper)->HelperType<<"\n"<<endl;
                    }
                    else
                    {
                        (yyval.helper)->setHelperType("NULL");
                    }

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                    erm_s((yyvsp[-1].symbol_info));
            }
#line 3573 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1723 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("term","unary_expression");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[0].helper)->text;
            // update vector : push up
            (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
    }
#line 3592 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1737 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("term","term MULOP unary_expression");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[-2].helper)->text;
            (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
            (yyval.helper)->text += (yyvsp[0].helper)->text;
            // implicit typecast
            string typecast_ret = do_implicit_typecast((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType);

            if((yyvsp[-1].symbol_info)->key == "%") // both operand should be integer
            {
                if(typecast_ret != "int")
                {
                    error_type_cast_mod();
                    (yyval.helper)->setHelperType("NULL");
                }
                else{
                    (yyval.helper)->setHelperType("int");
                    cout<<"HERERE"<<endl;
                }
            }
            else
            {
                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") (yyval.helper)->setHelperType(typecast_ret);
                    else error_type_cast() , (yyval.helper)->setHelperType("NULL");
                    cout<<"Implicit Typecast : "<<(yyval.helper)->HelperType<<"\n"<<endl;
                }
                else
                {
                    (yyval.helper)->setHelperType("NULL");
                }
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
            erm_s((yyvsp[-1].symbol_info));
    }
#line 3640 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1782 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("unary_expression","ADDOP unary_expression");
                
                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[-1].symbol_info)->key;
                (yyval.helper)->text += (yyvsp[0].helper)->text;
                // implicit typecast
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 3660 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1797 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("unary_expression","NOT unary_expression");
                
                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = "!";
                (yyval.helper)->text += (yyvsp[0].helper)->text;
                // implicit typecast
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
            }
#line 3679 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1811 "demo.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("unary_expression","factor");
                
                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // implicit typecast
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
            }
#line 3697 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1826 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","variable");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[0].helper)->text;
            // implicit typecast
            (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3716 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1840 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","ID LPAREN argument_list RPAREN");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[-3].symbol_info)->key;
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-1].helper)->text;
            (yyval.helper)->text += ")";

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-3].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_function((yyvsp[-3].symbol_info)->key);
                (yyval.helper)->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->isFunction == false)
                {
                    (yyval.helper)->setHelperType("NULL");
                    error_not_function((yyvsp[-3].symbol_info)->key);
                    break;
                }

                (yyval.helper)->setHelperType(ret_symbol->var_type);

                if(ret_symbol->isFunctionDeclaration) // only declared , no definition
                {
                    error_function_not_implemented();
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
                    for(auto s:(yyvsp[-1].helper)->param_v)
                    {
                        cout<<s<<" , ";
                    }
                    cout<<endl;

                    if(ret_symbol->param_v.size() != (yyvsp[-1].helper)->param_v.size())
                    {
                        error_function_parameter_number(ret_symbol->key);
                    }
                    else
                    {
                        for(int i=0;i<ret_symbol->param_v.size();i++)
                        {
                            if(!is_param_typecast_ok(ret_symbol->param_v[i],(yyvsp[-1].helper)->param_v[i])){
                                error_function_parameter_type(i+1,ret_symbol->key);
                                break;
                            }
                        }
                    }
                }
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
            erm_s((yyvsp[-3].symbol_info));
        }
#line 3795 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1914 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = "(";
            (yyval.helper)->text += (yyvsp[-1].helper)->text;
            (yyval.helper)->text += ")";

            (yyval.helper)->HelperType = (yyvsp[-1].helper)->HelperType;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
        
        }
#line 3817 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1931 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("factor","CONST_INT");

            // update text
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

            // pass up
            (yyval.helper)->setHelperType("int");

            print_log_text((yyval.helper)->text);

            erm_s((yyvsp[0].symbol_info));
        }
#line 3836 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1945 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("factor","CONST_FLOAT");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[0].symbol_info)->key;
            // pass up
            (yyval.helper)->setHelperType("float");

            print_log_text((yyval.helper)->text);

            erm_s((yyvsp[0].symbol_info));
        }
#line 3854 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1958 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable INCOP");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "++";

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
        }
#line 3870 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1969 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable DECOP");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "--";

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
        }
#line 3886 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1982 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("argument_list","arguments");

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].helper)->text;

                    (yyval.helper)->param_v = (yyvsp[0].helper)->param_v; 

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[0].helper));
                }
#line 3904 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1995 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("argument_list","");
                (yyval.helper) = new Helper();
            }
#line 3913 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2001 "demo.y" /* yacc.c:1646  */
    {

                print_grammar_rule("arguments","arguments COMMA logic_expression");
                
                (yyval.helper) = new Helper();
                (yyval.helper)->text = (yyvsp[-2].helper)->text; 
                (yyval.helper)->text += ","; 
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                // update vector
                (yyval.helper)->param_v = (yyvsp[-2].helper)->param_v; 
                (yyval.helper)->param_v.push_back((yyvsp[0].helper)->HelperType);

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
            }
#line 3935 "demo.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2018 "demo.y" /* yacc.c:1646  */
    {

                print_grammar_rule("arguments","logic_expression");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text; 
                // update helper type
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;
                // cout<<"Logic Helper : "<<$$->HelperType<<endl;
                // init vector
                (yyval.helper)->param_v.push_back((yyvsp[0].helper)->HelperType);

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
            }
#line 3958 "demo.tab.c" /* yacc.c:1646  */
    break;


#line 3962 "demo.tab.c" /* yacc.c:1646  */
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
#line 2038 "demo.y" /* yacc.c:1906  */


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

    logout.open("1705010_token.txt");
	errout.open("1705010_error.txt");

    yyin=fin;
	yyparse();

    sym_tab->print_all_scope();

    cout<<"Total lines : "<<line_count<<endl;
    cout<<"Total errors : "<<err_count<<endl;

    fclose(yyin);

    logout.close();
	errout.close();

    exit(0);
}
