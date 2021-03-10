
/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif


struct SymbolInfo
{
    string key;
    string val;
    SymbolInfo* nxt;

    SymbolInfo(){}

    SymbolInfo(string key,string val)
    {
        this->key = key;
        this->val = val;
        this->nxt = NULL;
    }

    SymbolInfo(string key,string val,SymbolInfo* nxt)
    {
        this->key = key;
        this->val = val;
        this->nxt = nxt;
    }
};
