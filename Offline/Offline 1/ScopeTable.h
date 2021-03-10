

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

    int N; /* initial number of assumed data */
    int M; /* initial hast table size */

    int collisionCnt = 0 , probecnt = 0;

    vector<SymbolInfo*>ht;

    function<int(string)> hashValue;

    template<typename T>
    ScopeTable(int table_size,T func)
    {
        id = "1";
        counter = 1;

        N = 10000;
//        M = 10007; /*prime*/
        M = table_size;

        ht = vector<SymbolInfo*>(M);

        hashValue = func;
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

    string search(string key)
    {
        int idx = hash(key);

        SymbolInfo* now = ht[idx];

        while(now != NULL)
        {
            probecnt++;

            if(now->key == key)
                return now->val;

            now = now->nxt;
        }

        return "NOT_AVAILABLE"; /*not found*/
    }

    bool insert(SymbolInfo si)
    {
        string key = si.key;
        string val = si.val;

        int idx = hash(key);

        assert(idx<M);

        SymbolInfo* now = ht[idx];

        while(now != NULL)
        {
            if(now->key == key)
                return false; /*already exists*/

            now = now->nxt;
        }

        if(ht[idx] != NULL) collisionCnt++;

        ht[idx] = new SymbolInfo(key,val,ht[idx]);

        return true;
    }

    string erase(string key)
    {
        int idx = hash(key);

        SymbolInfo* prv = NULL;
        SymbolInfo* now = ht[idx];

        while(now != NULL)
        {
            if(now->key == key)
            {
                string ret = now->val;

                if(prv) prv->nxt = now->nxt;
                else  ht[idx] = now->nxt;

                delete (now);
                return ret;
            }

            prv = now;
            now = now->nxt;
        }

        return "NOT_AVAILABLE";
    }

    void print()
    {
        cout<<"Scope Table "<<id<<endl;

        for(int i=0;i<M;i++)
        {
            cout<<"Chain "<<i<<" : ";

            SymbolInfo* now = ht[i];
            while(now != NULL) cout<< now->key<<" " , now = now->nxt;
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
