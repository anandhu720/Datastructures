#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[]="welcome";
    string c="welcome";
    int len=c.length();
    int i=0;
    while (a[i]!=0)
    {
        i++;
    }
    char b[100];
    strcpy(c,b);
    cout<<b<<'\n';
    cout<<"the lenght of the string is "<<len<<"\n";
    return 0;
}