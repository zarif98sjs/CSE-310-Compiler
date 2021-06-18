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

extern int line_count;
int err_count = 0;

// #define YYSTYPE SymbolInfo*

extern FILE *yyin;

void yyerror(string s){
	logout<<"Error at line "<<line_count<<": "<<s<<"\n"<<endl;
	errout<<"Error at line "<<line_count<<": "<<s<<"\n"<<endl;
    err_count++;
}

int yyparse(void);
int yylex(void);



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
    logout<<"Line "<<line_count<<": "<<left_part<<" : "<<right_part<<"\n"<<endl; 
}

void print_log_text(string log_text)
{
    logout<<log_text<<"\n"<<endl;
}

void error_multiple_declaration(string error_symbol)
{
    logout<<"Error at line "<<line_count<<": Multiple declaration of "<<error_symbol<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Multiple declaration of "<<error_symbol<<"\n"<<endl;
    err_count++;
}

void error_array_size_float()
{
    logout<<"Error at line "<<line_count<<": Non-integer Array Size\n"<<endl;
    errout<<"Error at line "<<line_count<<": Non-integer Array Size\n"<<endl;
    err_count++;
}

void error_array_index_invalid()
{
    logout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer\n"<<endl;
    errout<<"Error at line "<<line_count<<": Expression inside third brackets not an integer\n"<<endl;
    err_count++;
}

void error_type_cast()
{
    logout<<"Error at line "<<line_count<<": Incompatible Operand\n"<<endl;
    errout<<"Error at line "<<line_count<<": Incompatible Operand\n"<<endl;
    err_count++;
}

void error_type_cast_void()
{
    logout<<"Error at line "<<line_count<<": Void function used in expression\n"<<endl;
    errout<<"Error at line "<<line_count<<": Void function used in expression\n"<<endl;
    err_count++;
}

void error_type_cast_mod()
{
    logout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator\n"<<endl;
    errout<<"Error at line "<<line_count<<": Non-Integer operand on modulus operator\n"<<endl;
    err_count++;
}

void error_type_cast_mod_zero()
{
    logout<<"Error at line "<<line_count<<": Modulus by Zero\n"<<endl;
    errout<<"Error at line "<<line_count<<": Modulus by Zero\n"<<endl;
    err_count++;
}

void error_undeclared_variable(string var_name)
{
    logout<<"Error at line "<<line_count<<": Undeclared variable "<<var_name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Undeclared variable "<<var_name<<"\n"<<endl;
    err_count++;
}

void error_undeclared_function(string var_name)
{
    logout<<"Error at line "<<line_count<<": Undeclared function "<<var_name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Undeclared function "<<var_name<<"\n"<<endl;
    err_count++;
}

void error_type_mismatch(string msg="")
{
    logout<<"Error at line "<<line_count<<": Type mismatch "<<msg<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Type mismatch "<<msg<<"\n"<<endl;
    err_count++;
}

void error_function_parameter_type(int param_id,string extra_s="")
{
    logout<<"Error at line "<<line_count<<": "<<param_id<<"th argument mismatch in function "<<extra_s<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<param_id<<"th argument mismatch in function "<<extra_s<<"\n"<<endl;
    err_count++;
}

void error_function_parameter_number(string name,bool declaration_definition_clash = false)
{
    if(declaration_definition_clash){
        logout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<name<<"\n"<<endl;
        errout<<"Error at line "<<line_count<<": Total number of arguments mismatch with declaration in function "<<name<<"\n"<<endl;
    }
    else{
        logout<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<name<<"\n"<<endl;
        errout<<"Error at line "<<line_count<<": Total number of arguments mismatch in function "<<name<<"\n"<<endl;
    }

    err_count++;
}

void error_function_not_implemented()
{
    logout<<"Error at line "<<line_count<<": Function not implemented\n"<<endl;
    errout<<"Error at line "<<line_count<<": Function not implemented\n"<<endl;
    err_count++;
}

void error_function_return_condflict(string name)
{
    logout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": Return type mismatch with function declaration in function "<<name<< "\n"<<endl;
    err_count++;
}


void error_not_function(string f_name)
{
    logout<<"Error at line "<<line_count<<": "<<f_name<<" not a function\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<f_name<<" not a function\n"<<endl;
    err_count++;
}

