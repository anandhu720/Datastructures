// example of nested recursion


#include<stdio.h>

int fun(int n)
{
    if(n>100)
    {
        return (n-10);
    }
    else
    {
        fun(fun(n+11));   //nested recursion
    }
    
}

void main()
{
    int x=95;
    int ans = fun(x);
    printf("%d\n",ans);
}