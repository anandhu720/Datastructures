//square of a number by recursion
//using static and global variable

#include<stdio.h>

int x = 0;  //global variable

int fun(int n)
{
    //static int x = 0; //static variable
    if (n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

void main()
{
    int a=7;
    printf("%d\n",fun(a));
}