void error_nested_function()
{
    logout<<"Error at line "<<line_count<<": A function is defined inside a function\n"<<endl;
    errout<<"Error at line "<<line_count<<": A function is defined inside a function\n"<<endl;
    err_count++;
}

void error_var_type()
{
    logout<<"Error at line "<<line_count<<": Variable type cannot be void\n"<<endl;
    errout<<"Error at line "<<line_count<<": Variable type cannot be void\n"<<endl;
    err_count++;
}

void error_not_array(string name)
{
    logout<<"Error at line "<<line_count<<": "<<name<<" not an array\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<name<<" not an array\n"<<endl;
    err_count++;
}

void error_parameter_name_missing(int param_id,string func_name)
{
    logout<<"Error at line "<<line_count<<": "<<param_id<<"th parameter's name not given in function definition of "<<func_name<<"\n"<<endl;
    errout<<"Error at line "<<line_count<<": "<<param_id<<"th parameter's name not given in function definition of "<<func_name<<"\n"<<endl;
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

        for(int i=0;i<function_params.size();i++)
        {
            if(function_params[i].key == "dummy_key"){
                error_parameter_name_missing(i+1,ret_symbol->key);
            }
        }
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



#line 397 "y.tab.c" /* yacc.c:339  */

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

#line 431 "y.tab.c" /* yacc.c:355  */

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
    CONST_FLOAT = 294,
    ERROR_FLOAT = 295
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
#define ERROR_FLOAT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 338 "demo.y" /* yacc.c:355  */

    SymbolInfo* symbol_info;
    // SymbolInfo* symbol_info_vec[100];
    string* symbol_info_str;
    string* temp_str;
    Helper* helper;
    // int ival;
    // double dval;

#line 533 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 550 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   370,   370,   385,   397,   409,   418,   427,   438,   481,
     523,   571,   618,   652,   690,   729,   770,   770,   793,   793,
     822,   822,   849,   849,   883,   905,   932,   951,   976,   994,
    1013,  1032,  1052,  1071,  1090,  1105,  1126,  1160,  1198,  1208,
    1218,  1230,  1253,  1282,  1310,  1344,  1380,  1420,  1435,  1458,
    1486,  1496,  1508,  1523,  1533,  1544,  1555,  1565,  1575,  1592,
    1607,  1626,  1641,  1664,  1677,  1693,  1701,  1716,  1748,  1792,
    1805,  1837,  1850,  1893,  1906,  1948,  1962,  2004,  2018,  2083,
    2098,  2112,  2127,  2141,  2218,  2235,  2249,  2262,  2275,  2286,
    2299,  2312,  2318,  2335
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
  "LOGICOP", "CONST_INT", "CONST_FLOAT", "ERROR_FLOAT", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "$@1", "$@2",
  "$@3", "$@4", "parameter_list", "compound_statement",
  "dummy_scope_function", "var_declaration", "type_specifier",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -106

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-106)))

