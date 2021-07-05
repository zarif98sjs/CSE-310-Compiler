int save[7];
int fibo(int n)
{
    if(save[n]!=-1)
    {
        return save[n];
    }
    else if(n<=1)
    {
        save[n]=n;
        return save[n];
    }
    else
    {
        save[n]=fibo(n-1)+fibo(n-2);
        return save[n];
    }
}
int main()
{
    int i;
    i=0;
    for(i=0;i<=6;i++)
    {
        save[i]=-1;
    }
    int pr;
    for(i=6;i>-1;i--)
    {
        pr=fibo(i);
        println(pr);
    }
    return 0;
}