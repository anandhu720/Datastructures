//program of sum of n natural numbers by recursion

#include<stdio.h>

/*
int fun(int n)
{
    int a=0;
    if(n>a)
    {
        a+=n;
        fun(n-1);
        //return a;
    }
    return a;
}
*/

int sum(int n)
{
    if (n==0)
      return 0;
    else
        return sum(n-1)+n;
}


int main()
{
    int x = 3;
    int ans = sum(x);
    printf("%d\n",ans);

}