
#include "SymbolInfo.h"

SymbolInfo::SymbolInfo(string key,string val)
{
    this->key = key;
    this->val = val;
    this->nxt = NULL;

    bucket = -1;
    bucket_pos = 0;
}

SymbolInfo::SymbolInfo(string key,string val,SymbolInfo* nxt)
{
    this->key = key;
    this->val = val;
    this->nxt = nxt;
    this->bucket = bucket;
    this->bucket_pos = bucket_pos;
}
