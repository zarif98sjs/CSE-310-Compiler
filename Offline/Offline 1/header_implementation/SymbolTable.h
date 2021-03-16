
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

    ~SymbolTable()
    {
        cout<<"SymbolTable memory deallocated"<<endl;
        cout<<endl;

        while(cur != NULL)
        {
            ScopeTable* tmp = cur->parentScope;
            delete cur;
            cur = tmp;
        }
    }

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
        cout<<endl;
    }

    void exit_scope() /// exit scope  = pop : remove the current ScopeTable
    {
        if(cur != NULL)
        {
            cout<<"ScopeTable with id "<<getCurScopeTableId()<<" removed"<<endl;
            cout<<endl;

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
            cout<<endl;
            return false;
        }

        SymbolInfo* ret = cur->insert(si);

        cout<<"Inserted in ScopeTable# "<<getCurScopeTableId()<<" at position "<<ret->bucket<<","<<ret->bucket_pos<<endl;
        cout<<endl;
        return ret!=NULL ;
    }

    bool remove_symbol(string key)
    {
        SymbolInfo* temp = cur->search(key);

        if(temp != NULL) /// present , so can delete
        {
            cout<<"Found in ScopeTable# "<<getCurScopeTableId()<<" at position "<<temp->bucket<<","<<temp->bucket_pos<<endl;
            cout<<"Deleted Entry "<<temp->bucket<<","<<temp->bucket_pos<<" from current ScopeTable"<<endl;
            cout<<endl;
            return cur->erase(key);
        }
        else
        {
            cout<<"Not found"<<endl;
            cout<<key<<" not found"<<endl;
            cout<<endl;
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
                cout<<endl;
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


int hashF(string s)
{
    int h = 0;
    for(int i=0;i<(int)s.size();i++)
    {
        h = (h + s[i]);
    }
    return h;
}
