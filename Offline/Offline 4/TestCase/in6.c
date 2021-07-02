// recursion : nCr

int fact(int n);

int fact(int n)
{
    int res;
    res = 1;
    int i;
    for (i = 2; i <= n; i++)
        res = res * i;
    return res;
}
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Driver code
int main()
{
    int n,r;
    n = 6;
    r = 3;
    
    int ans;

    ans = nCr(n, r);

    println(ans); // 20

    return 0;
}