

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
#include "SymbolInfo.h"
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


struct ScopeTable
{
    string id;
    int counter;

    ScopeTable* parentScope;

    int M; /* initial hast table size */

    int collisionCnt = 0 , probecnt = 0;

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

    string get_id(){ return id; }
    void set_id(string id){ this->id = id; }

    int get_counter(){ return counter; }
    void set_counter(int counter){ this->counter = counter; }

    void increase_counter()
    {
        counter++;
    }

    int hash(string key)
    {
        int ret = (hashValue(key) % M);
        return ret;
    }

    SymbolInfo* search(string key)
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

    SymbolInfo* insert(SymbolInfo si)
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

    bool erase(string key)
    {
        int idx = hash(key);

        SymbolInfo* prv = NULL;
        SymbolInfo* now = ht[idx];

        while(now != NULL)
        {
            if(now->key == key)
            {
//                string ret = now->val;

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

    void print()
    {
        cout<<"ScopeTable # "<<id<<endl;

        for(int i=0;i<M;i++)
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
    }

    void printChainLengths()
    {
        for(int i=0;i<M;i++)
        {
            int cnt = 0;

            SymbolInfo* now = ht[i];
            while(now != NULL) now = now->nxt , cnt++;
            cout<<endl;

            cout<<"Chain "<<i<<" : "<<cnt<<endl;
        }
    }
};



//int hashF2(string s)
//{
//    int h = 0 , prime = 31 , p = 1 , mod = 1e9+7;
//    for(int i=0;i<(int)s.size();i++)
//    {
//        h = ((h%mod) + (p * s[i])%mod) % mod;
//
//        p = ((p%mod) * (prime%mod))%mod;
//    }
//    return h;
//}
//
