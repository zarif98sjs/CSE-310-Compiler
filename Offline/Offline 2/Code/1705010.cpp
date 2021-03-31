
/* Which of the favors of your Lord will you deny ? */

#include<bits/stdc++.h>
#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"
using namespace std;

#define READ        freopen("in", "r", stdin)
#define WRITE       freopen("vorta", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

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

//    READ;
//    WRITE;

    int bucket_size = 2;

    cin>>bucket_size;

    SymbolTable sym_tab(bucket_size,hashF);

    string command;

    while(cin>>command)
    {

        cout<<command<<" ";

        if(command=="I")
        {
            string name,sym_type;
            cin>>name>>sym_type;

            cout<<name<<" "<<sym_type<<endl;
            cout<<endl;

            sym_tab.insert_symbol(SymbolInfo(name,sym_type));
        }
        if(command=="L")
        {
            string name;
            cin>>name;

            cout<<name<<endl;
            cout<<endl;

            if(sym_tab.lookup(name)==NULL) cout<<"Not found"<<endl;
        }
        if(command=="D")
        {
            string name;
            cin>>name;

            cout<<name<<endl;
            cout<<endl;

            sym_tab.remove_symbol(name);
        }
        if(command=="S")
        {
            cout<<endl;
            cout<<endl;

            sym_tab.enter_scope();
        }
        if(command=="E")
        {
            cout<<endl;
            cout<<endl;

            sym_tab.exit_scope();
        }
        if(command=="P")
        {
            string print_type;
            cin>>print_type;

            cout<<print_type<<endl;
            cout<<endl;

            if(print_type == "C") sym_tab.print_current_scope();
            else if(print_type == "A") sym_tab.print_all_scope();
        }
    }


    return 0;
}
