// multiple return check + some arithmetic operation

int foo(int a,int b)
{    
    if(a>b) return a;
    else return b;
}

int foo2(int a,int b)
{
    if(a == 10) return a;
    if(b == 12) return b;

    return a+b;
}

int main(){

    int x,y;

    x = foo(12,10); // 12
    y = foo(12,15); // 15

    println(x);
    println(y);

    int z;

    z = 12/15; // 0
    println(z);

    z = x + y * foo2(10,20); // 162
    println(z);

    z = x * y - foo2(20,12); // 168
    println(z);

    z = x / y + foo2(14,13); // 27
    println(z);

    return 0;
}

