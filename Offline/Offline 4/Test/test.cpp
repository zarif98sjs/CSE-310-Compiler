
#include<bits/stdc++.h>
using namespace std;

void println(int c)
{
    cout<<c<<endl;
}
int f(int a){
    return 2*a;
    a=9;
}

int g(int a, int b){
    int x;
    x=f(a)+a+b;
    return x;
}

int main(){
    int a,b;
    a=1;
    b=2;
    a=g(a,b);
    println(a);
    return 0;
}