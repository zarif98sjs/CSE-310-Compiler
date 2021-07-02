// global variable check 

int a,b,c,i;

void foo()
{    
    b=0;
	c=1;
    for(i=0;i<4;i++){
        a=3;
        while(a--){
            b++;
        }
    }
    println(a);
    println(b);
    println(c);
}

int main(){
    foo(); // -1 12 1
    foo(); // -1 12 1
}