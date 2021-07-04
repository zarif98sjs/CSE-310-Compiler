// recursion : fibonacci

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main ()
{
    int n;
    n = 5;
    int s;
    s = fib(n);
    printf(s); // 6
    return 0;
}