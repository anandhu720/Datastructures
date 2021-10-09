#include<stdio.h>
#include<stdlib.h>

struct term
{
    int coff;
    int exp;
};

struct poly
{
    int n;
    struct term *t;
};

int create(struct poly *p)
{
    printf("enter the number of terms: ");
    scanf("%d",&p->n);
    p->t=(struct term *)malloc(p->n*sizeof(struct term));
    printf("enter the terms: \n");
    for(int i=0;i<p->n;i++)
    {
        scanf("%d %d",&p->t[i].coff,&p->t[i].exp);
    }
}

void display(struct poly p)
{
    for(int i=0;i<p.n;i++)
        printf("%dx%d+",p.t[i].coff,p.t[i].exp);
    printf("0");
}

struct poly *add(struct poly *p1,struct poly *p2)
{
    struct poly *sum;
    int i=0,j=0,k=0;
    sum=(struct poly *)malloc(sizeof(struct poly));
    sum->t=(struct term *)malloc((p1->n+p2->n)*sizeof(struct term));

    while(i < p1->n && j < p2->n )
    {
        if(p1->t[i].exp>p2->t[j].exp)
            sum->t[k++]=p1->t[i++];
        else if(p1->t[i].exp<p2->t[j].exp)
            sum->t[k++]=p2->t[j++];
        else
        {
            sum->t[k].exp=p1->t[i].exp;
            sum->t[k++].coff=p1->t[i++].coff+p2->t[j++].coff;
        }
    }
    for(;i<p1->n;i++)
        sum->t[k++]=p1->t[i];
    for(;j<p2->n;j++)
        sum->t[k++]=p2->t[j];
    sum->n=k;
    return sum;
}

int main()
{
    struct poly p1,p2,*p3;
    create(&p1);
    create(&p2);

    p3=add(&p1,&p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);
    printf("\n");

    return 0;

}