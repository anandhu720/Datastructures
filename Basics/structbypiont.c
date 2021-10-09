#include<stdio.h>

struct rectangle
{
    int lenght;
    int breadth;
};

void main()
{
    struct rectangle r = {10,5};
    struct rectangle *p = &r;
    p->lenght=20;
    (*p).breadth=30;
    printf("%d\n",r.lenght);

    
}