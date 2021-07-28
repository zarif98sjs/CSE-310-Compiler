%code requires{
    #include <bits/stdc++.h>
}

%{
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
ofstream opt_codeout;

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

string cur_function_name = "";

void insert_function_to_global(SymbolInfo* temp_s,string var_type)
{

    cur_function_name = temp_s->key;

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

// void fileToCode(ofstream &out_s,string sourceFileName)
// {
//     ifstream file_src;
//     file_src.open(sourceFileName);
//     string to_copy;

//     if(file_src && out_s){
//         while(getline(file_src,to_copy)){
//             out_s << to_copy << "\n";
//         }
    
//     } else {
//         //Something went wrong
//         cout<<"Cannot read File"<<endl;
//     }

// }

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

string stk_address_param(string stk_offset)
{
    return "[bp+"+stk_offset+"]";
}

string stk_address_typecast(string stk_offset)
{
    return "WORD PTR [bp-"+stk_offset+"]";
}

string cur_function_label(string name)
{
    return "L_"+name;
}

string process_global_variable(string str)
{
    vector<string> ret;
    char delim = '[';

    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        ret.push_back(str.substr(start, end - start));
    }

    int sz = ret.size();

    if(sz == 1) return ret[0];
    else return ret[0]+"[BX]";
}

vector<string> tokenize(string str,char delim)
{
    vector<string> ret;

    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        ret.push_back(str.substr(start, end - start));
    }

    return ret;
}

void optimize_code(string code)
{
    vector<string>line_v  = tokenize(code,'\n');
    int line_v_sz = line_v.size();

    string prev_line_cmd = "";
    vector<string>prev_line_token;

    for(int i=0;i<line_v_sz;i++)
    {
        string cur_line = line_v[i];
        vector<string>cur_line_token;

        if(cur_line[0] == ';')
        {
            opt_codeout<<cur_line<<endl;
            continue;
        }

        vector<string>token_v = tokenize(cur_line,' ');

        if(token_v[0] == "MOV" || token_v[0]=="mov")
        {

            if(token_v[1] == "WORD")
            {
                cur_line_token = tokenize(token_v[3],',');
            }
            else
            {
                cur_line_token = tokenize(token_v[1],',');
            }

            if(prev_line_cmd == "MOV" || prev_line_cmd == "mov")
            {
                
                if(i>0)
                {
                    // for(auto x:prev_line_token)
                    //     cout<<x<<endl;

                    // cout<<endl;
                    // cout<<"---"<<endl;
                    // cout<<endl;

                    // for(auto x:cur_line_token)
                    //     cout<<x<<endl;

                    // cout<<"==========="<<endl;

                    if(cur_line_token[0] == prev_line_token[1] && cur_line_token[1] == prev_line_token[0])
                    {
                        // optimize
                    }
                    else 
                    {
                        opt_codeout<<cur_line<<endl;
                    }
                }
                else
                {
                    opt_codeout<<cur_line<<endl;
                }
            }
            else
            {
               opt_codeout<<cur_line<<endl; 
            }

            prev_line_token = cur_line_token;

        }
        else
        {

            int sz_token_v = token_v.size();

            if(sz_token_v >= 2)
            {
                if(token_v[1] == "PROC")
                    opt_codeout<<endl;
            }

            opt_codeout<<cur_line<<endl;
            prev_line_token.clear();
        }
        
        prev_line_cmd = token_v[0];
        
    }
}

vector<string>temp_SP_vector;

bool isATempVariable(string s)
{
    for(string x:temp_SP_vector)
        if(x == s) return true;

    return false;
}

%}

%error-verbose

%union{
    SymbolInfo* symbol_info;
    string* symbol_info_str;
    string* temp_str;
    Helper* helper;;
}


%token IF ELSE LOWER_THAN_ELSE FOR WHILE DO BREAK CHAR DOUBLE RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN INCOP DECOP ASSIGNOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token <symbol_info> ID INT FLOAT VOID ADDOP MULOP RELOP LOGICOP CONST_INT CONST_FLOAT ERROR_FLOAT


%type <helper> start program unit variable var_declaration type_specifier func_declaration func_definition parameter_list
%type <helper> expression factor unary_expression term simple_expression rel_expression statement statements compound_statement logic_expression expression_statement
%type <helper> arguments argument_list
%type <helper> declaration_list 
%type <helper> dummy_scope_function 

%destructor { erm_h($$);  } <helper>
%destructor { erm_s($$);  } <symbol_info>

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE



%%

start: program
	{
		//write your code in this block in all the similar blocks below

        print_grammar_rule("start","program");

        $$ = new Helper();

        // update type
        $$->HelperType = $1->HelperType;
        
        $$->text = $1->text;

        // code
        $$->code = $1->code;

        // print_log_text($$->text);


        if(err_count == 0)
        {
            string asm_header = ".MODEL SMALL\n\n.STACK 100H";
            string output_proc = "\r\nOUTPUT PROC\r\n               \r\n        MOV CX , 0FH     \r\n        PUSH CX ; marker\r\n        \r\n        MOV IS_NEG, 0H\r\n        MOV AX , FOR_PRINT\r\n        TEST AX , 8000H\r\n        JE OUTPUT_LOOP\r\n                    \r\n        MOV IS_NEG, 1H\r\n        MOV AX , 0FFFFH\r\n        SUB AX , FOR_PRINT\r\n        ADD AX , 1H\r\n        MOV FOR_PRINT , AX\r\n\r\n    OUTPUT_LOOP:\r\n    \r\n        ;MOV AH, 1\r\n        ;INT 21H\r\n        \r\n        MOV AX , FOR_PRINT\r\n        XOR DX,DX\r\n        MOV BX , 10D\r\n        DIV BX ; QUOTIENT : AX  , REMAINDER : DX     \r\n        \r\n        MOV FOR_PRINT , AX\r\n        \r\n        PUSH DX\r\n        \r\n        CMP AX , 0H\r\n        JNE OUTPUT_LOOP\r\n        \r\n        ;LEA DX, NEWLINE ; DX : USED IN IO and MUL,DIV\r\n        ;MOV AH, 9 ; AH,9 used for character string output\r\n        ;INT 21H;\r\n\r\n        MOV AL , IS_NEG\r\n        CMP AL , 1H\r\n        JNE OP_STACK_PRINT\r\n        \r\n        MOV AH, 2\r\n        MOV DX, '-' ; stored in DL for display \r\n        INT 21H\r\n            \r\n        \r\n    OP_STACK_PRINT:\r\n    \r\n        ;MOV AH, 1\r\n        ;INT 21H\r\n    \r\n        POP BX\r\n        \r\n        CMP BX , 0FH\r\n        JE EXIT_OUTPUT\r\n        \r\n       \r\n        MOV AH, 2\r\n        MOV DX, BX ; stored in DL for display \r\n        ADD DX , 30H\r\n        INT 21H\r\n        \r\n        JMP OP_STACK_PRINT\r\n\r\n    EXIT_OUTPUT:\r\n    \r\n        ;POP CX \r\n\r\n        LEA DX, NEWLINE\r\n        MOV AH, 9 \r\n        INT 21H\r\n    \r\n        RET     \r\n      \r\nOUTPUT ENDP";

            codeout<<asm_header<<endl;
            codeout<<".DATA"<<endl;
            for(auto dv:DATA_vector) codeout<<dv<<endl;
            codeout<<endl;
            codeout<<".CODE"<<endl;
            // fileToCode(codeout,"output_proc.txt");
            codeout<<output_proc<<endl;
            codeout<<"\n"<<$$->code<<"\n"<<endl;

            ///////////
            opt_codeout<<asm_header<<endl;
            opt_codeout<<".DATA"<<endl;
            for(auto dv:DATA_vector) opt_codeout<<dv<<endl;
            opt_codeout<<endl;
            opt_codeout<<".CODE"<<endl;
            // fileToCode(opt_codeout,"output_proc.txt");
            opt_codeout<<output_proc<<endl;
            opt_codeout<<"\n"<<endl;
            optimize_code($$->code);
        }

        erm_h($1);
	}
	;

program: program unit  {
            print_grammar_rule("program","program unit");

            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "\n";
            $$->text += $2->text;

            print_log_text($$->text);

            // code
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            $$->code = $1->code;
            $$->code += $2->code;

            erm_h($1); erm_h($2);
        }
	| unit { 
            print_grammar_rule("program","unit");

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text); 

            // code
            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
        }
	;
	
