#ifndef HELPER_H
#define HELPER_H

#include<bits/stdc++.h>
using namespace std;

#include "SymbolInfo.h"

struct Helper{
    
    string text;
    vector<SymbolInfo*>v;
    string HelperType;
    vector<string>param_v;
    string code;
    string tempVar;

    Helper();
    Helper(string text,vector<SymbolInfo*>v);

    void setText(string text);
    void setCode(string code);
    void setHelperType(string HelperType);
    void setVector(vector<SymbolInfo*>v);

    void print();

};

#endif // HELPER_H