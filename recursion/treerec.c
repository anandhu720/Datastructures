/* example of tree recursive function */


#include<stdio.h>            /*  the no of times the recursive function
                                 executes is if x=n ,then
                                 2^(n+1)-1 times it will execute
                                 here 2 is no of time fun called */
int fun(int n)
{
    if(n>0)
    {
        printf("%d ",n);     /*  if x=n then space it requireid is n+1 */
        fun(n-1);
        fun(n-1);
        fun(n-1);
    }
    return 0;
}

void main()
{
    int x=3;
    fun(x);
}