
#ifndef SCOPETABLE_H
#define SCOPETABLE_H

/*
 *
 * Hash Table : Separate Chaining Method
 *
 * - Md. Zarif Ul Alam
 * Staring at : 16 November 2020 6:10pm
 *
 * */

#include<bits/stdc++.h>
#include "SymbolInfo.h"
using namespace std;

struct ScopeTable
{
    string id;
    int counter;

    ScopeTable* parentScope;

    int M; /* initial hast table size */

    vector<SymbolInfo*>ht;

    function<int(string)> hashValue;

    template<typename T>
    ScopeTable(int table_size,T func)
    {
        id = "1";
        counter = 1;
        parentScope = NULL;

        M = table_size;
        hashValue = func;

        ht = vector<SymbolInfo*>(M);
    }

    ~ScopeTable(); /// destructor

    /// id
    string get_id();
    void set_id(string id);

    /// counter
    int get_counter();
    void set_counter(int counter);
    void increase_counter();

    /// hash
    int hash(string key);

    /// mehtods
    SymbolInfo* search(string key);
    SymbolInfo* insert(SymbolInfo si);
    bool erase(string key);

    /// prints
    void print();
    void printChainLengths();

};

#endif // SCOPETABLE_H


