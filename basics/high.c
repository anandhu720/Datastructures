#include<stdio.h>

struct rectangle
{
    int lenght;
    int breadth;
};

void intialize(struct rectangle *r,int l,int b)
{
    r->lenght=l;
    r->breadth=b;
}

int area(struct rectangle r)
{
    int area = r.lenght*r.breadth;
    return area;
}

void changelenght(struct rectangle *r,int l)
{
    r->lenght=l;
}
int main()
{
    struct rectangle r;
    intialize(&r,10,5);
    int final_area=area(r);
    changelenght(&r,30);

}
