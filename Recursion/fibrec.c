#include<stdio.h>

int fib(int n)
{
    if (n<=1)       //fib using rec
        return n;
    return fib(n-2)+fib(n-1);
}
int f[10];

int fib1(int n)
{
    //int f[10];
    if (n<=1)
    {
        f[n]=n;
        return 1;     //memonising fuction
    }
    else
    {
        if (f[n-2]==-1)
            f[n-2] = fib(n-2);
        if (f[n-1]==-1)
            f[n-1] = fib(n-1);
        return f[n-2]+f[n-1];
    }
    
}

void main()
{
    for(int i=0;i<=10;i++)    //intilization of global array
         f[i] = -1;
    printf("%d\n",fib(20));
}