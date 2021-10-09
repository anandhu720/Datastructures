//program for combinations


#include<stdio.h>
//by function
int fac(int n)
{
    if(n==0)
       return 1;
    return fac(n-1)*n;
}

int comb(int n,int r)
{
    int t1 = fac(n);
    int t2 = fac(r);
    int t3 = fac(n-r);
    return t1/(t2*t3);
}

//by recursive function by using pascal triangle

int combrec(int n,int r)
{
    if ( n==r || r==0)
        return 1;
    return combrec((n-1),(r-1))+combrec((n-1),r);
}

void main()
{
    int n=5,r=2;
    printf("%d\n",combrec(n,r));
}