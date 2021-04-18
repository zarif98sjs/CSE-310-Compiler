
#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<bits/stdc++.h>
using namespace std;

struct SymbolInfo
{
    string key;
    string val;
    string var_type;
    vector<string>param_v;
    bool isFunctionDeclaration;
    bool isFunction;

    SymbolInfo* nxt;

    int bucket;
    int bucket_pos;

    SymbolInfo();

    SymbolInfo(string key,string val);
    // SymbolInfo(string key,string val,string var_type);
    // SymbolInfo(string key,string val,string var_type,vector<string>param_v);
    SymbolInfo(string key,string val,string var_type,vector<string>param_v,bool isFunctionDeclaration,bool isFunction);

    // SymbolInfo(string key,string val,SymbolInfo* nxt);
    // SymbolInfo(string key,string val,string var_type,SymbolInfo* nxt);
    // SymbolInfo(string key,string val,string var_type,vector<string>param_v,SymbolInfo* nxt);
    SymbolInfo(string key,string val,string var_type,vector<string>param_v,bool isFunctionDeclaration,bool isFunction,SymbolInfo* nxt);


    void setVarType(string var_type);
};

#endif // SYMBOLINFO_H
