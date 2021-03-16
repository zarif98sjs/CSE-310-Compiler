
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
//    vector<ScopeTable>v;

    ScopeTable* cur;

public:

    SymbolTable()
    {
        cur = NULL;
    }

    SymbolTable(const SymbolTable &old);
    ~SymbolTable();

    void enter_scope(ScopeTable* st) /// enter scope  = push : create and push a new ScopeTable
    {
        st->parentScope = cur;
        cur = st;

        if(st->parentScope != NULL)
        {
            st->set_id(st->parentScope->get_id()+"."+to_str(st->parentScope->get_counter()));
        }
    }

    void exit_scope() /// exit scope  = pop : remove the current ScopeTable
    {
        if(cur != NULL)
        {
            ScopeTable* temp = cur;
            cur = cur->parentScope;
            cur->increase_counter();

            delete temp;
        }
    }

    bool insert_symbol(SymbolInfo si)
    {
        return cur->insert(si);
    }

    bool remove_symbol(string key)
    {
        if(cur->erase(key) != "NOT_AVAILABLE") return true;
        return false;
    }

    SymbolInfo* lookup(string key)
    {
        ScopeTable* now = cur;

        while(now != NULL)
        {
            SymbolInfo* ret = now->search(key);

            if(ret != NULL)
            {
                cout<<"Found in Scope Table "<<now->get_id()<<" at position "<<ret->bucket<<","<<ret->bucket_pos<<endl;

                return ret;
            }

            now = now->parentScope;

        }

        return NULL; /// not found
    }


    void print_current_scope()
    {
        cur->print();
    }

    void print_all_scope()
    {
        ScopeTable* now = cur;

        while(now != NULL)
        {
            now->print();
            now = now->parentScope;
        }

        cout<<endl;
    }
};

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

    ScopeTable* st1 = new ScopeTable(bucket_size,hashF);
    ScopeTable* st2 = new ScopeTable(bucket_size,hashF);
    ScopeTable* st3 = new ScopeTable(bucket_size,hashF);
    ScopeTable* st4 = new ScopeTable(bucket_size,hashF);
    ScopeTable* st5 = new ScopeTable(bucket_size,hashF);
    ScopeTable* st6 = new ScopeTable(bucket_size,hashF);

//    SymbolInfo si1("v1","VAR") , si2("n1","NUMBER");
    st1->insert(SymbolInfo("v1","VAR"));
    st1->insert(SymbolInfo("n1","NUMBER"));

    SymbolTable sym_tab;

    sym_tab.enter_scope(st1);
    sym_tab.enter_scope(st2);
    sym_tab.enter_scope(st3);

    sym_tab.print_all_scope();
    sym_tab.lookup("v1");

    sym_tab.exit_scope();

    sym_tab.enter_scope(st4);
    sym_tab.print_all_scope();

//    cout<<"INSERT SYMBOL"<<endl;
//
    cout<<sym_tab.insert_symbol(SymbolInfo("v1","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v2","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v3","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v4","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v5","VAR"))<<endl;
    cout<<sym_tab.insert_symbol(SymbolInfo("v2","VAR"))<<endl;

    sym_tab.print_all_scope();
    sym_tab.lookup("v1");


    cout<<"REMOVE SYMBOL"<<endl;

    cout<<sym_tab.remove_symbol("v1")<<endl;
    cout<<sym_tab.remove_symbol("v5")<<endl;

    sym_tab.print_all_scope();

    sym_tab.exit_scope();
    sym_tab.print_all_scope();

    sym_tab.enter_scope(st5);
    sym_tab.print_all_scope();

    sym_tab.enter_scope(st6);
    sym_tab.print_all_scope();


//    st1.print();



    return 0;
}
