#include<iostream>
using namespace std;

class rectangle
{
    private:
       int lenght;
       int breadth;
    public:
       rectangle(int l,int b);
       int area();
       int perimeter();
       int getlenght()
       {
           return lenght;
        }
       int setlenght(int l)
       {
           return lenght=l;
        }
       //~rectangle();
};

rectangle::rectangle(int l,int b)
{
    lenght=l;
    breadth=b;
}
int rectangle::area()
{
    return lenght*breadth;
}
int rectangle::perimeter()
{
    return 2*(lenght+breadth);
}


int main()
{
    rectangle r(10,4);
    cout<<r.area()<<"\n";
    cout<<r.perimeter()<<"\n";
    r.setlenght(3);
    cout<<r.area()<<"\n";
    cout<<r.getlenght()<<"\n";
    return 0;
}