unit: var_declaration { 
            print_grammar_rule("unit","var_declaration"); 

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text); 

            // code
            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1); 
        }
     | func_declaration { 
            print_grammar_rule("unit","func_declaration"); 

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($1->text); 

            // code
            $$->code = $1->code;

            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            SP_VAL = 0;

            erm_h($1); 
        }
     | func_definition { 
            print_grammar_rule("unit","func_definition");

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($1->text); 

            // code
            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            SP_VAL = 0;

            erm_h($1); 
        }
     ;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    $2->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                // clear param_info
                function_params.clear();

                erm_h($1); erm_s($2) ; erm_h($4);
    
        }
        | type_specifier ID LPAREN parameter_list RPAREN error { 
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    $2->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                // clear param_info
                function_params.clear();

                erm_h($1); erm_s($2) ; erm_h($4);
    
        }
        | type_specifier ID LPAREN parameter_list error RPAREN SEMICOLON { 

                /**
                    To handle errors like: 
                        void foo(int x-y);
                **/
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    $2->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                // clear param_info
                function_params.clear();

                erm_h($1); erm_s($2) ; erm_h($4);
    
        }
        | type_specifier ID LPAREN parameter_list error RPAREN error { 

                /**
                    To handle errors like: 
                        void foo(int x-y)
                **/
                
                print_grammar_rule("func_declaration","type_specifier ID LPAREN parameter_list RPAREN");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;

                // update parameter type
                for(auto temp_s : function_params)
                {
                    $2->param_v.push_back(temp_s.var_type);
                }

                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                // clear param_info
                function_params.clear();

                erm_h($1); erm_s($2) ; erm_h($4);
    
        }
		| type_specifier ID LPAREN RPAREN SEMICOLON { 

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;
                
                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                function_params.clear();

                erm_h($1); erm_s($2) ; 
            }
            | type_specifier ID LPAREN RPAREN error { 

                /**
                    To handle errors like: 
                        void foo()
                **/

            print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN");
            
            $$ = new Helper();

            // update text
            $$->text = $1->text;
            $$->text += " ";
            $$->text += $2->key;
            $$->text += "(";
            $$->text += ")";

            // insert function ID to SymbolTable with VAR_TYPE
            $2->setVarType($1->text);
            $2->isFunction = true;
            
            if(sym_tab->insert_symbol(*$2))
            {
                SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                ret_symbol->isFunctionDeclaration = true; // mark as function declaration
            }
            else
            {
                error_multiple_declaration($2->key);
            }

            print_log_text($$->text);

            function_params.clear();

            erm_h($1); erm_s($2) ; 
        }
        | type_specifier ID LPAREN error RPAREN SEMICOLON { 

                /**
                    To handle errors like: 
                        void foo(-);
                **/

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += ";";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;
                
                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                function_params.clear();

                erm_h($1); erm_s($2) ; 
            }
        | type_specifier ID LPAREN error RPAREN error { 

                /**
                    To handle errors like: 
                        void foo(-)
                **/

                print_grammar_rule("func_declaration","type_specifier ID LPAREN RPAREN");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;
                
                if(sym_tab->insert_symbol(*$2))
                {
                    SymbolInfo* ret_symbol = sym_tab->lookup($2->key);
                    ret_symbol->isFunctionDeclaration = true; // mark as function declaration
                }
                else
                {
                    error_multiple_declaration($2->key);
                }

                print_log_text($$->text);

                function_params.clear();

                erm_h($1); erm_s($2) ; 
            }
		;

		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN { is_function_now = true; insert_function_to_global($2,$1->text);} compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += $7->text; 

                print_log_text($$->text);

                                // code
                $$->code = $2->key+" PROC\n";

                if($2->key=="main")
                {
                    $$->code += "MOV AX, @DATA\nMOV DS, AX\n";
                }

                $$->code += "PUSH BP\nMOV BP,SP\n";
                $$->code += "SUB SP,"+to_string(SP_VAL)+"\n";

                $$->code += $4->code+"\n";
                $$->code += $7->code+"\n";


                $$->code += cur_function_label(cur_function_name)+":\n";
                $$->code += "ADD SP,"+to_string(SP_VAL)+"\n";
                $$->code += "POP BP\n";

                if($2->key=="main")
                {
                    $$->code += "\n;DOS EXIT\nMOV AH,4ch\nINT 21h\n";
                }
                else 
                {
                    $$->code += "RET\n";
                }


                $$->code += $2->key+" ENDP\n\n";

                if($2->key=="main") $$->code += "END MAIN\n";

                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h($1); erm_h($4); erm_h($7);
                erm_s($2);
            }
        | type_specifier ID LPAREN parameter_list error RPAREN { is_function_now = true;insert_function_to_global($2,$1->text);} compound_statement { 
                
                /**
                    To handle cases like :
                        void foo(int x-y){}
                **/
                
                print_grammar_rule("func_definition","type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += $4->text;
                $$->text += ")";
                $$->text += $8->text; 

                print_log_text($$->text);



                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h($1); erm_h($4); erm_h($8);
                erm_s($2);
        }
		|   type_specifier ID LPAREN RPAREN {is_function_now = true;insert_function_to_global($2,$1->text);} compound_statement { 
                print_grammar_rule("func_definition","type_specifier ID LPAREN RPAREN compound_statement");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += $6->text;

                // insert function ID to SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                $2->isFunction = true;
                sym_tab->insert_symbol(*$2);

                print_log_text($$->text);

                // code

                // code

                $$->code = $2->key+" PROC\n";

                if($2->key=="main")
                {
                    $$->code += "MOV AX, @DATA\nMOV DS, AX\n";
                }

                $$->code += "PUSH BP\nMOV BP,SP\n";
                $$->code += "SUB SP,"+to_string(SP_VAL)+"\n";

                $$->code += $6->code+"\n";

                $$->code += cur_function_label(cur_function_name)+":\n";
                $$->code += "ADD SP,"+to_string(SP_VAL)+"\n";
                $$->code += "POP BP\n";

                if($2->key=="main")
                {
                    $$->code += "\n;DOS EXIT\nMOV AH,4ch\nINT 21h\n";
                }
                else 
                {
                    $$->code += "RET\n";
                }
                

                $$->code += $2->key+" ENDP\n";

                if($2->key=="main") $$->code += "END MAIN\n";
            
                // clear temp function params
                is_function_now = false;
                function_params.clear();

                erm_h($1); erm_h($6);
                erm_s($2);
            }
        |  type_specifier ID LPAREN error RPAREN { is_function_now = true;insert_function_to_global($2,$1->text);} compound_statement {
                
                /**
                    To handle cases like :
                        void foo(-){}
                **/
                
                // cout<<"inside func_definition syntax_error 1"<<endl;

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;
                $$->text += "(";
                $$->text += ")";
                $$->text += $7->text; 

                print_log_text($$->text);

                // clear temp function params
                is_function_now = false;
                function_params.clear();

                yyclearin;
                yyerrok;

                erm_h($1); erm_h($7);
                erm_s($2);
        }
 		;				


parameter_list: parameter_list COMMA type_specifier ID {

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->text;
                $$->text += " ";
                $$->text += $4->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                $4->setVarType($3->text);
                function_params.push_back(*$4);

                print_log_text($$->text);

                erm_h($1); erm_h($3);
                erm_s($4);
            }
        | parameter_list error COMMA type_specifier ID {

                /**
                    To handle errors like:
                    void foo(int x-y,int z){}
                **/

               print_grammar_rule("parameter_list","parameter_list COMMA type_specifier ID");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $4->text;
                $$->text += " ";
                $$->text += $5->key;

                // insert parameter ID to SymbolTable with VAR_TYPE
                $5->setVarType($4->text);
                function_params.push_back(*$5);

                print_log_text($$->text);

                erm_h($1); erm_h($4);
                erm_s($5);
        }
        | parameter_list COMMA type_specifier {
             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->text;

                SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
                temp_s.var_type = $3->text;

                function_params.push_back(temp_s);

                print_log_text($$->text);

                erm_h($1); erm_h($3);
        }
        | parameter_list error COMMA type_specifier {

            /**
                To handle cases like:
                    void foo(int x-y,int);
            **/

             print_grammar_rule("parameter_list","parameter_list COMMA type_specifier");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $4->text;

                SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
                temp_s.var_type = $4->text;

                function_params.push_back(temp_s);

                print_log_text($$->text);

                erm_h($1); erm_h($4);
        }
 		| type_specifier ID  { 
                print_grammar_rule("parameter_list","type_specifier ID");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += " ";
                $$->text += $2->key;

                // insert parameter ID to Parameter SymbolTable with VAR_TYPE
                $2->setVarType($1->text);
                function_params.push_back(*$2);

                print_log_text($$->text);

                erm_h($1); erm_s($2);
        }
		| type_specifier {
            print_grammar_rule("parameter_list","type_specifier");

            $$ = new Helper();

            // update type
            $$->HelperType = $1->HelperType;

            // update text
            $$->text = $1->text;

            SymbolInfo temp_s = SymbolInfo("dummy_key","dummy_value");
            temp_s.var_type = $1->text;

            function_params.push_back(temp_s);

            print_log_text($$->text);

            erm_h($1);
        }
 		;
 		
compound_statement: LCURL dummy_scope_function statements RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                $$ = new Helper();

                // update text
                $$->text = "{\n"; 
                $$->text += $3->text; 
                $$->text += "\n}"; 

                print_log_text($$->text);

                // code
                $$->code = $2->code;
                $$->code += $3->code;
                $$->tempVar = $3->tempVar;
                $$->stk_offset = $3->stk_offset;

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h($3);

            }
            | LCURL dummy_scope_function RCURL {

                print_grammar_rule("compound_statement","LCURL RCURL");

                $$ = new Helper();

                // update text
                $$->text = "{";  
                $$->text += "}"; 

                print_log_text($$->text);

                $$->code = $2->code;

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                // // clear temp function params
                // is_function_now = false;
                // function_params.clear();
             }
            | LCURL dummy_scope_function statements error RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                $$ = new Helper();

                // update text
                $$->text = "{\n"; 
                $$->text += $3->text; 
                $$->text += "\n}"; 

                print_log_text($$->text);

                $$->code = $2->code;
                $$->code += $3->code;

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h($3);

            }
            | LCURL dummy_scope_function error statements RCURL {
                print_grammar_rule("compound_statement","LCURL statements RCURL");
                
                $$ = new Helper();

                // update text
                $$->text = "{\n"; 
                $$->text += $4->text; 
                $$->text += "\n}"; 

                print_log_text($$->text);

                $$->code = $2->code;
                $$->code += $4->code;


                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

                erm_h($4);

            }
             | LCURL dummy_scope_function error RCURL {
                
                print_grammar_rule("compound_statement","LCURL error RCURL");

                $$ = new Helper();

                 // update text
                $$->text = "{";  
                $$->text += "}";

                print_log_text($$->text);

                $$->code = $2->code;

                // EXIT
                sym_tab->print_all_scope(logout);
                sym_tab->exit_scope();

             }
 		    ;

