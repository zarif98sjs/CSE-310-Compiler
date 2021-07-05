int f2(int a,int b)
{
    return a*b;
}
int f4(int a, int b,int c,int d)
{
    return f2(f2(a,b),f2(c,d));
}
int count;
void show(int n)
{
    count++;
    println(n);
}
int main()
{
    int d[4];
    int i;
    i=0;
    for(i=0;i<4;i++)
    {
        d[3-i]=(i+1)*10;
    }
    i=0;
    while(i<4)
    {
        show(d[i]/5);
        i++;
    }
    int md;
    md=d[0]%d[1];
    show(md);
    show(count);
    int g;
    g=f4(2,3,4,5);
    println(g);
    return 0;
}