int main()
{
    int d[4];
    d[0] = 20;
    d[1] = 40;

    int a,b,c;

    a = 10;
    b = 14;
    c = 16;

    int x;

    x = d[0]-d[1];
    println(x);

    x = d[0]-d[1]+c;
    println(x);

    x = a+b+c;
    println(x);

    x = d[0]-c-d[1];
    println(x);

    x = d[0]-d[1];
    println(x);

    return 0;
}