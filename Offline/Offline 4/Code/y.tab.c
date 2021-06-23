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
#line 5 "1705010.y" /* yacc.c:339  */

#include<bits/stdc++.h>
#include <typeinfo>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "Helper.h"

ofstream logout;
ofstream errout;
ofstream codeout;

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

///////////////////////////////////////
///////// MACHINE CODE GEN ////////////

void fileToCode(string sourceFileName)
{
    ifstream file_src;
    file_src.open(sourceFileName);
    string to_copy;

    if(file_src && codeout){
        while(getline(file_src,to_copy)){
            codeout << to_copy << "\n";
        }
    
    } else {
        //Something went wrong
        cout<<"Cannot read File"<<endl;
    }

}

string newWordVariable(string name)
{
    return name+" dw ?";
}

int labelCount=0;
int tempCount=0;

vector<string>DATA_vector;

int SP_VAL = 0;

void incSP(int ara_size = -1)
{
    if(ara_size == -1) SP_VAL += 2;
    else SP_VAL += ara_size*2; // 2 for word
}

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);

    incSP();

	return t;
}


string getJumpText(string relop)
{
    if(relop=="<") return "jl";
    if(relop=="<=") return "jle";
    if(relop==">") return "jg";
    if(relop==">=") return "jge";
    if(relop=="==") return "je";
    if(relop=="!=") return "jne";
}

string stk_address(string stk_offset)
{
    return "[bp-"+stk_offset+"]";
}

string stk_address_typecast(string stk_offset)
{
    return "WORD PTR[bp-"+stk_offset+"]";
}




#line 483 "y.tab.c" /* yacc.c:339  */

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
#line 1 "1705010.y" /* yacc.c:355  */

    #include <bits/stdc++.h>

#line 517 "y.tab.c" /* yacc.c:355  */

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
#line 424 "1705010.y" /* yacc.c:355  */

    SymbolInfo* symbol_info;
    string* symbol_info_str;
    string* temp_str;
    Helper* helper;;

#line 616 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 633 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   330

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

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
       0,   451,   451,   477,   494,   511,   526,   542,   559,   602,
     644,   692,   739,   773,   811,   850,   891,   891,   914,   914,
     943,   943,   990,   990,  1024,  1046,  1073,  1092,  1117,  1135,
    1154,  1178,  1198,  1217,  1236,  1255,  1281,  1326,  1364,  1374,
    1384,  1396,  1419,  1448,  1477,  1511,  1547,  1587,  1602,  1626,
    1654,  1668,  1683,  1698,  1712,  1727,  1742,  1758,  1772,  1818,
    1833,  1852,  1889,  1917,  1957,  1970,  1986,  1995,  2014,  2049,
    2100,  2118,  2159,  2176,  2276,  2293,  2357,  2375,  2450,  2468,
    2580,  2595,  2609,  2628,  2646,  2720,  2741,  2762,  2775,  2788,
    2804,  2822,  2839,  2845,  2862
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

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -23

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,  -110,  -110,  -110,    28,    40,  -110,  -110,  -110,  -110,
      26,  -110,  -110,     3,    12,    13,   -19,    46,    38,  -110,
      41,    29,    64,    50,    73,    83,    60,  -110,    79,    31,
    -110,  -110,    93,   -13,    33,    40,  -110,  -110,  -110,    98,
      63,  -110,  -110,    93,  -110,  -110,    62,    40,  -110,  -110,
      93,   100,    70,   111,   113,  -110,    82,  -110,  -110,    93,
     112,  -110,  -110,   118,   121,  -110,  -110,   200,   119,   127,
     128,    97,   135,   290,   290,  -110,  -110,     5,   290,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,   122,  -110,  -110,    78,
     141,  -110,   136,    25,   129,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,   162,   290,   137,   290,  -110,   143,   148,   114,
    -110,   157,   290,   290,  -110,   238,  -110,  -110,  -110,  -110,
     290,  -110,   290,   290,   290,   290,   276,  -110,   158,   137,
     159,  -110,   -14,  -110,  -110,   165,   161,   163,  -110,  -110,
    -110,  -110,   129,   151,  -110,   276,   290,   276,   168,   290,
    -110,   290,  -110,   194,   176,  -110,  -110,   177,  -110,   276,
     276,   182,  -110,  -110,   179,  -110
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
       0,     0,     0,     0,     0,    31,    66,    68,     0,    86,
      87,    88,    55,    54,    57,    53,     0,    50,    56,    83,
       0,    70,    72,    74,    76,    78,    82,    19,    25,    44,
      46,    34,     0,     0,     0,     0,    65,     0,     0,    83,
      81,     0,    92,     0,    80,     0,    30,    51,    89,    90,
       0,    67,     0,     0,     0,     0,     0,    33,     0,     0,
       0,    64,     0,    85,    94,     0,    91,     0,    32,    52,
      71,    73,    77,    75,    79,     0,     0,     0,     0,     0,
      84,     0,    69,    59,     0,    61,    62,     0,    93,     0,
       0,     0,    60,    58,     0,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,   204,    16,    17,  -110,  -110,  -110,  -110,
    -110,    34,  -110,    18,    -9,  -110,   144,   -78,   -34,   -73,
     -70,  -109,    88,    89,    91,   -71,  -110,  -110,  -110
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
     109,   107,   110,   134,   111,   109,    23,   114,   117,   148,
      46,   140,   149,    17,    20,    47,     7,     8,     9,    24,
      25,     7,     8,     9,   117,    15,    51,   112,    11,    16,
      30,   113,    41,   128,    48,   130,    21,   139,    60,   109,
      18,    19,   158,   137,     1,     2,     3,   109,   139,   109,
     109,   109,   109,   -20,   144,   -22,    13,   -16,    31,   123,
      42,   124,    49,    57,    29,    33,    45,   153,    28,   155,
     129,     1,     2,     3,    26,    27,   154,    55,   109,   157,
      36,   162,   163,    67,    61,    68,   -18,    34,    69,    70,
      39,    58,    35,    97,    71,   146,   118,   119,   120,    72,
      37,    53,    54,    73,    74,    40,    44,    75,    63,    64,
      38,    76,    77,     1,     2,     3,    78,    44,    73,    74,
      79,    80,    81,   115,    52,    68,   106,    77,    69,    70,
      62,    78,   118,   119,    71,    79,    80,    81,    65,    72,
      66,   103,    98,    73,    74,    99,    44,   116,   100,   104,
     105,    76,    77,     1,     2,     3,    78,   108,    73,    74,
      79,    80,    81,   126,   125,    68,    76,    77,    69,    70,
     121,    78,   131,   122,    71,    79,    80,    81,   132,    72,
     133,   145,   147,    73,    74,   123,    44,   127,   150,   151,
     152,    76,    77,     1,     2,     3,    78,   156,   159,   160,
      79,    80,    81,    68,   161,   164,    69,    70,   165,    12,
     141,   102,    71,   143,   142,     0,     0,    72,     0,     0,
       0,    73,    74,     0,    44,   101,     0,     0,     0,    76,
      77,     1,     2,     3,    78,     0,     0,     0,    79,    80,
      81,    68,     0,     0,    69,    70,     0,     0,     0,     0,
      71,     0,     0,     0,     0,    72,     0,     0,     0,    73,
      74,     0,    44,   138,     0,     0,     0,    76,    77,     1,
       2,     3,    78,     0,     0,     0,    79,    80,    81,    68,
       0,     0,    69,    70,     0,     0,     0,     0,    71,     0,
       0,     0,     0,    72,     0,     0,     0,    73,    74,     0,
      44,     0,     0,     0,     0,    76,    77,     1,     2,     3,
      78,    73,    74,     0,    79,    80,    81,     0,     0,     0,
      77,     0,     0,     0,    78,     0,     0,     0,    79,    80,
      81
};

