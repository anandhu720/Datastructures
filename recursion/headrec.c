//example of head recursion

#include<stdio.h>

int fun(int n)
{
    if (n>0)
    {
        fun(n-1);  //head recursive function
        printf("%d ",n);   
    }
}

int fun1(int n)
{
    int i = 1;
    while (i<=n)
    {
        printf("%d ",i);
        i++;
    }
    
}

int main()
{
    int a = 3;
    //fun1(a);
    fun(a);
    return 0;
}