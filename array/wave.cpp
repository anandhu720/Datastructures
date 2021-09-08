#include<iostream>  //amazon
using namespace std;

int swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int wave(int *arr,int n)
{
       // Your code here
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
        {
            swap(&arr[i],&arr[i+1]);
            i++;
        }
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            swap(&arr[i],&arr[i+1]);
            i++;
        }
    }
}

int main()
{
    int arr[6]={1008,2343,2456,3216,4321,4423};
    int n=6;
    wave(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}