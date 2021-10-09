#include<stdio.h>

void fun(int a[],int n)
{
    a[3] = 0;
    for (int i=0;i<n;i++)
      printf("%d\n",a[i]);
}
void main()
{
    int a[5]={2,4,6,8,10};
    fun(a,5);
}