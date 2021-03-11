
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
    ScopeTable* cur;
    int bucket_size;
    function<int(string)> func;

public:

    template<typename T>
    SymbolTable(int bucket_size,T func)
    {
        this->bucket_size = bucket_size;
        this->func = func;

        cur = new ScopeTable(bucket_size,func);
    }

    SymbolTable(const SymbolTable &old);
    ~SymbolTable();

    void enter_scope() /// enter scope  = push : create and push a new ScopeTable
    {
        ScopeTable* st = new ScopeTable(bucket_size,func);

        st->parentScope = cur;
        cur = st;

        if(st->parentScope != NULL)
        {
            st->set_id(st->parentScope->get_id()+"."+to_str(st->parentScope->get_counter()));
        }

        cout<<"New ScopeTable with id "<<st->get_id()<<" created"<<endl;
    }

    void exit_scope() /// exit scope  = pop : remove the current ScopeTable
    {
        if(cur != NULL)
        {
            cout<<"ScopeTable with id "<<getCurScopeTableId()<<" removed"<<endl;

            ScopeTable* temp = cur;
            cur = cur->parentScope;
            cur->increase_counter();

            delete temp;
        }
    }

    bool insert_symbol(SymbolInfo si)
    {
        SymbolInfo* temp = cur->search(si.key);

        if(temp != NULL) /// cant insert
        {
            cout<<"<"<<temp->key<<","<<temp->val<<">"<<" already exists in current ScopeTable"<<endl;
            return false;
        }

        SymbolInfo* ret = cur->insert(si);

        cout<<"Inserted in ScopeTable# "<<getCurScopeTableId()<<" at position "<<ret->bucket<<","<<ret->bucket_pos<<endl;

        return ret!=NULL ;
    }

    bool remove_symbol(string key)
    {
        SymbolInfo* temp = cur->search(key);

        if(temp != NULL) /// present , so can delete
        {
            cout<<"Found in ScopeTable# "<<getCurScopeTableId()<<" at position "<<temp->bucket<<","<<temp->bucket_pos<<endl;
            cout<<"Deleted Entry "<<temp->bucket<<","<<temp->bucket_pos<<" from current ScopeTable"<<endl;
            return cur->erase(key);
        }
        else
        {
            cout<<"Not found"<<endl;
            cout<<key<<" not found"<<endl;
            return false;
        }
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

    string getCurScopeTableId()
    {
        return cur->get_id();
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

//    cin>>bucket_size;

    SymbolTable sym_tab(bucket_size,hashF);

    string command;

    while(cin>>command)
    {

        if(command=="I")
        {
            string name,sym_type;
            cin>>name>>sym_type;

            sym_tab.insert_symbol(SymbolInfo(name,sym_type));
        }
        if(command=="L")
        {
            string name;
            cin>>name;

            if(sym_tab.lookup(name)==NULL) cout<<"Not Found"<<endl;
        }
        if(command=="D")
        {
            string name;
            cin>>name;

            sym_tab.remove_symbol(name);
        }
        if(command=="S")
        {
            sym_tab.enter_scope();
        }
        if(command=="E")
        {
            sym_tab.exit_scope();
        }
        if(command=="P")
        {
            string print_type;
            cin>>print_type;

            if(print_type == "C") sym_tab.print_current_scope();
            else if(print_type == "A") sym_tab.print_all_scope();
        }

    }


    return 0;
}
