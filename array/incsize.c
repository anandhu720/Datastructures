#include<stdio.h>
#include<stdlib.h>
//test

int main()
{
    int *p,*q;
    p = (int *)malloc(5*sizeof(int));
    q = (int *)malloc(10*sizeof(int));

    p[0]=2;
    p[1]=4;
    p[2]=6;
    p[3]=8;

    for (int i = 0;i<5;i++)
        printf("%d ",p[i]);
    
    for (int j = 0;j<5;j++)
        q[j]=p[j];
    
    free(p);
    p=q;
    q=NULL;
    //p[8]=19;

    for (int a=0;a<10;a++)
        printf("\n%d ",p[a]);   

}