
/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
using namespace std;

struct SymbolInfo
{
    string key;
    string val;
    SymbolInfo* nxt;

    int bucket;
    int bucket_pos;

    SymbolInfo(){}

    SymbolInfo(string key,string val)
    {
        this->key = key;
        this->val = val;
        this->nxt = NULL;

        bucket = -1;
        bucket_pos = 0;
    }

    SymbolInfo(string key,string val,SymbolInfo* nxt)
    {
        this->key = key;
        this->val = val;
        this->nxt = nxt;
        this->bucket = bucket;
        this->bucket_pos = bucket_pos;
    }
};
