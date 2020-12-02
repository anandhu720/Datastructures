#include<iostream>
using namespace std;

void swap(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a=10,b=3;
    cout<<a<<b;
    swap(a,b);
    cout<<a<<b;
    return 0;
}