#include<iostream>
using namespace std;


//program of lower triangular matrix using class in c++
class lowertriangular
{
    private:
        int *a;
        int n;
    public:
        lowertriangular()
        {
            int n=2;
            a=new int[2*(2+1)/2];
        }
        lowertriangular(int n)
        {
            this->n=n;
            a=new int[n*(n+1)/2];
        }
        ~lowertriangular()
        {
            delete []a;
        }

        void set(int i,int j,int x);
        int get(int i,int j);
        void display();
};

void lowertriangular::set(int i,int j,int x)
{
    if(i>=j)
        a[i*i-1/2+j-1]=x;
}

int lowertriangular::get(int i,int j)
{
    if(i>=j)
        return a[i*i-1/2+j-1];
    else 
        return 0;
}

void lowertriangular::display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<a[i*i-1/2+j-1]<<" ";
            else 
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int d,x;
    cout<<"Enter the dimension :";
    cin>>d;
    lowertriangular lr(d);  //object
    cout<<"enter all elements: \n";
    for(int i=1;i<=d;i++)   //entering elements to array
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            lr.set(i,j,x);   //setting
        }
    }
    cout<<"\n\n\n";
    lr.display();
    return 0;
}