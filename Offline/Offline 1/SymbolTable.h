
/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
#include "SymbolInfo.h"
#include "ScopeTable.h"
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

class SymbolTable
{
    ScopeTable* ara;
    int top;
    int maxSize;

public:

    SymbolTable();
    SymbolTable(const SymbolTable &old);
    ~SymbolTable();
    void push(ScopeTable num); /// enter scope : create and push a new ScopeTable
    int pop(); /// exit scope : remove the current ScopeTable
};

SymbolTable::SymbolTable()
{
    maxSize=10;
    ara=new ScopeTable[10];
    top=0;

    cout<<"Default Constructor used and A stack of size "<<maxSize<<" has been allocated memory"<<endl;
}

SymbolTable::SymbolTable(const SymbolTable &old)
{
    maxSize=old.maxSize;
    ara=new ScopeTable[maxSize];
    tos=old.top;

    for(int i=0; i<maxSize; i++)
        ara[i]=old.ara[i];

    cout<<"Copy Constructor has been used"<<endl;
}

SymbolTable::~SymbolTable()
{
    cout<<"MEMORY DEALOCATED"<<endl;
    delete[] ara;
}

void SymbolTable::push(int num)
{
    if(tos==maxSize)
    {
        //cout<<"Stack is full"<<endl;
        Resize(1);
        ara[tos++]=num;
        //cout<<"maxSIZE --> "<<maxSize<<" tos--> "<<tos<<endl;

    }
    else
        ara[tos++]=num;
}


void SymbolTable::push(SymbolTable s)
{
    if(tos+s.tos>maxSize)
    {
        Resize(s.tos);
        //cout<<"maxSIZE --> "<<maxSize<<" tos--> "<<tos<<endl;
    }

    for(int i=tos,j=s.tos-1; i<tos+s.tos; i++,j--)
        ara[i]=s.ara[j];

    tos += s.tos;

//    for(int i=0; i<tos; i++)
//        cout<<ara[i]<<" - ";

}

int SymbolTable::pop()
{
    if(tos==0)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else if(maxSize-tos>=10)
    {
        Resize(-1);
        //cout<<"maxSIZE is "<<maxSize<<" tos--> "<<tos<<endl;
        return ara[--tos];
    }
    else
        return ara[--tos];
}