static const yytype_int16 yycheck[] =
{
      73,    71,    73,   112,    74,    78,    15,    78,    86,    23,
      23,   120,    26,     1,     1,    28,     0,     0,     0,    38,
      39,     5,     5,     5,   102,    22,    35,    22,     0,    26,
       1,    26,     1,   103,     1,   105,    23,   115,    47,   112,
      28,    29,   151,   113,    31,    32,    33,   120,   126,   122,
     123,   124,   125,    24,   125,    24,    30,    24,    29,    34,
      29,    36,    29,     1,    23,     1,    32,   145,    30,   147,
     104,    31,    32,    33,    28,    29,   146,    43,   151,   149,
      30,   159,   160,     1,    50,     3,    24,    23,     6,     7,
      30,    29,    28,    59,    12,   129,    18,    19,    20,    17,
      27,    38,    39,    21,    22,    26,    24,    25,    38,    39,
      27,    29,    30,    31,    32,    33,    34,    24,    21,    22,
      38,    39,    40,     1,    26,     3,    29,    30,     6,     7,
      30,    34,    18,    19,    12,    38,    39,    40,    27,    17,
      27,    22,    30,    21,    22,    27,    24,    25,    27,    22,
      22,    29,    30,    31,    32,    33,    34,    22,    21,    22,
      38,    39,    40,     1,    35,     3,    29,    30,     6,     7,
      29,    34,    29,    37,    12,    38,    39,    40,    30,    17,
      23,    23,    23,    21,    22,    34,    24,    25,    23,    28,
      27,    29,    30,    31,    32,    33,    34,    29,     4,    23,
      38,    39,    40,     3,    27,    23,     6,     7,    29,     5,
     122,    67,    12,   124,   123,    -1,    -1,    17,    -1,    -1,
      -1,    21,    22,    -1,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      40,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,
      22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    21,    22,    -1,    38,    39,    40,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40
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
      62,    63,    65,    64,    66,    23,    59,    23,    23,    26,
      23,    28,    27,    58,    61,    58,    29,    61,    62,     4,
      23,    27,    58,    58,    23,    29
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
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69
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
       7,     5,     5,     8,     3,     2,     1,     2,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     1,     1,     4,     3,     1,     1,     1,     2,
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
  switch (yytype)
    {
          case 30: /* ID  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1609 "y.tab.c" /* yacc.c:1257  */
        break;

    case 31: /* INT  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1615 "y.tab.c" /* yacc.c:1257  */
        break;

    case 32: /* FLOAT  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1621 "y.tab.c" /* yacc.c:1257  */
        break;

    case 33: /* VOID  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1627 "y.tab.c" /* yacc.c:1257  */
        break;

    case 34: /* ADDOP  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1633 "y.tab.c" /* yacc.c:1257  */
        break;

    case 35: /* MULOP  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1639 "y.tab.c" /* yacc.c:1257  */
        break;

    case 36: /* RELOP  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1645 "y.tab.c" /* yacc.c:1257  */
        break;

    case 37: /* LOGICOP  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1651 "y.tab.c" /* yacc.c:1257  */
        break;

    case 38: /* CONST_INT  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1657 "y.tab.c" /* yacc.c:1257  */
        break;

    case 39: /* CONST_FLOAT  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1663 "y.tab.c" /* yacc.c:1257  */
        break;

    case 40: /* ERROR_FLOAT  */
#line 442 "1705010.y" /* yacc.c:1257  */
      { erm_s(((*yyvaluep).symbol_info));  }
#line 1669 "y.tab.c" /* yacc.c:1257  */
        break;

    case 42: /* start  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1675 "y.tab.c" /* yacc.c:1257  */
        break;

    case 43: /* program  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1681 "y.tab.c" /* yacc.c:1257  */
        break;

    case 44: /* unit  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1687 "y.tab.c" /* yacc.c:1257  */
        break;

    case 45: /* func_declaration  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1693 "y.tab.c" /* yacc.c:1257  */
        break;

    case 46: /* func_definition  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1699 "y.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* parameter_list  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1705 "y.tab.c" /* yacc.c:1257  */
        break;

    case 52: /* compound_statement  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1711 "y.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* var_declaration  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1717 "y.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* type_specifier  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1723 "y.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* declaration_list  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1729 "y.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* statements  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1735 "y.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* statement  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1741 "y.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* expression_statement  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1747 "y.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* variable  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1753 "y.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* expression  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1759 "y.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* logic_expression  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1765 "y.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* rel_expression  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1771 "y.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* simple_expression  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1777 "y.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* term  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1783 "y.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* unary_expression  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1789 "y.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* factor  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1795 "y.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* argument_list  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1801 "y.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* arguments  */
#line 441 "1705010.y" /* yacc.c:1257  */
      { erm_h(((*yyvaluep).helper));  }
#line 1807 "y.tab.c" /* yacc.c:1257  */
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
#line 452 "1705010.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below

        print_grammar_rule("start","program");

        (yyval.helper) = new Helper();
        (yyval.helper)->text = (yyvsp[0].helper)->text;

        // code
        (yyval.helper)->code = (yyvsp[0].helper)->code;

        // print_log_text($$->text);

        codeout<<".DATA"<<endl;
        for(auto dv:DATA_vector) codeout<<dv<<endl;
        codeout<<endl;

        codeout<<".CODE"<<endl;
        
        codeout<<"\n"<<(yyval.helper)->code<<"\n"<<endl;
        
        erm_h((yyvsp[0].helper));
	}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 477 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("program","program unit");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            // code
            (yyval.helper)->code = (yyvsp[-1].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[-1].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[-1].helper)->stk_offset;

            erm_h((yyvsp[-1].helper)); erm_h((yyvsp[0].helper));
        }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 494 "1705010.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("program","unit");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 

            // code
            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
        }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 511 "1705010.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","var_declaration"); 

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text); 

            // code
            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper)); 
        }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 526 "1705010.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","func_declaration"); 

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyvsp[0].helper)->text); 

            // code
            (yyval.helper)->code = (yyvsp[0].helper)->code;

            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper)); 
        }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 542 "1705010.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("unit","func_definition");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyvsp[0].helper)->text); 

            // code
            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper)); 
        }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 559 "1705010.y" /* yacc.c:1646  */
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
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 602 "1705010.y" /* yacc.c:1646  */
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
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 644 "1705010.y" /* yacc.c:1646  */
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
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 692 "1705010.y" /* yacc.c:1646  */
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
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 739 "1705010.y" /* yacc.c:1646  */
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
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 773 "1705010.y" /* yacc.c:1646  */
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
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 811 "1705010.y" /* yacc.c:1646  */
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
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 850 "1705010.y" /* yacc.c:1646  */
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
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 891 "1705010.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-3].symbol_info),(yyvsp[-4].helper)->text);}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 891 "1705010.y" /* yacc.c:1646  */
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
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 914 "1705010.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-4].symbol_info),(yyvsp[-5].helper)->text);}
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 914 "1705010.y" /* yacc.c:1646  */
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
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 943 "1705010.y" /* yacc.c:1646  */
    {is_function_now = true;insert_function_to_global((yyvsp[-2].symbol_info),(yyvsp[-3].helper)->text);}
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 943 "1705010.y" /* yacc.c:1646  */
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

                // code

                // code

                (yyval.helper)->code = (yyvsp[-4].symbol_info)->key+" PROC\n";

                if((yyvsp[-4].symbol_info)->key=="main")
                {
                    (yyval.helper)->code += "MOV AX, @DATA\nMOV DS, AX\n";
                }

                (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";

                if((yyvsp[-4].symbol_info)->key=="main")
                {
                    (yyval.helper)->code += "MOV AH,4ch\nINT 21h\n";
                }

                (yyval.helper)->code += (yyvsp[-4].symbol_info)->key+" ENDP\n";
            
                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h((yyvsp[-5].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-4].symbol_info));
            }
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 990 "1705010.y" /* yacc.c:1646  */
    { is_function_now = true;insert_function_to_global((yyvsp[-3].symbol_info),(yyvsp[-4].helper)->text);}
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 990 "1705010.y" /* yacc.c:1646  */
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
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 1024 "1705010.y" /* yacc.c:1646  */
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
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 1046 "1705010.y" /* yacc.c:1646  */
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
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 1073 "1705010.y" /* yacc.c:1646  */
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
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 1092 "1705010.y" /* yacc.c:1646  */
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
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1117 "1705010.y" /* yacc.c:1646  */
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
#line 2875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1135 "1705010.y" /* yacc.c:1646  */
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
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1154 "1705010.y" /* yacc.c:1646  */
    {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                (yyval.helper) = new Helper();

                // update text
                (yyval.helper)->text = "{\n"; 
                (yyval.helper)->text += (yyvsp[-1].helper)->text; 
                (yyval.helper)->text += "\n}"; 

                print_log_text((yyval.helper)->text);

                // code
                (yyval.helper)->code = (yyvsp[-1].helper)->code;
                (yyval.helper)->tempVar = (yyvsp[-1].helper)->tempVar;
                (yyval.helper)->stk_offset = (yyvsp[-1].helper)->stk_offset;

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h((yyvsp[-1].helper));

            }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1178 "1705010.y" /* yacc.c:1646  */
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
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1198 "1705010.y" /* yacc.c:1646  */
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
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1217 "1705010.y" /* yacc.c:1646  */
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
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1236 "1705010.y" /* yacc.c:1646  */
    {
                
                print_grammar_rule("compound_statement","LCURL error RCURL");

                (yyval.helper) = new Helper();

                 // update text
                (yyval.helper)->text = "{";  
                (yyval.helper)->text += "}";

                print_log_text((yyval.helper)->text); 

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

             }
