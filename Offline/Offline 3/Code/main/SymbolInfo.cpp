
#include "SymbolInfo.h"

SymbolInfo::SymbolInfo(){
    isFunctionDeclaration = false;
    isFunction = false;
}

SymbolInfo::SymbolInfo(string key,string val)
{
    this->key = key;
    this->val = val;
    this->nxt = NULL;

    bucket = -1;
    bucket_pos = 0;
}

// SymbolInfo::SymbolInfo(string key,string val,string var_type)
// {
//     this->key = key;
//     this->val = val;
//     this->var_type = var_type;
//     this->nxt = NULL;

//     bucket = -1;
//     bucket_pos = 0;
// }

// SymbolInfo::SymbolInfo(string key,string val,string var_type,vector<string>param_v)
// {
//     this->key = key;
//     this->val = val;
//     this->var_type = var_type;
//     this->param_v = param_v;
//     this->nxt = NULL;

//     bucket = -1;
//     bucket_pos = 0;
// }

SymbolInfo::SymbolInfo(string key,string val,string var_type,vector<string>param_v,bool isFunctionDeclaration,bool isFunction)
{
    this->key = key;
    this->val = val;
    this->var_type = var_type;
    this->param_v = param_v;
    this->isFunctionDeclaration = isFunctionDeclaration;
    this->isFunction = isFunction;
    this->nxt = NULL;

    bucket = -1;
    bucket_pos = 0;
}


/////////////////////////////////////////////////////////


// SymbolInfo::SymbolInfo(string key,string val,SymbolInfo* nxt)
// {
//     this->key = key;
//     this->val = val;
//     this->nxt = nxt;
//     this->bucket = bucket;
//     this->bucket_pos = bucket_pos;
// }

// SymbolInfo::SymbolInfo(string key,string val,string var_type,SymbolInfo* nxt)
// {
//     this->key = key;
//     this->val = val;
//     this->var_type = var_type;
//     this->nxt = nxt;
//     this->bucket = bucket;
//     this->bucket_pos = bucket_pos;
// }

// SymbolInfo::SymbolInfo(string key,string val,string var_type,vector<string>param_v,SymbolInfo* nxt)
// {
//     this->key = key;
//     this->val = val;
//     this->var_type = var_type;
//     this->param_v = param_v;
//     this->nxt = nxt;
//     this->bucket = bucket;
//     this->bucket_pos = bucket_pos;
// }

SymbolInfo::SymbolInfo(string key,string val,string var_type,vector<string>param_v,bool isFunctionDeclaration,bool isFunction,SymbolInfo* nxt)
{
    this->key = key;
    this->val = val;
    this->var_type = var_type;
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