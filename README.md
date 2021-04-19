# **`A Compiler in the making`**

A compiler is a computer program that translates computer code written in one programming language (the source language) into another language (the target language). Here we will build some parts of a compiler for the subset of C language.

# Part 1 : **`Creating a Symbol Table`**

The first part needed to make a `Compiler` is a `Symbol Table`. A Symbol Table is a data structure maintained by compilers in order to store information about the occurrence of various entities such as identifiers, objects, function names etc. Information of different entities may include type, value, scope etc. 

At the starting phase of constructing a compiler, we will construct
a Symbol Table which maintains a list of `Hash Tables(Scope Tables)` where each hash table contains information of symbols encountered in a scope of the source program . Each Scope Table will have `Symbol Info` (which will store the information) in it's buckets.

Here is an overview 

![](images/symboltable.png)

Now straight to code . I am showing the declarations here . The full implementation can be found in the code directory.

## `SymbolInfo`

```c++

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
    SymbolInfo(string key,string val,string var_type,vector<string>param_v,bool isFunctionDeclaration,bool isFunction);

    SymbolInfo(string key,string val,string var_type,vector<string>param_v,bool isFunctionDeclaration,bool isFunction,SymbolInfo* nxt);


    void setVarType(string var_type);
};

#endif // SYMBOLINFO_H

```

## `ScopeTable`

```c++

#ifndef SCOPETABLE_H
#define SCOPETABLE_H

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

```

## `SymbolTable`

```c++

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

    void print_current_scope();
    void print_all_scope();

    string getCurScopeTableId();

};

#endif // SYMBOLTABLE_H

```

# Part 2 : `Lexical Analyzer`