dummy_scope_function:  {

                    $$ = new Helper();

                    sym_tab->enter_scope(); 

                    $$->code = "";
                    int PP_Val = 4;

                    if(is_function_now)
                    {
                        // $$->code += "; retrieving function parameter\n";

                        for(auto &el:function_params)
                        {

                            if(el.key == "dummy_key") continue;
                            if(el.var_type == "void")
                            {
                                error_var_type();
                                el.var_type = "NULL";
                            }
                            // insert ID
                            // cout<<"INSIDE FUNCTIONNN"<<endl;

                            incSP();
                            el.stk_offset = to_string(SP_VAL);

                            if(!sym_tab->insert_symbol(el)) // already present in current scope
                            {
                                error_multiple_declaration(el.key + " in parameter");
                            }


                            $$->code += "MOV AX,"+stk_address_param(to_string(PP_Val))+"\n";
                            $$->code += "MOV "+stk_address_typecast(el.stk_offset)+",AX\n";
                            PP_Val+=2;

                        }

                    }
                }
                ;
 		    
var_declaration: type_specifier declaration_list SEMICOLON { 

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
            $$ = new Helper();

            // update text
            $$->text = $1->text;
            $$->text += " ";
            $$->text += $2->text;
            $$->text += ";";

            if($1->text == "void"){
                error_var_type();
            }
            else{
                // insert all declaration_list ID to SymbolTable with VAR_TYPE
                for(auto el:$2->v)
                {
                        if(el->var_type == "array")
                        {
                            el->setVarType($1->text + "_array");

                            if(sym_tab->getCurScopeTableId()!="1") // not global
                            {
                                incSP(el->ara_size);
                                el->stk_offset = to_string(SP_VAL);
                            }
                            else
                            {
                                DATA_vector.push_back(el->key + " dw "+to_string(el->ara_size)+" dup ($)");
                            }

                        }
                        else 
                        {
                            el->setVarType($1->text); 

                            if(sym_tab->getCurScopeTableId()!="1") // not global
                            {
                                incSP();
                                el->stk_offset = to_string(SP_VAL);
                            }
                            else
                            {
                                DATA_vector.push_back(el->key + " dw ?");
                            }
                
                        }
                    
                    if(!sym_tab->insert_symbol(*el)) // already present in current scope
                    {
                        error_multiple_declaration(el->key);
                    }

                }
            }

            print_log_text($$->text);

            erm_h($1); erm_h($2);
        }
        | type_specifier declaration_list error SEMICOLON { 

            /**
                To handle errors like :
                    int x-y;
                    int x[10]-y;
                    int x[10.5]-y;
            **/            

            print_grammar_rule("var_declaration","type_specifier declaration_list SEMICOLON");
            
            $$ = new Helper();

            // update text
            $$->text = $1->text;
            $$->text += " ";
            $$->text += $2->text;
            $$->text += ";";

            // insert all declaration_list ID to SymbolTable with VAR_TYPE
            for(auto el:$2->v)
            {
                if(el->var_type == "array") el->setVarType($1->text + "_array") ; 
                else el->setVarType($1->text); 
                
                if(!sym_tab->insert_symbol(*el)) // already present in current scope
                {
                    error_multiple_declaration(el->key);
                }

            }

            print_log_text($$->text);

            erm_h($1); erm_h($2);
        }
 		;
 		 
type_specifier: INT  { 
                    print_grammar_rule("type_specifier","INT"); 

                    $$ = new Helper();
                    $$->text = $1->key; 

                    print_log_text($$->text);

                    erm_s($1);
                }
 		| FLOAT { 
                    print_grammar_rule("type_specifier","FLOAT"); 

                    $$ = new Helper();
                    $$->text = $1->key; 

                    print_log_text($$->text);

                    erm_s($1);
                }
 		| VOID { 
                    print_grammar_rule("type_specifier","VOID"); 

                    $$ = new Helper();
                    $$->text = $1->key;

                    print_log_text($$->text);

                    erm_s($1);
                }
 		;
 		