#line 3021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1255 "1705010.y" /* yacc.c:1646  */
    {

                    sym_tab->enter_scope(); 

                    if(is_function_now)
                    {
                        for(auto el:function_params)
                        {

                            if(el.key == "dummy_key") continue;
                            if(el.var_type == "void")
                            {
                                error_var_type();
                                el.var_type = "NULL";
                            }
                            // insert ID
                            // cout<<"INSIDE FUNCTIONNN"<<endl;
                            if(!sym_tab->insert_symbol(el)) // already present in current scope
                            {
                                error_multiple_declaration(el.key + " in parameter");
                            }
                        }
                    }
                }
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1281 "1705010.y" /* yacc.c:1646  */
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
                    if(el->var_type == "array")
                    {
                        el->setVarType((yyvsp[-2].helper)->text + "_array");
                        incSP(el->ara_size);
                        el->stk_offset = to_string(SP_VAL);
                    }
                    else 
                    {
                        el->setVarType((yyvsp[-2].helper)->text); 

                        incSP();
                        el->stk_offset = to_string(SP_VAL);
                    }
                    
                    if(!sym_tab->insert_symbol(*el)) // already present in current scope
                    {
                        error_multiple_declaration(el->key);
                    }

                }
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[-1].helper));
        }
#line 3100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1326 "1705010.y" /* yacc.c:1646  */
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
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1364 "1705010.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","INT"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key; 

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 3156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1374 "1705010.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","FLOAT"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key; 

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1384 "1705010.y" /* yacc.c:1646  */
    { 
                    print_grammar_rule("type_specifier","VOID"); 

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

                    print_log_text((yyval.helper)->text);

                    erm_s((yyvsp[0].symbol_info));
                }
