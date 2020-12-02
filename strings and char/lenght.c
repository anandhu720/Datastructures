#include<stdio.h>

int main()
{
    char c[]="welcome";
    int i=0;
    while(c[i]!='\0')  //to find lenght of the string 
    {
        i++;
    }
    printf("the lenght of string is %d",i);
    return 0;
}