declaration_list: declaration_list COMMA ID { 
                    print_grammar_rule("declaration_list","declaration_list COMMA ID");
                    
                    $$ = new Helper();

                    // update text
                    $$->text = $1->text;
                    $$->text += ",";
                    $$->text += $3->key;

                    // update type
                    $$->HelperType = $1->HelperType;

                    // init update vector
                    $$->v = $1->v;
                    $$->v.push_back($3);
                    // $$->print();

                    print_log_text($$->text);

                    erm_h($1); 
                    // erm_s($3); // can't delete this as we will need it later to insert
            }
            | declaration_list error COMMA ID {

                /**
                To handle errors like :
                    int x-y,z;
                **/    

                print_grammar_rule("declaration_list","declaration_list COMMA ID");

                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $4->key;

                // update type
                $$->HelperType = $1->HelperType;

                // init update vector
                $$->v = $1->v;
                $$->v.push_back($4);
                // $$->print();

                print_log_text($$->text);

                erm_h($1); 
                // erm_s($4);
            }
 		    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->key;
                $$->text += "[";
                $$->text += $5->key;
                $$->text += "]";

                // update type
                $$->HelperType = $1->HelperType;

                // init & update vector
                $$->v = $1->v;
                $3->setVarType("array");
                $3->ara_size = stoi($5->key);
                $$->v.push_back($3);
                // $$->print();

                print_log_text($$->text);

                erm_h($1); 
                // erm_s($3); 
                erm_s($5);
           }
           | declaration_list error COMMA ID LTHIRD CONST_INT RTHIRD {

               /**
                To handle errors like :
                    int x-y,z[10];
                **/  

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
           
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $4->key;
                $$->text += "[";
                $$->text += $6->key;
                $$->text += "]";

                // update type
                $$->HelperType = $1->HelperType;

                // init & update vector
                $$->v = $1->v;
                $4->setVarType("array");
                $$->v.push_back($4);
                // $$->print();

                print_log_text($$->text);

                erm_h($1); 
                // erm_s($4); 
                erm_s($6);
           }
           | declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                ***/

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $3->key;
                $$->text += "[";
                $$->text += $5->key;
                $$->text += "]";

                // update type
                $$->HelperType = $1->HelperType;

                // int & update vector
                $$->v = $1->v;
                $3->setVarType("array");
                $$->v.push_back($3);
                // $$->print();

                error_array_size_float();

                print_log_text($$->text);

                erm_h($1); 
                // erm_s($3); 
                erm_s($5);
           
            }
            | declaration_list error COMMA ID LTHIRD CONST_FLOAT RTHIRD {

                /***
                    THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    
                    Also,
                    To handle errors like :
                    int x-y,z[10.5];
                ***/

               print_grammar_rule("declaration_list","declaration_list COMMA ID LTHIRD CONST_FLOAT RTHIRD");
           
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += ",";
                $$->text += $4->key;
                $$->text += "[";
                $$->text += $6->key;
                $$->text += "]";

                // update type
                $$->HelperType = $1->HelperType;

                // int & update vector
                $$->v = $1->v;
                $4->setVarType("array");
                $$->v.push_back($4);
                // $$->print();

                error_array_size_float();

                print_log_text($$->text);

                erm_h($1); 
                // erm_s($4); 
                erm_s($6);
           
            }
 		    | ID {     
                    print_grammar_rule("declaration_list","ID");

                    $$ = new Helper();

                    // update text
                    $$->text = $1->key;

                    // init vector
                    $$->v.push_back($1);

                    print_log_text($$->text);

                    // erm_s($1);
            }
 		    | ID LTHIRD CONST_INT RTHIRD {

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_INT RTHIRD");

                    $$ = new Helper();

                    // update text
                    $$->text = $1->key;
                    $$->text += "[";
                    $$->text += $3->key;
                    $$->text += "]";

                    // init vector
                    $1->setVarType("array");
                    $1->ara_size = stoi($3->key);
                    $$->v.push_back($1);
                    // cout<<"PRINT"<<endl;
                    // $$->print();

                    print_log_text($$->text);

                    // erm_s($1); 
                    erm_s($3);
            }
            | ID LTHIRD CONST_FLOAT RTHIRD {

                    /***
                        THIS IS AS EXTRA RULE ADDED TO CATCH ERROR
                    ***/

                    print_grammar_rule("declaration_list","ID LTHIRD CONST_FLOAT RTHIRD");

                    $$ = new Helper();

                    // update text
                    $$->text = $1->key;
                    $$->text += "[";
                    $$->text += $3->key;
                    $$->text += "]";

                    // init vector
                    $$->v.push_back($1);

                    error_array_size_float();

                    print_log_text($$->text);

                    // erm_s($1); 
                    erm_s($3);
           }
 		  ;
 		  
statements: statement {
            print_grammar_rule("statements","statement");
            
            $$ = new Helper();
            $$->text = $1->text;

            print_log_text($$->text);

            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);  
        }
	   | statements statement {
            print_grammar_rule("statements","statements statement");
        
            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "\n";
            $$->text += $2->text;

            print_log_text($$->text);

            $$->code = $1->code+"\n";
            $$->code += $2->code;

            erm_h($1);  erm_h($2);   
        }
        | statements error statement {
            print_grammar_rule("statements","statements statement");
        
            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "\n";
            $$->text += $3->text;

            print_log_text($$->text);

            erm_h($1);  erm_h($3);   
        }
        
	   ;
	   
statement: var_declaration {
            print_grammar_rule("statement","var_declaration");

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
        }
      | func_definition {
          print_grammar_rule("statement","func_definition");

            $$ = new Helper();
            $$->text = $1->text;

            print_log_text($$->text);
            error_nested_function();

            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
      }
      | func_declaration {
          print_grammar_rule("statement","func_declaration");

            $$ = new Helper();
            $$->text = $1->text;

            print_log_text($$->text);
            error_nested_function();

            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
      }
	  | expression_statement {
            print_grammar_rule("statement","expression_statement");

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            $$->code = "; "+$$->text+"\n";
            $$->code += $1->code;

            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
        }
	  | compound_statement {
            print_grammar_rule("statement","compound_statement");

            $$ = new Helper();
            $$->text = $1->text;

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
        }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
            print_grammar_rule("statement","FOR LPAREN expression_statement expression_statement expression RPAREN statement");

            $$ = new Helper();

            // update text
            $$->text = "for";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += $4->text;
            $$->text += $5->text;
            $$->text += ")";
            $$->text += $7->text;
            
            print_log_text($$->text);

            string tempL1 = newLabel();
            string tempL2 = newLabel();

            string to_print = $$->text;
            to_print.erase(remove(to_print.begin(), to_print.end(), '\n'), to_print.end());

            $$->code = "; "+to_print+"\n";

            $$->code += $3->code+"\n";

            $$->code += tempL1+":\n"; // loop starting label

            $$->code += "; "+$4->text+"\n";
            $$->code += $4->code+"\n"; // eval expression

            $$->code += "; check for loop condition\n";
            $$->code += "CMP "+ stk_address($4->stk_offset)+",0\n"; // check if need to exit
            $$->code += "JE "+tempL2+"\n"; // check if need to exit

            $$->code += $7->code+"\n";  // exec statement

            $$->code += "; "+$5->text+"\n";  // exec statement
            $$->code += $5->code+"\n";  // exec statement

            $$->code += "JMP "+tempL1+"\n"; // loop
            $$->code += tempL2+":\n"; // loop ending label


            erm_h($3); erm_h($4); erm_h($5); erm_h($7);
        }
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE { 
            print_grammar_rule("statement","IF LPAREN expression RPAREN statement");
            
            $$ = new Helper();
            // update text
            $$->text = "if";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;

            print_log_text($$->text);

            string to_print = $$->text;
            to_print.erase(remove(to_print.begin(), to_print.end(), '\n'), to_print.end());

            $$->code = "; "+to_print+"\n";

            $$->code += $3->code+"\n";
            
            string tempL1 = newLabel();
            $$->code += "CMP "+stk_address($3->stk_offset)+",0\n";
            $$->code += "JE "+tempL1+"\n";
            $$->code += $5->code+"\n";
            $$->code += tempL1+":\n";

            erm_h($3); erm_h($5); 
        }
	  | IF LPAREN expression RPAREN statement ELSE statement {

            print_grammar_rule("statement","IF LPAREN expression RPAREN statement ELSE statement");
        
            $$ = new Helper();
            // update text
            $$->text = "if";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;
            $$->text += "\nelse ";
            $$->text += $7->text;

            print_log_text($$->text);

            string to_print = $$->text;
            to_print.erase(remove(to_print.begin(), to_print.end(), '\n'), to_print.end());

            $$->code = "; "+to_print+"\n";

            $$->code += $3->code+"\n";
            
            string tempL1 = newLabel();
            string tempL2 = newLabel();

            $$->code += "CMP "+stk_address($3->stk_offset)+",0\n";
            $$->code += "JE "+tempL1+"\n";

            $$->code += $5->code+"\n";
            $$->code += "JMP "+tempL2+"\n";
            $$->code += tempL1+":\n";

            $$->code += $7->code+"\n";
            $$->code += tempL2+":\n";

            erm_h($3); erm_h($5); erm_h($7);
        
        }
	  | WHILE LPAREN expression RPAREN statement {
            print_grammar_rule("statement","WHILE LPAREN expression RPAREN statement");

            $$ = new Helper();
            // update text
            $$->text = "while";
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";
            $$->text += $5->text;

            print_log_text($$->text);

            string tempL1 = newLabel();
            string tempL2 = newLabel();

            string to_print = $$->text;
            to_print.erase(remove(to_print.begin(), to_print.end(), '\n'), to_print.end());

            $$->code = "; "+to_print+"\n";

            $$->code += tempL1+":\n"; // loop starting label

            $$->code += "; "+$3->text+"\n";
            $$->code += $3->code+"\n"; // eval expression

            $$->code += "; check while loop condition\n";
            $$->code += "CMP "+ stk_address($3->stk_offset) +",0\n"; // check if need to exit
            $$->code += "JE "+tempL2+"\n"; // check if need to exit

            $$->code += $5->code+"\n";  // exec statement

            $$->code += "JMP "+tempL1+"\n"; // loop
            $$->code += tempL2+":\n"; // loop ending label

            erm_h($3); erm_h($5); 
        }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");

            $$ = new Helper();
            $$->text = "printf";
            $$->text += "(";
            $$->text += $3->key;
            $$->text += ")";
            $$->text += ";";

            print_log_text($$->text);

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($3->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($3->key);
                $$->setHelperType("NULL");
            }

            $$->code = "\n; "+$$->text+"\n";
            
            if(ret_symbol != NULL && ret_symbol->stk_offset != "") $$->code += "MOV AX,"+stk_address(ret_symbol->stk_offset)+"\n";
            else $$->code += "MOV AX,"+$3->key+"\n";
            
            $$->code += "MOV FOR_PRINT,AX\n";
            $$->code += "CALL OUTPUT";
            
            erm_s($3);
        }
        | PRINTLN LPAREN ID LTHIRD expression RTHIRD RPAREN SEMICOLON {
            print_grammar_rule("statement","PRINTLN LPAREN ID RPAREN SEMICOLON");

            $$ = new Helper();
            $$->text = "printf";
            $$->text += "(";
            $$->text += $3->key;
            $$->text += "[";
            $$->text += $5->text;
            $$->text += "]";
            $$->text += ")";
            $$->text += ";";

            print_log_text($$->text);

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($3->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($3->key);
                $$->setHelperType("NULL");
            }

            if(ret_symbol != NULL)
            {
                $$->code = "\n; "+$$->text+"\n";

                // code

                $$->code += $5->code+"\n";
                $$->stk_offset = ret_symbol->stk_offset+"+SI";

                if(ret_symbol->stk_offset != "")
                {
                    $$->code += "MOV SI,"+stk_address($5->stk_offset)+"\n";
                    $$->code += "ADD SI,SI\n";
                    $$->code += "MOV AX,"+stk_address($$->stk_offset)+"\n";
                }
                else
                {   $$->code += "MOV BX,"+stk_address($5->stk_offset)+"\n";
                    $$->code += "ADD BX,BX\n";
                    $$->code += "MOV AX,"+$3->key+"[BX]\n";
                }

                $$->code += "MOV FOR_PRINT,AX\n";
                $$->code += "CALL OUTPUT";
            }
        
            
            erm_s($3);
        }
	  | RETURN expression SEMICOLON {
            print_grammar_rule("statement","RETURN expression SEMICOLON");

            $$ = new Helper();
            $$->text = "return";
            $$->text += " ";
            $$->text += $2->text;
            $$->text += ";";

            print_log_text($$->text);

            $$->code = "; "+$$->text+"\n";
            $$->code += $2->code+"\n";
            
            if($2->stk_offset != "") $$->code += "MOV AX,"+stk_address($2->stk_offset)+"\n";
            else {
                $$->code += "MOV AX,"+ process_global_variable($2->text)+"\n";
            } 

            $$->code += "JMP "+cur_function_label(cur_function_name)+"\n";

            //$$->code += "POP BP\n";
            //$$->code += "RET";

            erm_h($2); 
        }
        | RETURN SEMICOLON {

            /***
                EXTRA RULE ADDED 
            ***/

            print_grammar_rule("statement","RETURN SEMICOLON");

            $$ = new Helper();
            $$->text = "return";
            $$->text += ";";

            print_log_text($$->text);

            $$->code = "JMP "+cur_function_label(cur_function_name)+"\n";
            //$$->code += "RET";
        }
	  ;
	  
