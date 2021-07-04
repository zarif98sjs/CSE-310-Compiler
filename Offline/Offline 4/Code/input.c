int ar[10];
int f()
{
    int x[10];

    x[2] = 20;
    return x[2];
}

int main()
{
    ar[2] = 3;
    println(ar[2]);
    int re ;
    re = f();
    println(re);
    return 0;
}