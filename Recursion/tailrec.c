//example of tail recursion
 /*  tail recursion is less efficent than loops because it consumes more space
    so always try to write loops in place of tail recursion. */
#include<stdio.h>

int fun(int x)
{
    if (x > 0)
    {
        printf("%d ",x);
        fun(x-1);    //tail recursion 
    }
}
int fun1(int n)
{
    while (n>0)
    {
        printf("%d ",n);
        n--;
    }
}

int fun2(int y)
{
    for (y;y>0;y--)
    {
        printf("%d ",y);
    }
}

void main()
{
    int a = 5;
    //printf("%d\n",fun(a));
    fun2(a);
}