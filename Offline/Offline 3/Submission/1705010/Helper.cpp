
#include<bits/stdc++.h>
using namespace std;

#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "Helper.h"



Helper::Helper(){};
Helper::Helper(string text,vector<SymbolInfo*>v)
{
    this->text = text;
    this->v = v;
}

void Helper::setText(string text){this->text = text;}
void Helper::setHelperType(string HelperType){this->HelperType = HelperType;}
void Helper::setVector(vector<SymbolInfo*>v){this->v = v;}

void Helper::print()
{
    cout<<"Text : "<<text<<endl;

    cout<<"Vector Size : "<<v.size()<<endl;
    cout<<"Vector  : "<<endl;
    for(auto s:v)
    {
        cout<<s->key<<" , "<<s->val<<endl;
    }
}



// int main()
// {
//     SymbolInfo* s1 = new SymbolInfo("a","bcd");
//     SymbolInfo* s2 = new SymbolInfo("a2","bcd2");

//     vector<SymbolInfo*>v;
//     v.push_back(s1);
//     v.push_back(s2);

//     Helper h("dummy",v);
//     h.print();
//     return 0;
// }