expression_statement: SEMICOLON	{
                    print_grammar_rule("expression_statement","SEMICOLON");

                    $$ = new Helper();
                    $$->text = ";";

                    print_log_text($$->text);

                }		
			| expression SEMICOLON {
                    print_grammar_rule("expression_statement","expression SEMICOLON");
                    
                    $$ = new Helper();

                    // update text
                    $$->text = $1->text;
                    $$->text += ";";

                    print_log_text($$->text);

                    $$->code = $1->code;
                    $$->tempVar = $1->tempVar;
                    $$->stk_offset = $1->stk_offset;

                    erm_h($1);
                }
			;
	  
variable: ID { 
            print_grammar_rule("variable","ID");
            $$ = new Helper();

            // update text
            $$->text = $1->key;

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($1->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($1->key);
                $$->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int_array" || ret_symbol->var_type == "float_array")
                {
                    error_type_mismatch(ret_symbol->key + " is an array"); // should i change this to indexing
                    $$->setHelperType("NULL");
                }
                else{
                    $$->setHelperType(ret_symbol->var_type);
                }
                //  cout<<"Helper : "<<$$->HelperType<<endl;
            }

            print_log_text($$->text);


            $$->code = "";
            $$->tempVar = $1->key;

            if(ret_symbol != NULL) $$->stk_offset = ret_symbol->stk_offset;

            erm_s($1);
        }		
	 | ID LTHIRD expression RTHIRD {
            print_grammar_rule("variable","ID LTHIRD expression RTHIRD");
            
            $$ = new Helper();

            // update text
            $$->text = $1->key;
            $$->text += "[";
            $$->text += $3->text;
            $$->text += "]";

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($1->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_variable($1->key);
                $$->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->var_type == "int" || ret_symbol->var_type == "float")
                {
                    error_not_array(ret_symbol->key);
                    $$->setHelperType("NULL");
                }
                else{
                    $$->setHelperType(ret_symbol->var_type);
                }
                // cout<<"HelperType : "<<$$->HelperType<<endl;
            }

            if($3->HelperType != "int")
            {
                error_array_index_invalid();
            }

            print_log_text($$->text);

            if(ret_symbol != NULL)
            {
                // code

                $$->code = $3->code+"\n";

                if(ret_symbol->stk_offset!="")
                {
                    $$->code += "MOV SI,"+stk_address($3->stk_offset)+"\n";
                    $$->code += "ADD SI,SI";
                    $$->stk_offset = ret_symbol->stk_offset+"+SI";
                }
                else
                {
                    $$->code += "MOV BX,"+stk_address($3->stk_offset)+"\n";
                    $$->code += "ADD BX,BX";
                    //$$->stk_offset = ret_symbol->stk_offset+"+SI";
                }
            }

            erm_h($3);
            erm_s($1);
         }
	 ;
	 
 expression: logic_expression	{
                print_grammar_rule("expression","logic_expression");

                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // update vector : push up
                $$->HelperType = $1->HelperType;

                // $$->code = "; "+$1->text+"\n";
                $$->code = $1->code;
                $$->tempVar = $1->tempVar;
                $$->stk_offset = $1->stk_offset;

                print_log_text($$->text);

                erm_h($1);
            }
	   | variable ASSIGNOP logic_expression {
                print_grammar_rule("expression","variable ASSIGNOP logic_expression");
                
                $$ = new Helper();

                // update text
                $$->text = $1->text;
                $$->text += "=";
                $$->text += $3->text;

                //check error
                // cout<<$1->HelperType<<" ---- "<<$3->HelperType<<endl;
                if(!check_assignop($1->HelperType,$3->HelperType))
                {
                    if($1->HelperType=="void" || $3->HelperType=="void")
                    {
                        error_type_cast_void();
                    }
                    else
                    {
                        error_type_mismatch();
                    }
                }

                print_log_text($$->text);

                // code
                
                $$->code = $3->code+"\n";

                if($3->stk_offset != "") $$->code += "MOV CX,"+stk_address($3->stk_offset)+"\n";
                else $$->code += "MOV CX,"+process_global_variable($3->text)+"\n";

                if($1->code != "") $$->code += $1->code+"\n";

                if($1->stk_offset != "") $$->code += "MOV "+stk_address_typecast($1->stk_offset)+",CX";
                else $$->code += "MOV "+process_global_variable($1->text)+",CX";

                erm_h($1); erm_h($3);
            }	
	   ;


			 