#define YYTABLE_NINF -23

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,  -106,  -106,  -106,    10,    67,  -106,  -106,  -106,  -106,
     -17,  -106,  -106,    -3,     8,    23,    52,    90,   -10,  -106,
       3,    24,    37,    -1,     5,    32,    38,  -106,    45,    33,
    -106,  -106,    55,   -11,    43,    67,  -106,  -106,  -106,    56,
      83,  -106,  -106,    55,  -106,  -106,    88,    67,  -106,  -106,
      55,    75,   115,    86,    96,  -106,    63,  -106,  -106,    55,
     108,  -106,  -106,    99,   124,  -106,  -106,   181,   123,   137,
     139,   118,   147,   282,   282,  -106,  -106,    85,   282,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,   103,  -106,  -106,   111,
      79,  -106,   129,    80,   135,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,   143,   282,   271,   282,  -106,   142,   148,   144,
    -106,   156,   282,   282,  -106,   219,  -106,  -106,  -106,  -106,
     282,  -106,   282,   282,   282,   282,   257,  -106,   157,   271,
     162,  -106,   163,  -106,  -106,   166,   164,   167,  -106,  -106,
    -106,  -106,   135,   161,  -106,   257,   282,   257,   168,  -106,
     282,  -106,   186,   173,  -106,  -106,  -106,   257,   257,  -106,
    -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,    39,    40,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    47,     0,     0,     0,     0,     0,    36,
       0,     0,     0,    29,     0,     0,     0,    37,    41,     0,
      13,    12,     0,     0,     0,     0,    28,    48,    49,    42,
       0,    15,    14,     0,    35,    21,     0,     0,     9,     8,
       0,    26,     0,     0,     0,    23,     0,    11,    10,     0,
      27,    17,    24,     0,     0,    43,    45,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    65,    67,     0,    85,
      86,    87,    55,    54,    57,    53,     0,    50,    56,    82,
       0,    69,    71,    73,    75,    77,    81,    19,    25,    44,
      46,    34,     0,     0,     0,     0,    64,     0,     0,    82,
      80,     0,    91,     0,    79,     0,    30,    51,    88,    89,
       0,    66,     0,     0,     0,     0,     0,    33,     0,     0,
       0,    63,     0,    84,    93,     0,    90,     0,    32,    52,
      70,    72,    76,    74,    78,     0,     0,     0,     0,    83,
       0,    68,    59,     0,    61,    62,    92,     0,     0,    60,
      58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,   194,    22,    78,  -106,  -106,  -106,  -106,
    -106,   -29,  -106,    81,    -7,  -106,   133,   -84,   -88,   -73,
     -70,  -105,    69,    77,    84,   -67,  -106,  -106,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    82,    83,    50,    59,    32,    43,
      22,    84,    56,    85,    10,    14,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   135,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   107,   117,    45,   111,   109,   110,   134,    23,    17,
      11,   114,    46,    13,    55,   140,   129,    47,   117,    15,
      28,    61,     7,    16,    20,    30,    29,     7,    51,    36,
      97,   139,    37,   128,    41,   130,    18,    19,    33,   109,
      60,   146,   139,   137,    48,   156,    21,   109,   -20,   109,
     109,   109,   109,    31,     1,     2,     3,   -22,   144,    38,
      34,   152,    42,   154,    67,    35,    68,   -16,    39,    69,
      70,    40,    49,   159,   160,    71,   153,   109,     8,    44,
      72,     9,    52,     8,    73,    74,     9,    44,    75,    57,
      24,    25,    76,    77,     1,     2,     3,    78,     1,     2,
       3,    79,    80,    81,   115,    62,    68,   112,   121,    69,
      70,   113,   -18,    65,   123,    71,   124,    58,    26,    27,
      72,    53,    54,    66,    73,    74,    99,    44,   116,   118,
     119,   120,    76,    77,     1,     2,     3,    78,    98,    73,
      74,    79,    80,    81,   126,   103,    68,   106,    77,    69,
      70,   100,    78,    63,    64,    71,    79,    80,    81,   104,
      72,   105,   118,   119,    73,    74,   122,    44,   127,   108,
     125,   131,    76,    77,     1,     2,     3,    78,   132,   133,
     145,    79,    80,    81,    68,   147,   148,    69,    70,   149,
     157,   141,   150,    71,   151,   123,   158,   155,    72,    12,
     102,   143,    73,    74,     0,    44,   101,   142,     0,     0,
      76,    77,     1,     2,     3,    78,     0,     0,     0,    79,
      80,    81,    68,     0,     0,    69,    70,     0,     0,     0,
       0,    71,     0,     0,     0,     0,    72,     0,     0,     0,
      73,    74,     0,    44,   138,     0,     0,     0,    76,    77,
       1,     2,     3,    78,     0,     0,     0,    79,    80,    81,
      68,     0,     0,    69,    70,     0,     0,     0,     0,    71,
       0,     0,     0,     0,    72,     0,     0,     0,    73,    74,
       0,    44,     0,     0,     0,     0,    76,    77,     1,     2,
       3,    78,    73,    74,     0,    79,    80,    81,     0,     0,
      76,    77,     0,    73,    74,    78,     0,     0,     0,    79,
      80,    81,    77,     0,     0,     0,    78,     0,     0,     0,
      79,    80,    81
};

