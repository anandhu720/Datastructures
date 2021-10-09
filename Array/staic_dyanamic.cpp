#include<iostream>
using namespace std;
int main()
{
    int a[5]={0};
    int *p;
    p = new int [5];  //dynamic allocation
    p[0]=3;
    cout<<p[0];
    delete []p;  //deleting dynamic allocation
    cout<<p[0];
    return 0;
}