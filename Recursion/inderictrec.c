#include<stdio.h>

void funb(int n);

void funa(int a)
{
    if(a>0)
    {
        printf("%d ",a);
        funb(a-1);
    }
}

void funb(int n)
{
    if(n>1)
    {
        printf("%d ",n);
        funa(n/2);
    }
}

int main()
{
    int x=20;
    funa(x);
}