static const yytype_int16 yycheck[] =
{
      73,    71,    86,    32,    74,    78,    73,   112,    15,     1,
       0,    78,    23,    30,    43,   120,   104,    28,   102,    22,
      30,    50,     0,    26,     1,     1,    23,     5,    35,    30,
      59,   115,    27,   103,     1,   105,    28,    29,     1,   112,
      47,   129,   126,   113,     1,   150,    23,   120,    24,   122,
     123,   124,   125,    29,    31,    32,    33,    24,   125,    27,
      23,   145,    29,   147,     1,    28,     3,    24,    30,     6,
       7,    26,    29,   157,   158,    12,   146,   150,     0,    24,
      17,     0,    26,     5,    21,    22,     5,    24,    25,     1,
      38,    39,    29,    30,    31,    32,    33,    34,    31,    32,
      33,    38,    39,    40,     1,    30,     3,    22,    29,     6,
       7,    26,    24,    27,    34,    12,    36,    29,    28,    29,
      17,    38,    39,    27,    21,    22,    27,    24,    25,    18,
      19,    20,    29,    30,    31,    32,    33,    34,    30,    21,
      22,    38,    39,    40,     1,    22,     3,    29,    30,     6,
       7,    27,    34,    38,    39,    12,    38,    39,    40,    22,
      17,    22,    18,    19,    21,    22,    37,    24,    25,    22,
      35,    29,    29,    30,    31,    32,    33,    34,    30,    23,
      23,    38,    39,    40,     3,    23,    23,     6,     7,    23,
       4,   122,    28,    12,    27,    34,    23,    29,    17,     5,
      67,   124,    21,    22,    -1,    24,    25,   123,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      21,    22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    22,
      -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    21,    22,    -1,    38,    39,    40,    -1,    -1,
      29,    30,    -1,    21,    22,    34,    -1,    -1,    -1,    38,
      39,    40,    30,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    42,    43,    44,    45,    46,    54,
      55,     0,    44,    30,    56,    22,    26,     1,    28,    29,
       1,    23,    51,    55,    38,    39,    28,    29,    30,    23,
       1,    29,    49,     1,    23,    28,    30,    27,    27,    30,
      26,     1,    29,    50,    24,    52,    23,    28,     1,    29,
      47,    55,    26,    38,    39,    52,    53,     1,    29,    48,
      55,    52,    30,    38,    39,    27,    27,     1,     3,     6,
       7,    12,    17,    21,    22,    25,    29,    30,    34,    38,
      39,    40,    45,    46,    52,    54,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    52,    30,    27,
      27,    25,    57,    22,    22,    22,    29,    61,    22,    60,
      66,    61,    22,    26,    66,     1,    25,    58,    18,    19,
      20,    29,    37,    34,    36,    35,     1,    25,    61,    59,
      61,    29,    30,    23,    62,    68,    69,    61,    25,    58,
      62,    63,    65,    64,    66,    23,    59,    23,    23,    23,
      28,    27,    58,    61,    58,    29,    62,     4,    23,    58,
      58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    45,    47,    46,    48,    46,
      49,    46,    50,    46,    51,    51,    51,    51,    51,    51,
      52,    52,    52,    52,    52,    53,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       7,     7,     5,     5,     6,     6,     0,     7,     0,     8,
       0,     6,     0,     7,     4,     5,     3,     4,     2,     1,
       4,     3,     5,     5,     4,     0,     3,     4,     1,     1,
       1,     3,     4,     6,     7,     6,     7,     1,     4,     4,
       1,     2,     3,     1,     1,     1,     1,     1,     7,     5,
       7,     5,     5,     3,     2,     1,     2,     1,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       2,     1,     1,     4,     3,     1,     1,     1,     2,     2,
       1,     0,     3,     1
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
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1524 "y.tab.c" /* yacc.c:1257  */
        break;

    case 31: /* INT  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1530 "y.tab.c" /* yacc.c:1257  */
        break;

    case 32: /* FLOAT  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1536 "y.tab.c" /* yacc.c:1257  */
        break;

    case 33: /* VOID  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1542 "y.tab.c" /* yacc.c:1257  */
        break;

    case 34: /* ADDOP  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1548 "y.tab.c" /* yacc.c:1257  */
        break;

    case 35: /* MULOP  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1554 "y.tab.c" /* yacc.c:1257  */
        break;

    case 36: /* RELOP  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1560 "y.tab.c" /* yacc.c:1257  */
        break;

    case 37: /* LOGICOP  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1566 "y.tab.c" /* yacc.c:1257  */
        break;

    case 38: /* CONST_INT  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1572 "y.tab.c" /* yacc.c:1257  */
        break;

    case 39: /* CONST_FLOAT  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1578 "y.tab.c" /* yacc.c:1257  */
        break;

    case 40: /* ERROR_FLOAT  */
#line 361 "demo.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1584 "y.tab.c" /* yacc.c:1257  */
        break;

    case 42: /* start  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1590 "y.tab.c" /* yacc.c:1257  */
        break;

    case 43: /* program  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1596 "y.tab.c" /* yacc.c:1257  */
        break;

    case 44: /* unit  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1602 "y.tab.c" /* yacc.c:1257  */
        break;

    case 45: /* func_declaration  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1608 "y.tab.c" /* yacc.c:1257  */
        break;

    case 46: /* func_definition  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1614 "y.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* parameter_list  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1620 "y.tab.c" /* yacc.c:1257  */
        break;

    case 52: /* compound_statement  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1626 "y.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* var_declaration  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1632 "y.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* type_specifier  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1638 "y.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* declaration_list  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1644 "y.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* statements  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1650 "y.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* statement  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1656 "y.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* expression_statement  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1662 "y.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* variable  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1668 "y.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* expression  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1674 "y.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* logic_expression  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1680 "y.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* rel_expression  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1686 "y.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* simple_expression  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1692 "y.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* term  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1698 "y.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* unary_expression  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1704 "y.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* factor  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1710 "y.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* argument_list  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1716 "y.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* arguments  */
#line 360 "demo.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1722 "y.tab.c" /* yacc.c:1257  */
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
#line 371 "demo.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below

        print_grammar_rule("start","program");

        (yyval.helper) = new Helper();
        (yyval.helper)->text = (yyvsp[0].helper)->text;

        // print_log_text($$->text);
        
        erm_h((yyvsp[0].helper));
	}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 385 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("program","program unit");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 

            erm_h((yyvsp[-1].helper)); erm_h((yyvsp[0].helper));
        }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 397 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("program","unit");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 

            erm_h((yyvsp[0].helper));
        }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 409 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","var_declaration"); 

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 
            erm_h((yyvsp[0].helper)); 
        }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 418 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","func_declaration"); 

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyvsp[0].helper)->text);  
            erm_h((yyvsp[0].helper)); 
        }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 427 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","func_definition");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyvsp[0].helper)->text); 
            erm_h((yyvsp[0].helper)); 
        }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 438 "demo.y" /* yacc.c:1646  */
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
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 481 "demo.y" /* yacc.c:1646  */
    { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-4].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += (yyvsp[-2].helper)->text;
                (yyval.helper)->text += ")";

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
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 523 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo(int x-y);
                **/
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
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
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 571 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo(int x-y)
                **/
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-6].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-5].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += (yyvsp[-3].helper)->text;
                (yyval.helper)->text += ")";

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
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 618 "demo.y" /* yacc.c:1646  */
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
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 652 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo()
                **/

            print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN");
            
            (yyval.helper) = new Helper();

            // update text
            (yyval.helper)->text = (yyvsp[-4].helper)->text;
            (yyval.helper)->text += " ";
            (yyval.helper)->text += (yyvsp[-3].symbol_info)->key;
            (yyval.helper)->text += "(";
            (yyval.helper)->text += ")";

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
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 690 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo(-);
                **/

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
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
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 729 "demo.y" /* yacc.c:1646  */
    { 

                /**
                    To handle errors like: 
                        void foo(-)
                **/

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-5].helper)->text;
                (yyval.helper)->text += " ";
                (yyval.helper)->text += (yyvsp[-4].symbol_info)->key;
                (yyval.helper)->text += "(";
                (yyval.helper)->text += ")";

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
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 770 "demo.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-3].symbol_info),(yyvsp[-4].helper)->text);}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 770 "demo.y" /* yacc.c:1646  */
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
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 793 "demo.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-4].symbol_info),(yyvsp[-5].helper)->text);}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 793 "demo.y" /* yacc.c:1646  */
    { 
                
                /**
                    To handle cases like :
                        void foo(int x-y){}
                **/
                
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
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
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 822 "demo.y" /* yacc.c:1646  */
    {is_function_now = true;insert_function_to_global((yyvsp[-2].symbol_info),(yyvsp[-3].helper)->text);}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 822 "demo.y" /* yacc.c:1646  */
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
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 849 "demo.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-3].symbol_info),(yyvsp[-4].helper)->text);}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 849 "demo.y" /* yacc.c:1646  */
    {
                
                /**
                    To handle cases like :
                        void foo(-){}
                **/
                
                // cout<<"inside func_definition syntax_error 1"<<endl;

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
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 883 "demo.y" /* yacc.c:1646  */
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
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 905 "demo.y" /* yacc.c:1646  */
    {

                /**
                    To handle errors like:
                    void foo(int x-y,int z){}
                **/

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

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
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 932 "demo.y" /* yacc.c:1646  */
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
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 951 "demo.y" /* yacc.c:1646  */
    {

            /**
                To handle cases like:
                    void foo(int x-y,int);
            **/

             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");

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
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 976 "demo.y" /* yacc.c:1646  */
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
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 994 "demo.y" /* yacc.c:1646  */
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
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1013 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-1].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h((yyvsp[-1].helper));

            }
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1032 "demo.y" /* yacc.c:1646  */
    {

                print_grammar_rule("compound_statement","LCURL RCURL");

                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{";  
                (yyval.helper)->text += "}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                // // clear temp function params
                // is_function_now = false;
                // function_params.clear();
             }
#line 2801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1052 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-2].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h((yyvsp[-2].helper));

            }
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1071 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-1].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h((yyvsp[-1].helper));

            }
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1090 "demo.y" /* yacc.c:1646  */
    {
                
                print_grammar_rule("compound_statement","LCURL error RCURL");

                (yyval.helper) = new Helper();

                 // update text
                (yyval.helper)->text = "{";  
                (yyval.helper)->text += "}";

                print_log_text((yyval.helper)->text); 

             }
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1105 "demo.y" /* yacc.c:1646  */
    {

                    sym_tab->enter_scope(); 

                    if(is_function_now)
                    {
                        for(auto el:function_params)
                        {

                            if(el.key == "dummy_key") continue;
                            // insert ID
                            // cout<<"INSIDE FUNCTIONNN"<<endl;
                            if(!sym_tab->insert_symbol(el)) // already present in current scope
                            {
                                error_multiple_declaration(el.key + " in parameter");
                            }
                        }
                    }
                }
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1126 "demo.y" /* yacc.c:1646  */
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
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1160 "demo.y" /* yacc.c:1646  */
    { 

            /**
                To handle errors like :
                    int x-y;
                    int x[10]-y;
                    int x[10.5]-y;
            **/            

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
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
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1198 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","INT"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key; 

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1208 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","FLOAT"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key; 

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 3001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1218 "demo.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","VOID"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1230 "demo.y" /* yacc.c:1646  */
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
#line 3044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1253 "demo.y" /* yacc.c:1646  */
    {

                /**
                To handle errors like :
                    int x-y,z;
                **/    

                print_grammar_rule("declaration_list","declaration_list COMMA ID");

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
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1282 "demo.y" /* yacc.c:1646  */
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
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1310 "demo.y" /* yacc.c:1646  */
    {

               /**
                To handle errors like :
                    int x-y,z[10];
                **/  

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
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
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1344 "demo.y" /* yacc.c:1646  */
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
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1380 "demo.y" /* yacc.c:1646  */
    {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    
                    Also,
                    To handle errors like :
                    int x-y,z[10.5];
                ***/

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
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
#line 3236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1420 "demo.y" /* yacc.c:1646  */
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
#line 3256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1435 "demo.y" /* yacc.c:1646  */
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
#line 3284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1458 "demo.y" /* yacc.c:1646  */
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
#line 3315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1486 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statement");
            
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));  
        }
#line 3330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1496 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements statement");
        
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));  erm_h((yyvsp[0].helper));   
        }
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1508 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements statement");
        
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-2].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper));  erm_h((yyvsp[0].helper));   
        }
