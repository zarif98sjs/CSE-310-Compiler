
#include<bits/stdc++.h>
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "SymbolTable.h"

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
    SymbolInfo s("asd","123");
    ScopeTable st(10,hashF);
    SymbolTable sym_tab(10,hashF);

    int a;

    while(cin>>a)
    {
        cout<<s.key<<endl;
        cout<<s.val<<endl;
    }

    return 0;
}
