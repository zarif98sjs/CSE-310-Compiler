
/*
 *
 * Hash Table : Separate Chaining Method
 *
 * - Md. Zarif Ul Alam
 * Staring at : 16 November 2020 6:10pm
 *
 * */


/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
#include "ScopeTable.h"
using namespace std;


template<typename T>
ScopeTable::ScopeTable(int table_size,T func) /// constructor
{
    id = "1";
    counter = 1;
    parentScope = NULL;

    M = table_size;
    hashValue = func;

    ht = vector<SymbolInfo*>(M);
}

ScopeTable::~ScopeTable() /// destructor
{
    cout<<"ScopeTable memory deallocated"<<endl;

    for(int i=0; i<ht.size(); i++)
    {
        SymbolInfo* now = ht[i];

        while(now != NULL)
        {
            SymbolInfo* tmp = now->nxt;
            delete now;
            now = tmp;
        }
    }
}

string ScopeTable::get_id()
{
    return id;
}
void ScopeTable::set_id(string id)
{
    this->id = id;
}

int ScopeTable::get_counter()
{
    return counter;
}
void ScopeTable::set_counter(int counter)
{
    this->counter = counter;
}

void ScopeTable::increase_counter()
{
    counter++;
}

int ScopeTable::hash(string key)
{
    int ret = (hashValue(key) % M);
    return ret;
}

SymbolInfo* ScopeTable::search(string key)
{
    int bucket = hash(key);

    SymbolInfo* now = ht[bucket];

    while(now != NULL)
    {
        if(now->key == key) return now;

        now = now->nxt;
    }

    return NULL; /*not found*/
}

SymbolInfo* ScopeTable::insert(SymbolInfo si)
{
    string key = si.key;
    string val = si.val;

    int bucket = hash(key);

    SymbolInfo* to_insert = new SymbolInfo(key,val,NULL);
    to_insert->bucket = bucket;

    assert(bucket<M);

    if(ht[bucket] == NULL) ht[bucket] = to_insert;
    else
    {
        SymbolInfo* now = ht[bucket];
        if(now->key == key) return NULL; /*already exists*/

        int bucket_pos = 1;

        while(now->nxt != NULL)
        {
            if(now->key == key)
                return NULL; /*already exists*/

            now = now->nxt;
            bucket_pos++;
        }

        to_insert->bucket_pos = bucket_pos;
        now->nxt = to_insert;
    }

    return to_insert;
}

bool ScopeTable::erase(string key)
{
    int idx = hash(key);

    SymbolInfo* prv = NULL;
    SymbolInfo* now = ht[idx];

    while(now != NULL)
    {
        if(now->key == key)
        {
            if(prv) prv->nxt = now->nxt;
            else  ht[idx] = now->nxt;

            delete (now);
            return true;
        }

        prv = now;
        now = now->nxt;
    }

    return false;
}

void ScopeTable::print()
{
    cout<<"ScopeTable # "<<id<<endl;

    for(int i=0; i<M; i++)
    {
        cout<<"Chain "<<i<<" : ";

        SymbolInfo* now = ht[i];
        while(now != NULL)
        {
            cout<<"< "<<now->key <<" : "<<now->val<<" > ";
            now = now->nxt;
        }
        cout<<endl;
    }
    cout<<endl;
}

void ScopeTable::printChainLengths()
{
    for(int i=0; i<M; i++)
    {
        int cnt = 0;

        SymbolInfo* now = ht[i];
        while(now != NULL) now = now->nxt, cnt++;
        cout<<endl;

        cout<<"Chain "<<i<<" : "<<cnt<<endl;
    }
}

