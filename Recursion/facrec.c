#include<stdio.h>

int factorial(int n)
{
    if (n>1)
    {
        return factorial(n-1)*n;
    }

}

int main()
{
    int x =3;
    printf("%d\n",factorial(x));
    return 0;
}
