#include<iostream>
using namespace std;

template <class t>
class arithamatic
{
    private:
       t x;
       t y;
    public:
       arithamatic(t a,t b);
       t sum();
       t diff();
};
template <class t>
arithamatic<t>::arithamatic(t a,t b)
{
    x=a;
    y=b;
}
template <class t>
t arithamatic<t>::sum()
{
    return x+y;
}
template <class t>
t arithamatic<t>::diff()
{
    return x-y;
}

int main()
{
    arithamatic<int> a(10,4);
    cout<<a.sum()<<"\n";
    cout<<a.diff()<<"\n";
    arithamatic<float> a1(10.3,4.5);
    cout<<a1.sum()<<"\n";
    return 0;
}