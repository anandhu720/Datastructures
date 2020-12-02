#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[3][4];
    a[1][3]=7;

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        {
            printf("%d ",a[i][j]);
        }
        
    }
}