#line 3186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1396 "1705010.y" /* yacc.c:1646  */
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
#line 3214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1419 "1705010.y" /* yacc.c:1646  */
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
#line 3248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1448 "1705010.y" /* yacc.c:1646  */
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
                (yyvsp[-3].symbol_info)->ara_size = stoi((yyvsp[-1].symbol_info)->key);
                (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                // $$->print();

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-5].helper)); 
                // erm_s($3); 
                erm_s((yyvsp[-1].symbol_info));
           }
#line 3282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1477 "1705010.y" /* yacc.c:1646  */
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
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1511 "1705010.y" /* yacc.c:1646  */
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
#line 3362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1547 "1705010.y" /* yacc.c:1646  */
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
#line 3407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1587 "1705010.y" /* yacc.c:1646  */
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
#line 3427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1602 "1705010.y" /* yacc.c:1646  */
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
                    (yyvsp[-3].symbol_info)->ara_size = stoi((yyvsp[-1].symbol_info)->key);
                    (yyval.helper)->v.push_back((yyvsp[-3].symbol_info));
                    // cout<<"PRINT"<<endl;
                    // $$->print();

                    print_log_text((yyval.helper)->text);

                    // erm_s($1); 
                    erm_s((yyvsp[-1].symbol_info));
            }
#line 3456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1626 "1705010.y" /* yacc.c:1646  */
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
#line 3487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1654 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statement");
            
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));  
        }
#line 3506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1668 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements statement");
        
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = (yyvsp[-1].helper)->code+"\n";
            (yyval.helper)->code += (yyvsp[0].helper)->code;

            erm_h((yyvsp[-1].helper));  erm_h((yyvsp[0].helper));   
        }
#line 3526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1683 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statements","statements statement");
        
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-2].helper)->text;
            (yyval.helper)->text += "\n";
            (yyval.helper)->text += (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper));  erm_h((yyvsp[0].helper));   
        }
#line 3543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1698 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","var_declaration");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
        }
