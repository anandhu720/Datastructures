#include<stdio.h>

struct rectangle
{
    int lenght;
    int breadth;
};
void main()
{
    struct rectangle r;
    printf("input the lenght: ");
    scanf("%d",&r.lenght);
    printf("input the breadth: ");
    scanf("%d",&r.breadth);
    printf("area is %d\n",r.lenght*r.breadth);
    
}