#line 3364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1523 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","var_declaration");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1533 "demo.y" /* yacc.c:1646  */
    {
          print_grammar_rule("statement","func_definition");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);
            error_nested_function();

            erm_h((yyvsp[0].helper));
      }
#line 3395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1544 "demo.y" /* yacc.c:1646  */
    {
          print_grammar_rule("statement","func_declaration");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);
            error_nested_function();

            erm_h((yyvsp[0].helper));
      }
#line 3411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1555 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","expression_statement");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1565 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","compound_statement");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[0].helper));
        }
#line 3441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1575 "demo.y" /* yacc.c:1646  */
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
#line 3463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1592 "demo.y" /* yacc.c:1646  */
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
#line 3483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1607 "demo.y" /* yacc.c:1646  */
    {

            print_grammar_rule("statement","IF LPAREN expression RPAREN statement ELSE statement");
        
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
#line 3507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1626 "demo.y" /* yacc.c:1646  */
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
#line 3527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1641 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = "printf";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-2].symbol_info)->key;
            (yyval.helper)->text += ")";
            (yyval.helper)->text += ";";

            print_log_text((yyval.helper)->text);

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-2].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[-2].symbol_info)->key);
                (yyval.helper)->setHelperType("NULL");
            }
            
            erm_s((yyvsp[-2].symbol_info));
        }
