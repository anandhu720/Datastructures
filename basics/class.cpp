#include<iostream>
using namespace std;

class rectangle
{
    private:
       int length;
       int breadth;
    public:
       rectangle(int l,int b) //constructure
       {
           length=l;
           breadth=b;
       }   
       int area()
       {
           return length*breadth;
       }
       void change_lenght(int l)
       {
           length=l;
       }
};

int  main()
{
    rectangle r(10,3);
    r.area();
    r.change_lenght(2);
    return 0;
}
