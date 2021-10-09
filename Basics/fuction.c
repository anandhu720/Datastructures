#include<stdio.h>

int add(int a,int b)
{
    int c = a+b;
    return c;
}
void main()
{
    int x=10,y=20,z;
    z=add(x,y);
    printf("the sum is %d\n",z);
}