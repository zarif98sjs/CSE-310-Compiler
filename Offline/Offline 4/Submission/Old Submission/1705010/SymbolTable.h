
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
#include "ScopeTable.h"
using namespace std;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}


class SymbolTable
{
    ScopeTable* cur;
    int bucket_size;
    function<int(string)> func;

public:

    template<typename T>
    SymbolTable(int bucket_size,T func) /// constructor
    {
        this->bucket_size = bucket_size;
        this->func = func;

        cur = new ScopeTable(bucket_size,func);
    }

    ~SymbolTable();

    void enter_scope(); /// enter scope  = push : create and push a new ScopeTable
    void exit_scope(); /// exit scope  = pop : remove the current ScopeTable

    bool insert_symbol(SymbolInfo si);
    bool remove_symbol(string key);
    SymbolInfo* lookup(string key);

    void print_current_scope(ofstream &out);
    void print_all_scope(ofstream &out);

    string getCurScopeTableId();

};

#endif // SYMBOLTABLE_H