#line 3562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1712 "1705010.y" /* yacc.c:1646  */
    {
          print_grammar_rule("statement","func_definition");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);
            error_nested_function();

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
      }
#line 3582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1727 "1705010.y" /* yacc.c:1646  */
    {
          print_grammar_rule("statement","func_declaration");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);
            error_nested_function();

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
      }
#line 3602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1742 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","expression_statement");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = "; "+(yyval.helper)->text+"\n";
            (yyval.helper)->code += (yyvsp[0].helper)->code;

            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
        }
#line 3623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1758 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","compound_statement");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].helper)->text;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
        }
#line 3642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1772 "1705010.y" /* yacc.c:1646  */
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

            string tempL1 = newLabel();
            string tempL2 = newLabel();

            string to_print = (yyval.helper)->text;
            to_print.erase(remove(to_print.begin(), to_print.end(), '\n'), to_print.end());

            (yyval.helper)->code = "; "+to_print+"\n";

            (yyval.helper)->code += (yyvsp[-4].helper)->code+"\n";

            (yyval.helper)->code += tempL1+":\n"; // loop starting label

            (yyval.helper)->code += "; "+(yyvsp[-3].helper)->text+"\n";
            (yyval.helper)->code += (yyvsp[-3].helper)->code+"\n"; // eval expression

            (yyval.helper)->code += "; check for loop condition\n";
            (yyval.helper)->code += "CMP "+ stk_address((yyvsp[-3].helper)->stk_offset)+",0\n"; // check if need to exit
            (yyval.helper)->code += "JE "+tempL2+"\n"; // check if need to exit

            (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";  // exec statement

            (yyval.helper)->code += "; "+(yyvsp[-2].helper)->text+"\n";  // exec statement
            (yyval.helper)->code += (yyvsp[-2].helper)->code+"\n";  // exec statement

            (yyval.helper)->code += "JMP "+tempL1+"\n"; // loop
            (yyval.helper)->code += tempL2+":\n"; // loop ending label


            erm_h((yyvsp[-4].helper)); erm_h((yyvsp[-3].helper)); erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
        }
#line 3693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1818 "1705010.y" /* yacc.c:1646  */
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
#line 3713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1833 "1705010.y" /* yacc.c:1646  */
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
#line 3737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1852 "1705010.y" /* yacc.c:1646  */
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

            string tempL1 = newLabel();
            string tempL2 = newLabel();

            string to_print = (yyval.helper)->text;
            to_print.erase(remove(to_print.begin(), to_print.end(), '\n'), to_print.end());

            (yyval.helper)->code = "; "+to_print+"\n";

            (yyval.helper)->code += tempL1+":\n"; // loop starting label

            (yyval.helper)->code += "; "+(yyvsp[-2].helper)->text+"\n";
            (yyval.helper)->code += (yyvsp[-2].helper)->code+"\n"; // eval expression

            (yyval.helper)->code += "; check while loop condition\n";
            (yyval.helper)->code += "CMP "+ stk_address((yyvsp[-2].helper)->stk_offset) +",0\n"; // check if need to exit
            (yyval.helper)->code += "JE "+tempL2+"\n"; // check if need to exit

            (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";  // exec statement

            (yyval.helper)->code += "JMP "+tempL1+"\n"; // loop
            (yyval.helper)->code += tempL2+":\n"; // loop ending label

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper)); 
        }
#line 3779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1889 "1705010.y" /* yacc.c:1646  */
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

            (yyval.helper)->code = "\n; "+(yyval.helper)->text+"\n";
            (yyval.helper)->code += "MOV AX,"+stk_address(ret_symbol->stk_offset)+"\n";
            (yyval.helper)->code += "MOV FOR_PRINT,AX\n";
            (yyval.helper)->code += "CALL OUTPUT";
            
            erm_s((yyvsp[-2].symbol_info));
        }
#line 3812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1917 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = "printf";
            (yyval.helper)->text += "(";
            (yyval.helper)->text += (yyvsp[-5].symbol_info)->key;
            (yyval.helper)->text += "[";
            (yyval.helper)->text += (yyvsp[-3].helper)->text;
            (yyval.helper)->text += "]";
            (yyval.helper)->text += ")";
            (yyval.helper)->text += ";";

            print_log_text((yyval.helper)->text);

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup((yyvsp[-5].symbol_info)->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable((yyvsp[-5].symbol_info)->key);
                (yyval.helper)->setHelperType("NULL");
            }

            (yyval.helper)->code = "\n; "+(yyval.helper)->text+"\n";

            // code
            
            (yyval.helper)->code += (yyvsp[-3].helper)->code+"\n";
            (yyval.helper)->code += "MOV SI,"+stk_address((yyvsp[-3].helper)->stk_offset)+"\n";
            (yyval.helper)->code += "ADD SI,SI\n";

            (yyval.helper)->stk_offset = ret_symbol->stk_offset+"+SI";

            (yyval.helper)->code += "MOV AX,"+stk_address((yyval.helper)->stk_offset)+"\n";
            (yyval.helper)->code += "MOV FOR_PRINT,AX\n";
            (yyval.helper)->code += "CALL OUTPUT";
            
            erm_s((yyvsp[-5].symbol_info));
        }
#line 3857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1957 "1705010.y" /* yacc.c:1646  */
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
#line 3875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1970 "1705010.y" /* yacc.c:1646  */
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
#line 3894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1986 "1705010.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","SEMICOLON");

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = ";";

                    print_log_text((yyval.helper)->text);

                }
