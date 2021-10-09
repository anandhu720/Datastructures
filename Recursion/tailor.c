#include<stdio.h>

double fun(int m,int n)
{
    static double p=1,f=1;
    double r;
    if (n==0)
       return 1;
    r = fun(m,n-1);
    p=p*m;
    f=f*n;
    return r+p/f;
}

void main()
{
    int x = 5,y = 4;
    printf("%lf\n",fun(y,10));
}