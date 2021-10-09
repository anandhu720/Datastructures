#include<iostream>
using namespace std;

int sum(int n)
{
    if ( n>0)
    {
        return sum(n-1)+n;
    }
    
}

int main()
{
    int x = 5;
    int ans = sum(x);
    cout<<ans;
    return 0;
}