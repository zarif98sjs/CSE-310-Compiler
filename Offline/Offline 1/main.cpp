
/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
//#include "SymbolInfo.h"
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

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

class SymbolTable
{
    vector<ScopeTable>v;

public:

    SymbolTable();
    SymbolTable(const SymbolTable &old);
    ~SymbolTable();
    void enter_scope(ScopeTable st) /// enter scope  = push : create and push a new ScopeTable
    {
        if(!v.empty())
        {
            st.set_id(v.back().get_id()+"."+to_str(v.back().get_counter()));
        }

        v.push_back(st);
    }

    void exit_scope() /// exit scope  = pop : remove the current ScopeTable
    {
        v.pop_back();
        v.back().increase_counter();
    }

    bool insert_symbol(SymbolInfo si)
    {
        return v.back().insert(si);
    }

    bool remove_symbol(string key)
    {
        if(v.back().erase(key) != "NOT_AVAILABLE") return true;
        return false;
    }

    SymbolInfo

    void print_current_scope()
    {
        v.back().print();
    }

    void print_all_scope()
    {
        for(auto it = v.rbegin(); it != v.rend() ; ++it)
            (*it).print();
    }
};

SymbolTable::SymbolTable()
{
    cout<<"Inside Default Constructor"<<endl;
}

SymbolTable::SymbolTable(const SymbolTable &old)
{
//    maxSize=old.maxSize;
//    ara=new ScopeTable[maxSize];
//    tos=old.top;
//
//    for(int i=0; i<maxSize; i++)
//        ara[i]=old.ara[i];

    cout<<"Copy Constructor has been used"<<endl;
}

SymbolTable::~SymbolTable()
{
    cout<<"MEMORY DEALOCATED"<<endl;
//    delete[] ara;
}

int hashF(string s)
{
    int h = 0;
    for(int i=0;i<(int)s.size();i++)
    {
        h = (h + s[i]);
    }
    return h;
}


int main()
{

    int bucket_size = 2;

    ScopeTable st1(bucket_size,hashF);
    ScopeTable st2(bucket_size,hashF);
    ScopeTable st3(bucket_size,hashF);
    ScopeTable st4(bucket_size,hashF);
    ScopeTable st5(bucket_size,hashF);

//    SymbolInfo si1("v1","VAR") , si2("n1","NUMBER");
    st1.insert(SymbolInfo("v1","VAR"));
    st1.insert(SymbolInfo("n1","NUMBER"));

    SymbolTable sym_tab;

    sym_tab.enter_scope(st1);
    sym_tab.enter_scope(st2);
    sym_tab.enter_scope(st3);

    cout<<"INSERT SYMBOL"<<endl;

    cout<<sym_tab.insert_symbol(SymbolInfo("v1","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v2","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v3","VAR"))<<endl;
//    sym_tab.insert_symbol(SymbolInfo("v2","VAR"));

//    sym_tab.print_all_scope();

    cout<<"REMOVE SYMBOL"<<endl;

    cout<<sym_tab.remove_symbol("v1")<<endl;
    cout<<sym_tab.remove_symbol("v5")<<endl;

    sym_tab.print_all_scope();
    cout<<endl;

    sym_tab.exit_scope();

    sym_tab.print_all_scope();
    cout<<endl;

    sym_tab.enter_scope(st4);
    sym_tab.print_all_scope();
    cout<<endl;

    sym_tab.enter_scope(st5);
    sym_tab.print_all_scope();
    cout<<endl;


//    st1.print();



    return 0;
}
