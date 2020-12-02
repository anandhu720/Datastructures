#include<stdio.h>

int main()
{
    char temp='A';
    char r[5]={65,66,67,68,69};    //array of chracter
    char r1[5]={'a','b','c','d','e'};  //array of character
    char name[]="john";
    printf("%s\n",name);
    for(int i=0;i<5;i++)
        printf("%c ",r[i]);
    printf("\n");
    return 0;
}