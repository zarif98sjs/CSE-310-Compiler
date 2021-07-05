
#include "SymbolInfo.h"

SymbolInfo::SymbolInfo(){
    
    isFunctionDeclaration = false;
    isFunction = false;

    var_type = "";
    stk_offset = "";
}

SymbolInfo::SymbolInfo(string key,string val)
{
    this->key = key;
    this->val = val;
    this->nxt = NULL;

    bucket = -1;
    bucket_pos = 0;
    ara_size = 0;

    var_type = "";
    stk_offset = "";
}

SymbolInfo::SymbolInfo(string key,string val,string var_type,string stk_offset,int ara_size,vector<string>param_v,bool isFunctionDeclaration,bool isFunction)
{
    this->key = key;
    this->val = val;
    this->var_type = var_type;
    this->stk_offset = stk_offset;
    this->ara_size = ara_size;
    this->param_v = param_v;
    this->isFunctionDeclaration = isFunctionDeclaration;
    this->isFunction = isFunction;
    this->nxt = NULL;

    bucket = -1;
    bucket_pos = 0;
}


/////////////////////////////////////////////////////////

SymbolInfo::SymbolInfo(string key,string val,string var_type,string stk_offset,int ara_size,vector<string>param_v,bool isFunctionDeclaration,bool isFunction,SymbolInfo* nxt)
{
    this->key = key;
    this->val = val;
    this->var_type = var_type;
    this->stk_offset = stk_offset;
    this->ara_size = ara_size;
    this->param_v = param_v;
    this->isFunctionDeclaration = isFunctionDeclaration;
    this->isFunction = isFunction;
    this->nxt = nxt;
    this->bucket = bucket;
    this->bucket_pos = bucket_pos;
}


void SymbolInfo::setVarType(string var_type){
    this->var_type = var_type;
}