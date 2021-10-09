#include<stdio.h>

struct rectangle
{
    int length;
    int breadth;
};

int area(struct rectangle r1)
{
    return r1.breadth*r1.length;
}

int main()
{
    struct rectangle r = {2,4};
    printf("%d",area(r));
    return 0;
}
