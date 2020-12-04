#include<stdio.h>
#include<stdlib.h>

struct matrix 
{
    int *a;
    int n;
}m;

//row major mapping
void setr(struct matrix *m,int i,int j,int x)
{
    if(i<=j)
        m->a[m->n*(i-1)+(i-2)*(i-1)/2+(j-1)]=x;
}

int getr(int i,int j,struct matrix m)
{
    if(i<=j)
        return m.a[m.n*(i-1)+(i-2)*(i-1)/2+(j-1)];
    return 0;
}

void displayr(struct matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i<=j)
                printf("%d ",m.a[m.n*(i-1)+(i-2)*(i-1)/2+(j-1)]);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

//column major mapping
void setc(struct matrix *m,int i,int j,int x)
{
    if(i<=j)
        m->a[(j-1)*j/2+(i-1)]=x;
}

int getco(int i,int j,struct matrix m)
{
    if(i<=j)
        return m.a[(j-1)*j/2+(i-1)];
    return 0;
}

void displayc(struct matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i<=j)
                printf("%d ",m.a[(j-1)*j/2+(i-1)]);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int x;
    printf("enter the dimension:");
    scanf("%d",&m.n);

    m.a=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));

    printf("Enter the elements: \n");
    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            setc(&m,i,j,x);
        }
    }

    printf("\n\n");

    displayc(m);
    return 0;

}