#line 3555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1664 "demo.y" /* yacc.c:1646  */
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
#line 3573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1677 "demo.y" /* yacc.c:1646  */
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
#line 3592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1693 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","SEMICOLON");

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = ";";

                    print_log_text((yyval.helper)->text);
                }
#line 3605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1701 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    
                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[-1].helper)->text;
                    (yyval.helper)->text += ";";

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[-1].helper));
                }
#line 3623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1716 "demo.y" /* yacc.c:1646  */
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
#line 3660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1748 "demo.y" /* yacc.c:1646  */
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
#line 3707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1792 "demo.y" /* yacc.c:1646  */
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
#line 3725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1805 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("expression","variable ASSIGNOP logic_expression");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = (yyvsp[-2].helper)->text;
                (yyval.helper)->text += "=";
                (yyval.helper)->text += (yyvsp[0].helper)->text;

                //check error
                // cout<<$1->HelperType<<" ---- "<<$3->HelperType<<endl;
                if(!check_assignop((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType))
                {
                    if((yyvsp[-2].helper)->HelperType=="void" || (yyvsp[0].helper)->HelperType=="void")
                    {
                        error_type_cast_void();
                    }
                    else
                    {
                        error_type_mismatch();
                    }
                }

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
            }
#line 3758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1837 "demo.y" /* yacc.c:1646  */
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
#line 3776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1850 "demo.y" /* yacc.c:1646  */
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
                    else {

                        if((yyvsp[-2].helper)->HelperType=="void" || (yyvsp[0].helper)->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         (yyval.helper)->setHelperType("NULL");
                    }
                    
                    // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                }
                else
                {
                    (yyval.helper)->setHelperType("NULL");
                }

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 3822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1893 "demo.y" /* yacc.c:1646  */
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
#line 3840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1906 "demo.y" /* yacc.c:1646  */
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
                    else {

                        if((yyvsp[-2].helper)->HelperType=="void" || (yyvsp[0].helper)->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         (yyval.helper)->setHelperType("NULL");
                    }
                    // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                }
                else
                {
                    (yyval.helper)->setHelperType("NULL");
                }

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 3885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1948 "demo.y" /* yacc.c:1646  */
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
#line 3904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1962 "demo.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("simple_expression","simple_expression ADDOP term");

                    (yyval.helper) = new Helper();
                    // update text
                    (yyval.helper)->text = (yyvsp[-2].helper)->text;
                    (yyval.helper)->text += (yyvsp[-1].symbol_info)->key;
                    (yyval.helper)->text += (yyvsp[0].helper)->text;
                    // do implicit typecast
                    // cout<<$1->HelperType<<" --- "<<$3->HelperType<<endl;
                    string typecast_ret = do_implicit_typecast((yyvsp[-2].helper)->HelperType,(yyvsp[0].helper)->HelperType);

                    if(typecast_ret != "NULL")
                    {
                        if(typecast_ret != "error") (yyval.helper)->setHelperType(typecast_ret);
                        else {

                        if((yyvsp[-2].helper)->HelperType=="void" || (yyvsp[0].helper)->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         (yyval.helper)->setHelperType("NULL");
                        }
                        // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                    }
                    else
                    {
                        (yyval.helper)->setHelperType("NULL");
                    }

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                    erm_s((yyvsp[-1].symbol_info));
            }
#line 3949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 2004 "demo.y" /* yacc.c:1646  */
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
#line 3968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 2018 "demo.y" /* yacc.c:1646  */
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
                if((yyvsp[0].helper)->text == "0")
                {
                    error_type_cast_mod_zero();
                    (yyval.helper)->setHelperType("NULL");
                }
                else
                {
                    if(typecast_ret != "int")
                    {
                        error_type_cast_mod();
                        (yyval.helper)->setHelperType("NULL");
                    }
                    else{
                        (yyval.helper)->setHelperType("int");
                        // cout<<"HERERE"<<endl;
                    }
                }
            }
            else
            {
                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") (yyval.helper)->setHelperType(typecast_ret);
                    else {

                        if((yyvsp[-2].helper)->HelperType=="void" || (yyvsp[0].helper)->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         (yyval.helper)->setHelperType("NULL");
                    }
                    // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
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
#line 4036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 2083 "demo.y" /* yacc.c:1646  */
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
#line 4056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 2098 "demo.y" /* yacc.c:1646  */
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
#line 4075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 2112 "demo.y" /* yacc.c:1646  */
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
#line 4093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 2127 "demo.y" /* yacc.c:1646  */
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
#line 4112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 2141 "demo.y" /* yacc.c:1646  */
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
                }
                else
                {
                    (yyval.helper)->setHelperType(ret_symbol->var_type);

                    if(ret_symbol->isFunctionDeclaration) // only declared , no definition
                    {
                        error_function_not_implemented();
                    }
                    else // other errors
                    {
                        // printing function param_list
                        // cout<<"OG Param : ";
                        // for(auto s:ret_symbol->param_v)
                        // {
                        //     cout<<s<<" , ";
                        // }
                        // cout<<endl;

                        // // printing argument_list
                        // cout<<"Called Args : ";
                        // for(auto s:$3->param_v)
                        // {
                        //     cout<<s<<" , ";
                        // }
                        // cout<<endl;

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

 
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
            erm_s((yyvsp[-3].symbol_info));
        }
#line 4194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 2218 "demo.y" /* yacc.c:1646  */
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
#line 4216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2235 "demo.y" /* yacc.c:1646  */
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
#line 4235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2249 "demo.y" /* yacc.c:1646  */
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
#line 4253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2262 "demo.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("factor","ERROR_FLOAT");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[0].symbol_info)->key;
            // pass up
            (yyval.helper)->setHelperType("NULL");

            print_log_text((yyval.helper)->text);

            erm_s((yyvsp[0].symbol_info));
        }
#line 4271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 2275 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable INCOP");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "++";

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
        }
#line 4287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 2286 "demo.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable DECOP");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "--";

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
        }
#line 4303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 2299 "demo.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("argument_list","arguments");

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].helper)->text;

                    (yyval.helper)->param_v = (yyvsp[0].helper)->param_v; 

                    print_log_text((yyval.helper)->text);

                    erm_h((yyvsp[0].helper));
                }
#line 4321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 2312 "demo.y" /* yacc.c:1646  */
    {
                print_grammar_rule("argument_list","");
                (yyval.helper) = new Helper();
            }
#line 4330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 2318 "demo.y" /* yacc.c:1646  */
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
#line 4352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 2335 "demo.y" /* yacc.c:1646  */
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
#line 4375 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4379 "y.tab.c" /* yacc.c:1646  */
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
#line 2355 "demo.y" /* yacc.c:1906  */


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

    logout.open("log.txt");
	errout.open("error.txt");

    yyin=fin;
	yyparse();

    sym_tab->print_all_scope(logout);

    logout<<"Total lines: "<<line_count<<endl;
    logout<<"Total errors: "<<err_count<<endl;

    fclose(yyin);

    logout.close();
	errout.close();

    exit(0);
}
