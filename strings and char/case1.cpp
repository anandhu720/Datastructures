#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="welcome";
    transform(a.begin(),a.end(),a.begin(),::toupper);   //to uppercase
    cout<<a<<"\n";

    transform(a.begin(),a.end(),a.begin(),::tolower);   //to lowercase
    cout<<a<<'\n';

    return 0;
}