logic_expression: rel_expression {
                print_grammar_rule("logic_expression","rel_expression");

                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // update vector : push up
                $$->HelperType = $1->HelperType;

                print_log_text($$->text);

                $$->code = $1->code;
                $$->tempVar = $1->tempVar;
                $$->stk_offset = $1->stk_offset;

                erm_h($1); 
            }	
		 | rel_expression LOGICOP rel_expression {
                print_grammar_rule("logic_expression","rel_expression LOGICOP rel_expression");
                
                $$ = new Helper();
                // update text
                $$->text = $1->text;
                $$->text += $2->key;
                $$->text += $3->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);

                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") $$->setHelperType("int"); // ALWAYS INT
                    else {

                        if($1->HelperType=="void" || $3->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         $$->setHelperType("NULL");
                    }
                    
                    // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                }
                else
                {
                    $$->setHelperType("NULL");
                }

                print_log_text($$->text);

                if($2->key == "&&")
                {
                    // code for &&
                    $$->code = $1->code+"\n";
                    $$->code += $3->code+"\n";

                    if($1->stk_offset != "") $$->code += "CMP "+ stk_address($1->stk_offset)+",0\n";
                    else  $$->code += "CMP "+ process_global_variable($1->text)+",0\n";

                    string tempL1 = newLabel();
                    string tempL2 = newLabel();

                    $$->code += "JE "+tempL1+"\n";

                    if($3->stk_offset != "") $$->code += "CMP "+stk_address($3->stk_offset)+",0\n";
                    else $$->code += "CMP "+process_global_variable($3->text)+",0\n";

                    $$->code += "JE "+tempL1+"\n";

                    if(isATempVariable($1->stk_offset))
                    {
                        $$->stk_offset = $1->stk_offset;
                    }
                    else if(isATempVariable($3->stk_offset))
                    {
                        $$->stk_offset = $3->stk_offset;
                    }
                    else
                    {
                        string tempVar = newTemp();

                        $$->tempVar = tempVar;
                        $$->stk_offset = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                    }

                    $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",1\n";
                    $$->code += "JMP "+tempL2+"\n";
                    $$->code += tempL1+":\n";

                    $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",0\n";
                    $$->code += tempL2+":\n";
                    
                }
                else if($2->key == "||")
                {
                    // code for ||
                    $$->code = $1->code+"\n";
                    $$->code += $3->code+"\n";

                    if($1->stk_offset != "") $$->code += "CMP "+stk_address($1->stk_offset)+",0\n";
                    else  $$->code += "CMP "+process_global_variable($1->text)+",0\n";

                    string tempL1 = newLabel();
                    string tempL2 = newLabel();

                    $$->code += "JNE "+tempL1+"\n";

                    if($3->stk_offset != "") $$->code += "CMP "+stk_address($3->stk_offset)+",0\n";
                    else $$->code += "CMP "+process_global_variable($3->text)+",0\n";

                    $$->code += "JNE "+tempL1+"\n";

                    if(isATempVariable($1->stk_offset))
                    {
                        $$->stk_offset = $1->stk_offset;
                    }
                    else if(isATempVariable($3->stk_offset))
                    {
                        $$->stk_offset = $3->stk_offset;
                    }
                    else
                    {
                        string tempVar = newTemp();

                        $$->tempVar = tempVar;
                        $$->stk_offset = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                    }

                    $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",0\n";
                    $$->code += "JMP "+tempL2+"\n";
                    $$->code += tempL1+":\n";

                    $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",1\n";
                    $$->code += tempL2+":\n";

                }

                erm_h($1); erm_h($3);
                erm_s($2);
            }	
		 ;
			
rel_expression: simple_expression {
                print_grammar_rule("rel_expression","simple_expression");

                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // update vector : push up
                $$->HelperType = $1->HelperType;

                print_log_text($$->text);

                $$->code = $1->code;
                $$->tempVar = $1->tempVar;
                $$->stk_offset = $1->stk_offset;

                erm_h($1);
            }
		| simple_expression RELOP simple_expression	{
                print_grammar_rule("rel_expression","simple_expression RELOP simple_expression");
                
                $$ = new Helper();
                // update text
                $$->text = $1->text;
                $$->text += $2->key;
                $$->text += $3->text;

                // do implicit typecast
                string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);

                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") $$->setHelperType("int"); // ALWAYS INT
                    else {

                        if($1->HelperType=="void" || $3->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         $$->setHelperType("NULL");
                    }
                    // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                }
                else
                {
                    $$->setHelperType("NULL");
                }

                string jumpText = getJumpText($2->key);

                // code 
                $$->code = $1->code+"\n";
                $$->code += $3->code+"\n";

                if($1->stk_offset != "") $$->code += "MOV AX,"+stk_address($1->stk_offset)+"\n";
                else $$->code += "MOV AX,"+process_global_variable($1->text)+"\n";

                if($3->stk_offset != "") $$->code += "CMP AX,"+stk_address($3->stk_offset)+"\n";
                else $$->code += "CMP AX,"+process_global_variable($3->text)+"\n";

                string tempL1 = newLabel();
                string tempL2 = newLabel();

                if(isATempVariable($1->stk_offset))
                {
                    $$->stk_offset = $1->stk_offset;
                }
                else if(isATempVariable($3->stk_offset))
                {
                    $$->stk_offset = $3->stk_offset;
                }
                else
                {
                    string tempVar = newTemp();

                    $$->tempVar = tempVar;
                    $$->stk_offset = to_string(SP_VAL);
                    // // temp_SP_vector.push_back(to_string(SP_VAL));
                }

                $$->code += jumpText+" "+tempL1+"\n";
                $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",0"+"\n";
                $$->code += "JMP "+tempL2+"\n";
                $$->code += tempL1+":\n";
                $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",1"+"\n";
                $$->code += tempL2+":\n";

                print_log_text($$->text);

                erm_h($1); erm_h($3);
                erm_s($2);
            }
		;
				
