int sum(int a,int b,int c,int d)
{
    int s;
    s = a+b;
    return s;
}

int main(){
    int x,y;
    x = 10;
    y = 12;

    int s;
    s = sum(x,y,y,x);
    println(s);
}