#line 3908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1995 "1705010.y" /* yacc.c:1646  */
    {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    
                    (yyval.helper) = new Helper();

                    // update text
                    (yyval.helper)->text = (yyvsp[-1].helper)->text;
                    (yyval.helper)->text += ";";

                    print_log_text((yyval.helper)->text);

                    (yyval.helper)->code = (yyvsp[-1].helper)->code;
                    (yyval.helper)->tempVar = (yyvsp[-1].helper)->tempVar;
                    (yyval.helper)->stk_offset = (yyvsp[-1].helper)->stk_offset;

                    erm_h((yyvsp[-1].helper));
                }
#line 3930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2014 "1705010.y" /* yacc.c:1646  */
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

            (yyval.helper)->tempVar = (yyvsp[0].symbol_info)->key;
            (yyval.helper)->stk_offset = ret_symbol->stk_offset;

            erm_s((yyvsp[0].symbol_info));
        }
#line 3970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 2049 "1705010.y" /* yacc.c:1646  */
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

            // code
            
            (yyval.helper)->code = (yyvsp[-1].helper)->code+"\n";
            (yyval.helper)->code += "MOV SI,"+stk_address((yyvsp[-1].helper)->stk_offset)+"\n";
            (yyval.helper)->code += "ADD SI,SI";
            (yyval.helper)->stk_offset = ret_symbol->stk_offset+"+SI";
            
            erm_h((yyvsp[-1].helper));
            erm_s((yyvsp[-3].symbol_info));
         }
#line 4024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2100 "1705010.y" /* yacc.c:1646  */
    {
                print_grammar_rule("expression","logic_expression");

                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // update vector : push up
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                // $$->code = "; "+$1->text+"\n";
                (yyval.helper)->code = (yyvsp[0].helper)->code;
                (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[0].helper));
            }
#line 4047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 2118 "1705010.y" /* yacc.c:1646  */
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

                // code
                
                (yyval.helper)->code = (yyvsp[0].helper)->code+"\n";

                (yyval.helper)->code += "MOV AX,"+stk_address((yyvsp[0].helper)->stk_offset)+"\n";

                (yyval.helper)->code += (yyvsp[-2].helper)->code+"\n";
                (yyval.helper)->code += "MOV "+stk_address_typecast((yyvsp[-2].helper)->stk_offset)+",AX";

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
            }