simple_expression: term {

                    print_grammar_rule("simple_expression","term");

                    $$ = new Helper();
                    // update text
                    $$->text = $1->text;
                    // update vector : push up
                    $$->HelperType = $1->HelperType;

                    print_log_text($$->text);

                    $$->code = $1->code;
                    $$->tempVar = $1->tempVar;
                    $$->stk_offset = $1->stk_offset;

                    erm_h($1);
            }
		    |   simple_expression ADDOP term {
                    print_grammar_rule("simple_expression","simple_expression ADDOP term");

                    $$ = new Helper();
                    // update text
                    $$->text = $1->text;
                    $$->text += $2->key;
                    $$->text += $3->text;
                    // do implicit typecast
                    // cout<<$1->HelperType<<" --- "<<$3->HelperType<<endl;
                    string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);

                    if(typecast_ret != "NULL")
                    {
                        if(typecast_ret != "error") $$->setHelperType(typecast_ret);
                        else {

                        if($1->HelperType=="void" || $3->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         $$->setHelperType("NULL");
                        }
                        // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                    }
                    else
                    {
                        $$->setHelperType("NULL");
                    }

                    print_log_text($$->text);

                    if($2->key=="+")
                    {
                        // code for +
                        $$->code = $1->code+"\n";
                        
                        if($1->stk_offset!="") $$->code += "MOV AX,"+stk_address($1->stk_offset)+"\n";
                        else $$->code += "MOV AX,"+process_global_variable($1->text)+"\n";

                        string tempVarExtra = newTemp();
                        string tempVarExtra_stk_add = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                        $$->code += "MOV "+stk_address_typecast(tempVarExtra_stk_add)+",AX\n";

                        $$->code += $3->code+"\n";

                        $$->code += "MOV AX,"+stk_address(tempVarExtra_stk_add)+"\n";

                        if($3->stk_offset!="") $$->code += "ADD AX,"+stk_address($3->stk_offset)+"\n";
                        else $$->code += "ADD AX,"+process_global_variable($3->text)+"\n";

                        if(isATempVariable($1->stk_offset))
                        {
                            $$->stk_offset = $1->stk_offset;
                        }
                        else if(isATempVariable($3->stk_offset))
                        {
                            $$->stk_offset = $3->stk_offset;
                        }
                        else
                        {
                            string tempVar = newTemp();

                            $$->tempVar = tempVar;
                            $$->stk_offset = to_string(SP_VAL);
                            // temp_SP_vector.push_back(to_string(SP_VAL));
                        }

                        $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",AX";
                    }
                    else
                    {
                        // code for -
                        $$->code = $1->code+"\n";
                        
                        if($1->stk_offset!="") $$->code += "MOV AX,"+stk_address($1->stk_offset)+"\n";
                        else $$->code += "MOV AX,"+process_global_variable($1->text)+"\n";

                        string tempVarExtra = newTemp();
                        string tempVarExtra_stk_add = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                        $$->code += "MOV "+stk_address_typecast(tempVarExtra_stk_add)+",AX\n";

                        $$->code += $3->code+"\n";
                        
                        $$->code += "MOV AX,"+stk_address(tempVarExtra_stk_add)+"\n";
                        
                        if($3->stk_offset!="") $$->code += "SUB AX,"+stk_address($3->stk_offset)+"\n";
                        else $$->code += "SUB AX,"+process_global_variable($3->text)+"\n";

                        if(isATempVariable($1->stk_offset))
                        {
                            $$->stk_offset = $1->stk_offset;
                        }
                        else if(isATempVariable($3->stk_offset))
                        {
                            $$->stk_offset = $3->stk_offset;
                        }
                        else
                        {
                            string tempVar = newTemp();

                            $$->tempVar = tempVar;
                            $$->stk_offset = to_string(SP_VAL);
                            // temp_SP_vector.push_back(to_string(SP_VAL));
                        }

                        $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",AX";
                    }

                    

                    erm_h($1); erm_h($3);
                    erm_s($2);
            }
		    ;
					
term:	unary_expression {

            print_grammar_rule("term","unary_expression");

            $$ = new Helper();
            // update text
            $$->text = $1->text;
            // update vector : push up
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            $$->code = $1->code;
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
    }
    |  term MULOP unary_expression {

            print_grammar_rule("term","term MULOP unary_expression");

            $$ = new Helper();
            // update text
            $$->text = $1->text;
            $$->text += $2->key;
            $$->text += $3->text;
            // implicit typecast
            string typecast_ret = do_implicit_typecast($1->HelperType,$3->HelperType);

            if($2->key == "%") // both operand should be integer
            {
                if($3->text == "0")
                {
                    error_type_cast_mod_zero();
                    $$->setHelperType("NULL");
                }
                else
                {
                    if(typecast_ret != "int")
                    {
                        error_type_cast_mod();
                        $$->setHelperType("NULL");
                    }
                    else{
                        $$->setHelperType("int");
                        // cout<<"HERERE"<<endl;

                        // code
                        $$->code = $1->code+"\n";
                        

                        if($1->stk_offset!="") $$->code += "MOV CX,"+ stk_address($1->stk_offset)+"\n";
                        else $$->code += "MOV CX,"+process_global_variable($1->text)+"\n";
                        
                        $$->code += "CWD\n";

                        string tempVarExtra = newTemp();
                        string tempVarExtra_stk_add = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                        $$->code += "MOV "+stk_address_typecast(tempVarExtra_stk_add)+",CX\n";

                        $$->code += $3->code+"\n";
                        
                        $$->code += "MOV CX,"+stk_address(tempVarExtra_stk_add)+"\n";

                        $$->code += "MOV AX,CX\n"; /// speacial case to handle noth array and normal variable

                        if($3->stk_offset!="") $$->code += "IDIV "+stk_address_typecast($3->stk_offset)+"\n";
                        else $$->code += "IDIV "+process_global_variable($3->text)+"\n";

                        if(isATempVariable($1->stk_offset))
                        {
                            $$->stk_offset = $1->stk_offset;
                        }
                        else if(isATempVariable($3->stk_offset))
                        {
                            $$->stk_offset = $3->stk_offset;
                        }
                        else
                        {
                            string tempVar = newTemp();

                            $$->tempVar = tempVar;
                            $$->stk_offset = to_string(SP_VAL);
                            // temp_SP_vector.push_back(to_string(SP_VAL));
                        }


                        $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",DX";
                    }
                }
            }
            else
            {
                if(typecast_ret != "NULL")
                {
                    if(typecast_ret != "error") $$->setHelperType(typecast_ret);
                    else {

                        if($1->HelperType=="void" || $3->HelperType=="void")
                        {
                            error_type_cast_void();
                        }
                        else
                        {
                            error_type_cast();
                        }

                         $$->setHelperType("NULL");
                    }
                    // cout<<"Implicit Typecast : "<<$$->HelperType<<"\n"<<endl;
                }
                else
                {
                    $$->setHelperType("NULL");
                }

                if($2->key == "*")
                {
                    // code for *
                    $$->code = $1->code+"\n";

                    if($1->stk_offset!="") $$->code += "MOV CX,"+stk_address($1->stk_offset)+"\n";
                    else $$->code += "MOV CX,"+process_global_variable($1->text)+"\n";

                    string tempVarExtra = newTemp();
                    string tempVarExtra_stk_add = to_string(SP_VAL);
                    // temp_SP_vector.push_back(to_string(SP_VAL));
                    $$->code += "MOV "+stk_address_typecast(tempVarExtra_stk_add)+",CX\n";

                    $$->code += $3->code+"\n";
                    
                    $$->code += "MOV CX,"+stk_address(tempVarExtra_stk_add)+"\n";

                    $$->code += "MOV AX,CX\n"; /// speacial case to handle noth array and normal variable

                    if($3->stk_offset!="") $$->code += "IMUL "+stk_address_typecast($3->stk_offset)+"\n";
                    else $$->code += "IMUL "+process_global_variable($3->text)+"\n";

                    if(isATempVariable($1->stk_offset))
                    {
                        $$->stk_offset = $1->stk_offset;
                    }
                    else if(isATempVariable($3->stk_offset))
                    {
                        $$->stk_offset = $3->stk_offset;
                    }
                    else
                    {
                        string tempVar = newTemp();

                        $$->tempVar = tempVar;
                        $$->stk_offset = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                    }

                    $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",AX";
                }
                else if($2->key == "/")
                {
                    // code
                    $$->code = $1->code+"\n";

                    if($1->stk_offset!="") $$->code += "MOV CX,"+ stk_address($1->stk_offset)+"\n";
                    else $$->code += "MOV CX,"+ process_global_variable($1->text)+"\n";
                    
                    $$->code += "CWD\n";

                    string tempVarExtra = newTemp();
                    string tempVarExtra_stk_add = to_string(SP_VAL);
                    // temp_SP_vector.push_back(to_string(SP_VAL));
                    $$->code += "MOV "+stk_address_typecast(tempVarExtra_stk_add)+",CX\n";

                    $$->code += $3->code+"\n";
                    
                    $$->code += "MOV CX,"+stk_address(tempVarExtra_stk_add)+"\n";

                    $$->code += "MOV AX,CX\n"; /// speacial case to handle noth array and normal variable

                    if($3->stk_offset!="") $$->code += "IDIV "+stk_address_typecast($3->stk_offset)+"\n";
                    else $$->code += "IDIV "+process_global_variable($3->text)+"\n";

                    if(isATempVariable($1->stk_offset))
                    {
                        $$->stk_offset = $1->stk_offset;
                    }
                    else if(isATempVariable($3->stk_offset))
                    {
                        $$->stk_offset = $3->stk_offset;
                    }
                    else
                    {
                        string tempVar = newTemp();

                        $$->tempVar = tempVar;
                        $$->stk_offset = to_string(SP_VAL);
                        // temp_SP_vector.push_back(to_string(SP_VAL));
                    }

                    $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",AX";
                }
            }

            print_log_text($$->text);

            erm_h($1); erm_h($3);
            erm_s($2);
    }
    ;

unary_expression: ADDOP unary_expression  {
                print_grammar_rule("unary_expression","ADDOP unary_expression");
                
                $$ = new Helper();
                // update text
                $$->text = $1->key;
                $$->text += $2->text;
                // implicit typecast
                $$->HelperType = $2->HelperType;

                print_log_text($$->text);

                if($1->key == "+")
                {
                    $$->code = $2->code;
                    $$->tempVar = $2->tempVar;
                    $$->stk_offset = $2->stk_offset;
                }
                else
                {
                    $$->code = $2->code+"\n";
                    $$->code += "NEG "+stk_address_typecast($2->stk_offset);

                    $$->tempVar = $2->tempVar;
                    $$->stk_offset = $2->stk_offset;
                }

                erm_h($2);
                erm_s($1);
            }
		    | NOT unary_expression {
                print_grammar_rule("unary_expression","NOT unary_expression");
                
                $$ = new Helper();
                // update text
                $$->text = "!";
                $$->text += $2->text;
                // implicit typecast
                $$->HelperType = $2->HelperType;

                print_log_text($$->text);

                $$->stk_offset = $2->stk_offset;

                $$->code = $2->code+"\n";
                $$->code += "CMP "+stk_address($2->stk_offset)+",0\n";

                string tempL1 = newLabel();
                string tempL2 = newLabel();

                $$->code += "JE "+tempL1+"\n";

                $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",0\n";
                $$->code += "JMP "+tempL2+"\n";

                $$->code += tempL1+":\n";
                $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",1\n";

                $$->code += tempL2+":\n";

                $$->tempVar = $2->tempVar;

                erm_h($2);
            }
		    | factor  { 
                print_grammar_rule("unary_expression","factor");
                
                $$ = new Helper();
                // update text
                $$->text = $1->text;
                // implicit typecast
                $$->HelperType = $1->HelperType;

                print_log_text($$->text);

                $$->code = $1->code;
                $$->tempVar = $1->tempVar;
                $$->stk_offset = $1->stk_offset;

                erm_h($1);
            }
		 ;
	
factor: variable {

            print_grammar_rule("factor","variable");

            $$ = new Helper();
            // update text
            $$->text = $1->text;
            // implicit typecast
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            $$->code = $1->code;
            $$->tempVar = $1->text; // no operation , so tempVar is realVar
            $$->stk_offset = $1->stk_offset;

            erm_h($1);
        }
	| ID LPAREN argument_list RPAREN {

            print_grammar_rule("factor","ID LPAREN argument_list RPAREN");

            $$ = new Helper();
            // update text
            $$->text = $1->key;
            $$->text += "(";
            $$->text += $3->text;
            $$->text += ")";

            // check error
            SymbolInfo* ret_symbol = sym_tab->lookup($1->key);

            if(ret_symbol == NULL)
            {
                error_undeclared_function($1->key);
                $$->setHelperType("NULL");
            }
            else
            {
                if(ret_symbol->isFunction == false)
                {
                    $$->setHelperType("NULL");
                    error_not_function($1->key);
                    break;
                }

                $$->setHelperType(ret_symbol->var_type);

                if(ret_symbol->isFunctionDeclaration) // only declared , no definition
                {
                    error_function_not_implemented();
                }
                else // other errors
                {
                    if(ret_symbol->param_v.size() != $3->param_v.size())
                    {
                        error_function_parameter_number(ret_symbol->key);
                    }
                    else
                    {
                        for(int i=0;i<ret_symbol->param_v.size();i++)
                        {
                            if(!is_param_typecast_ok(ret_symbol->param_v[i],$3->param_v[i])){
                                error_function_parameter_type(i+1,ret_symbol->key);
                                break;
                            }
                        }
                    }
                }
            }

            print_log_text($$->text);

            if(ret_symbol != NULL)
            {
                //code 

                $$->code = $3->code+"\n";
                $$->code += "CALL "+$1->key+"\n";
                $$->code += "ADD SP,"+to_string(2*ret_symbol->param_v.size());

                if(ret_symbol->var_type != "void")
                {
                    string tempVar = newTemp();
                    $$->stk_offset = to_string(SP_VAL);
                    // // temp_SP_vector.push_back(to_string(SP_VAL));
                    $$->code += "\nMOV "+stk_address_typecast($$->stk_offset)+",AX";
                }
            }

            
            erm_h($3);
            erm_s($1);
        }
	| LPAREN expression RPAREN {

            print_grammar_rule("factor","LPAREN expression RPAREN");

            $$ = new Helper();
            // update text
            $$->text = "(";
            $$->text += $2->text;
            $$->text += ")";

            $$->HelperType = $2->HelperType;

            $$->code = $2->code;
            $$->tempVar = $2->tempVar;
            $$->stk_offset = $2->stk_offset;

            print_log_text($$->text);

            erm_h($2);
        
        }
	| CONST_INT  { 
            print_grammar_rule("factor","CONST_INT");

            // update text
            $$ = new Helper();
            $$->text = $1->key;

            // pass up
            $$->setHelperType("int");

            print_log_text($$->text);

            // code
            string tempVar = newTemp();
            
            $$->tempVar = tempVar; // init
            $$->stk_offset = to_string(SP_VAL);
            temp_SP_vector.push_back(to_string(SP_VAL));
            $$->code = "MOV "+stk_address_typecast($$->stk_offset)+","+$1->key;

            erm_s($1);
        }
	| CONST_FLOAT  { 
            print_grammar_rule("factor","CONST_FLOAT");

            $$ = new Helper();
            // update text
            $$->text = $1->key;
            // pass up
            $$->setHelperType("float");

            print_log_text($$->text);

            erm_s($1);
        }
    | ERROR_FLOAT  { 
            print_grammar_rule("factor","ERROR_FLOAT");

            $$ = new Helper();
            // update text
            $$->text = $1->key;
            // pass up
            $$->setHelperType("NULL");

            print_log_text($$->text);

            erm_s($1);
        }
	| variable INCOP {
            print_grammar_rule("factor","variable INCOP");

            $$ = new Helper();
          
            $$->text = $1->text;
            $$->text += "++";

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            /**
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;
            $$->code = "INC "+stk_address_typecast($$->stk_offset);
            **/

            /// as postfix , passing the previous value
            $$->tempVar = newTemp();
            $$->stk_offset = to_string(SP_VAL); // init 
            //// temp_SP_vector.push_back(to_string(SP_VAL));

            $$->code = $1->code+"\n";

            if($1->stk_offset != "") $$->code += "MOV AX,"+stk_address($1->stk_offset)+"\n";
            else $$->code += "MOV AX,"+process_global_variable($1->text)+"\n";
            
            $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",AX\n";

            if($1->stk_offset != "") $$->code += "INC "+stk_address_typecast($1->stk_offset); // actual variable
            else $$->code += "INC "+process_global_variable($1->text); // actual variable

            erm_h($1);
        }
	| variable DECOP {
            print_grammar_rule("factor","variable DECOP");

            $$ = new Helper();
            $$->text = $1->text;
            $$->text += "--";

            // update type
            $$->HelperType = $1->HelperType;

            print_log_text($$->text);

            /**
            $$->tempVar = $1->tempVar;
            $$->stk_offset = $1->stk_offset;
            $$->code = "DEC "+stk_address_typecast($$->stk_offset);
            **/

            /// as postfix , passing the previous value
            $$->tempVar = newTemp();
            $$->stk_offset = to_string(SP_VAL); // init 
            //// temp_SP_vector.push_back(to_string(SP_VAL));

            $$->code = $1->code+"\n";

            if($1->stk_offset != "") $$->code += "MOV AX,"+stk_address($1->stk_offset)+"\n";
            else $$->code += "MOV AX,"+process_global_variable($1->text)+"\n";
            
            $$->code += "MOV "+stk_address_typecast($$->stk_offset)+",AX\n";

            if($1->stk_offset != "") $$->code += "DEC "+stk_address_typecast($1->stk_offset); // actual variable
            else $$->code += "DEC "+process_global_variable($1->text); // actual variable

            erm_h($1);
        }
	;
	
argument_list: arguments {

                    print_grammar_rule("argument_list","arguments");

                    $$ = new Helper();
                    $$->text = $1->text;

                    $$->param_v = $1->param_v; 

                    print_log_text($$->text);

                    $$->code = $1->code;
                    $$->tempVar = $1->tempVar;
                    $$->stk_offset = $1->stk_offset;

                    erm_h($1);
                }
			| {
                print_grammar_rule("argument_list","");
                $$ = new Helper();
            }   
			;
	
arguments: arguments COMMA logic_expression {

                print_grammar_rule("arguments","arguments COMMA logic_expression");
                
                $$ = new Helper();
                $$->text = $1->text; 
                $$->text += ","; 
                $$->text += $3->text;

                // update vector
                $$->param_v = $1->param_v; 
                $$->param_v.push_back($3->HelperType);

                print_log_text($$->text);

                $$->code = $3->code+"\n";
                if($3->stk_offset != "") $$->code += "PUSH "+stk_address($3->stk_offset)+"\n";
                else $$->code += "PUSH "+$3->text+"\n";

                $$->code += $1->code;
                

                erm_h($1); erm_h($3);
            }
	    | logic_expression {

                print_grammar_rule("arguments","logic_expression");

                $$ = new Helper();

                // update text
                $$->text = $1->text; 
                // update helper type
                $$->HelperType = $1->HelperType;
                // cout<<"Logic Helper : "<<$$->HelperType<<endl;
                // init vector
                $$->param_v.push_back($1->HelperType);

                print_log_text($$->text);

                $$->stk_offset = $1->stk_offset;
                $$->tempVar = $1->tempVar;

                $$->code = $1->code+"\n";

                if($$->stk_offset != "") $$->code += "PUSH "+stk_address($$->stk_offset);
                else $$->code += "PUSH "+$1->text+"\n";
                

                erm_h($1);
            }
	    ;

%%

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
	opt_codeout.open("optimized_code.asm");

    DATA_vector.push_back("IS_NEG DB ?");
    DATA_vector.push_back("FOR_PRINT DW ?");
    DATA_vector.push_back("CR EQU 0DH\nLF EQU 0AH\nNEWLINE DB CR, LF , '$'");


    yyin=fin;
	yyparse();

    sym_tab->print_all_scope(logout);

    logout<<"Total lines: "<<line_count<<endl;
    logout<<"Total errors: "<<err_count<<endl;

    fclose(yyin);

    logout.close();
	errout.close();
	codeout.close();
	opt_codeout.close();

    exit(0);
}