#line 4089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 2159 "1705010.y" /* yacc.c:1646  */
    {
                print_grammar_rule("logic_expression","rel_expression");

                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // update vector : push up
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                (yyval.helper)->code = (yyvsp[0].helper)->code;
                (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                erm_h((yyvsp[0].helper)); 
            }
#line 4111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 2176 "1705010.y" /* yacc.c:1646  */
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

                if((yyvsp[-1].symbol_info)->key == "&&")
                {
                    // code for &&
                    (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                    (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                    (yyval.helper)->code += "CMP "+ stk_address((yyvsp[-2].helper)->stk_offset)+",0\n";

                    string tempL1 = newLabel();
                    string tempL2 = newLabel();

                    (yyval.helper)->code += "JE "+tempL1+"\n";

                    (yyval.helper)->code += "CMP "+stk_address((yyvsp[0].helper)->stk_offset)+",0\n";
                    (yyval.helper)->code += "JE "+tempL1+"\n";

                    string tempVar = newTemp();

                    (yyval.helper)->tempVar = tempVar;
                    (yyval.helper)->stk_offset = SP_VAL; // init

                    (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",1\n";
                    (yyval.helper)->code += "JMP "+tempL2+"\n";
                    (yyval.helper)->code += tempL1+":\n";

                    (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",0\n";
                    (yyval.helper)->code += tempL2+":\n";
                    
                }
                else if((yyvsp[-1].symbol_info)->key == "||")
                {
                    // code for ||
                    (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                    (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                    (yyval.helper)->code += "CMP "+stk_address((yyvsp[-2].helper)->stk_offset)+",0\n";

                    string tempL1 = newLabel();
                    string tempL2 = newLabel();

                    (yyval.helper)->code += "JNE "+tempL1+"\n";

                    (yyval.helper)->code += "CMP "+stk_address((yyvsp[0].helper)->stk_offset)+",0\n";
                    (yyval.helper)->code += "JNE "+tempL1+"\n";

                    string tempVar = newTemp();

                    (yyval.helper)->tempVar = tempVar;
                    (yyval.helper)->stk_offset = to_string(SP_VAL); // init

                    (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",0\n";
                    (yyval.helper)->code += "JMP "+tempL2+"\n";
                    (yyval.helper)->code += tempL1+":\n";

                    (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",1\n";
                    (yyval.helper)->code += tempL2+":\n";

                }

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 4214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 2276 "1705010.y" /* yacc.c:1646  */
    {
                print_grammar_rule("rel_expression","simple_expression");

                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // update vector : push up
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                (yyval.helper)->code = (yyvsp[0].helper)->code;
                (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                erm_h((yyvsp[0].helper));
            }
#line 4236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 2293 "1705010.y" /* yacc.c:1646  */
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

                string jumpText = getJumpText((yyvsp[-1].symbol_info)->key);

                // code 
                (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                (yyval.helper)->code += "MOV AX,"+stk_address((yyvsp[-2].helper)->stk_offset)+"\n";
                (yyval.helper)->code += "CMP AX,"+stk_address((yyvsp[0].helper)->stk_offset)+"\n";

                string tempVar = newTemp();
                string tempL1 = newLabel();
                string tempL2 = newLabel();

                (yyval.helper)->tempVar = tempVar;
                (yyval.helper)->stk_offset = to_string(SP_VAL);

                (yyval.helper)->code += jumpText+" "+tempL1+"\n";
                (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",0"+"\n";
                (yyval.helper)->code += "JMP "+tempL2+"\n";
                (yyval.helper)->code += tempL1+":\n";
                (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",1"+"\n";
                (yyval.helper)->code += tempL2+":\n";

                print_log_text((yyval.helper)->text);

                erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                erm_s((yyvsp[-1].symbol_info));
            }
#line 4303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 2357 "1705010.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("simple_expression","term");

                    (yyval.helper) = new Helper();
                    // update text
                    (yyval.helper)->text = (yyvsp[0].helper)->text;
                    // update vector : push up
                    (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                    print_log_text((yyval.helper)->text);

                    (yyval.helper)->code = (yyvsp[0].helper)->code;
                    (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                    (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                    erm_h((yyvsp[0].helper));
            }
#line 4326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 2375 "1705010.y" /* yacc.c:1646  */
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

                    if((yyvsp[-1].symbol_info)->key=="+")
                    {
                        // code for +
                        (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                        (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                        (yyval.helper)->code += "MOV AX,"+stk_address((yyvsp[-2].helper)->stk_offset)+"\n";
                        (yyval.helper)->code += "ADD AX,"+stk_address((yyvsp[0].helper)->stk_offset)+"\n";

                        string tempVar = newTemp();

                        (yyval.helper)->tempVar = tempVar;
                        (yyval.helper)->stk_offset = to_string(SP_VAL);

                        (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",AX";
                    }
                    else
                    {
                        // code for -
                        (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                        (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                        (yyval.helper)->code += "MOV AX,"+stk_address((yyvsp[-2].helper)->stk_offset)+"\n";
                        (yyval.helper)->code += "SUB AX,"+stk_address((yyvsp[0].helper)->stk_offset)+"\n";

                        string tempVar = newTemp();

                        (yyval.helper)->tempVar = tempVar;
                        (yyval.helper)->stk_offset = to_string(SP_VAL);

                        (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",AX";
                    }

                    

                    erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
                    erm_s((yyvsp[-1].symbol_info));
            }
#line 4404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 2450 "1705010.y" /* yacc.c:1646  */
    {

            print_grammar_rule("term","unary_expression");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[0].helper)->text;
            // update vector : push up
            (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
    }
#line 4427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 2468 "1705010.y" /* yacc.c:1646  */
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

                        // code
                        (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                        (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                        (yyval.helper)->code += "MOV AX,"+ stk_address((yyvsp[-2].helper)->stk_offset)+"\n";
                        (yyval.helper)->code += "CWD\n";
                        (yyval.helper)->code += "IDIV "+stk_address_typecast((yyvsp[0].helper)->stk_offset)+"\n";

                        string tempVar = newTemp();

                        (yyval.helper)->tempVar = tempVar;
                        (yyval.helper)->stk_offset = to_string(SP_VAL);

                        (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",DX";
                        

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

                if((yyvsp[-1].symbol_info)->key == "*")
                {
                    // code for *
                    (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                    (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                    (yyval.helper)->code += "MOV AX,"+stk_address((yyvsp[-2].helper)->stk_offset)+"\n";
                    (yyval.helper)->code += "IMUL "+stk_address_typecast((yyvsp[0].helper)->stk_offset)+"\n";

                    string tempVar = newTemp();

                    (yyval.helper)->tempVar = tempVar;
                    (yyval.helper)->stk_offset = to_string(SP_VAL);
                    (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",AX";
                }
                else if((yyvsp[-1].symbol_info)->key == "/")
                {
                    // code
                    (yyval.helper)->code = (yyvsp[-2].helper)->code+"\n";
                    (yyval.helper)->code += (yyvsp[0].helper)->code+"\n";
                    (yyval.helper)->code += "MOV AX,"+ stk_address((yyvsp[-2].helper)->stk_offset)+"\n";
                    (yyval.helper)->code += "CWD\n";
                    (yyval.helper)->code += "IDIV "+stk_address_typecast((yyvsp[0].helper)->stk_offset)+"\n";

                    string tempVar = newTemp();

                    (yyval.helper)->tempVar = tempVar;
                    (yyval.helper)->stk_offset = to_string(SP_VAL);

                    (yyval.helper)->code += "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+",AX";
                }
            }

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-2].helper)); erm_h((yyvsp[0].helper));
            erm_s((yyvsp[-1].symbol_info));
    }
#line 4542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 2580 "1705010.y" /* yacc.c:1646  */
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
#line 4562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 2595 "1705010.y" /* yacc.c:1646  */
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
#line 4581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 2609 "1705010.y" /* yacc.c:1646  */
    { 
                print_grammar_rule("unary_expression","factor");
                
                (yyval.helper) = new Helper();
                // update text
                (yyval.helper)->text = (yyvsp[0].helper)->text;
                // implicit typecast
                (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

                print_log_text((yyval.helper)->text);

                (yyval.helper)->code = (yyvsp[0].helper)->code;
                (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                erm_h((yyvsp[0].helper));
            }
#line 4603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 2628 "1705010.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","variable");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = (yyvsp[0].helper)->text;
            // implicit typecast
            (yyval.helper)->HelperType = (yyvsp[0].helper)->HelperType;

            print_log_text((yyval.helper)->text);

            (yyval.helper)->code = (yyvsp[0].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[0].helper)->text; // no operation , so tempVar is realVar
            (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

            erm_h((yyvsp[0].helper));
        }
#line 4626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 2646 "1705010.y" /* yacc.c:1646  */
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

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
            erm_s((yyvsp[-3].symbol_info));
        }
#line 4705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2720 "1705010.y" /* yacc.c:1646  */
    {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            (yyval.helper) = new Helper();
            // update text
            (yyval.helper)->text = "(";
            (yyval.helper)->text += (yyvsp[-1].helper)->text;
            (yyval.helper)->text += ")";

            (yyval.helper)->HelperType = (yyvsp[-1].helper)->HelperType;

            (yyval.helper)->code = (yyvsp[-1].helper)->code;
            (yyval.helper)->tempVar = (yyvsp[-1].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[-1].helper)->stk_offset;

            print_log_text((yyval.helper)->text);

            erm_h((yyvsp[-1].helper));
        
        }
#line 4731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2741 "1705010.y" /* yacc.c:1646  */
    { 
            print_grammar_rule("factor","CONST_INT");

            // update text
            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[0].symbol_info)->key;

            // pass up
            (yyval.helper)->setHelperType("int");

            print_log_text((yyval.helper)->text);

            // code
            string tempVar = newTemp();
            
            (yyval.helper)->tempVar = tempVar; // init
            (yyval.helper)->stk_offset = to_string(SP_VAL);
            (yyval.helper)->code = "MOV "+stk_address_typecast((yyval.helper)->stk_offset)+","+(yyvsp[0].symbol_info)->key;

            erm_s((yyvsp[0].symbol_info));
        }
#line 4757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2762 "1705010.y" /* yacc.c:1646  */
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
#line 4775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 2775 "1705010.y" /* yacc.c:1646  */
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
#line 4793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 2788 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable INCOP");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "++";

            print_log_text((yyval.helper)->text);

            (yyval.helper)->tempVar = (yyvsp[-1].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[-1].helper)->stk_offset;

            (yyval.helper)->code = "INC "+stk_address_typecast((yyval.helper)->stk_offset);

            erm_h((yyvsp[-1].helper));
        }
#line 4814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 2804 "1705010.y" /* yacc.c:1646  */
    {
            print_grammar_rule("factor","variable DECOP");

            (yyval.helper) = new Helper();
            (yyval.helper)->text = (yyvsp[-1].helper)->text;
            (yyval.helper)->text += "--";

            print_log_text((yyval.helper)->text);

            (yyval.helper)->tempVar = (yyvsp[-1].helper)->tempVar;
            (yyval.helper)->stk_offset = (yyvsp[-1].helper)->stk_offset;

            (yyval.helper)->code = "DEC "+stk_address_typecast((yyval.helper)->stk_offset);

            erm_h((yyvsp[-1].helper));
        }
#line 4835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 2822 "1705010.y" /* yacc.c:1646  */
    {

                    print_grammar_rule("argument_list","arguments");

                    (yyval.helper) = new Helper();
                    (yyval.helper)->text = (yyvsp[0].helper)->text;

                    (yyval.helper)->param_v = (yyvsp[0].helper)->param_v; 

                    print_log_text((yyval.helper)->text);

                    (yyval.helper)->code = (yyvsp[0].helper)->code;
                    (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                    (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                    erm_h((yyvsp[0].helper));
                }
#line 4857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 2839 "1705010.y" /* yacc.c:1646  */
    {
                print_grammar_rule("argument_list","");
                (yyval.helper) = new Helper();
            }
#line 4866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 2845 "1705010.y" /* yacc.c:1646  */
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
#line 4888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 2862 "1705010.y" /* yacc.c:1646  */
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

                (yyval.helper)->code = (yyvsp[0].helper)->code;
                (yyval.helper)->tempVar = (yyvsp[0].helper)->tempVar;
                (yyval.helper)->stk_offset = (yyvsp[0].helper)->stk_offset;

                erm_h((yyvsp[0].helper));
            }
#line 4915 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4919 "y.tab.c" /* yacc.c:1646  */
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
#line 2886 "1705010.y" /* yacc.c:1906  */


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
	codeout.open("code.asm");

    fileToCode("asm_header.txt");
    DATA_vector.push_back("IS_NEG DB ?");
    DATA_vector.push_back("FOR_PRINT DW ?");
    DATA_vector.push_back("MARKER DW 0DH");
    DATA_vector.push_back("DIV_RES DW ? \nDIV_REM DW ?");
    DATA_vector.push_back("CR EQU 0DH\nLF EQU 0AH\nNEWLINE DB CR, LF , '$'");


    yyin=fin;
	yyparse();

    fileToCode("output_proc.txt");



    sym_tab->print_all_scope(logout);

    logout<<"Total lines: "<<line_count<<endl;
    logout<<"Total errors: "<<err_count<<endl;

    fclose(yyin);

    logout.close();
	errout.close();
	codeout.close();

    exit(0);
}
