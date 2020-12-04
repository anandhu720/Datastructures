#include<stdio.h>
#include<stdlib.h>

struct matrix
{
    int *a;
    int n;
};

//row major mapping
void setr(struct matrix *m,int i,int j,int x)
{
    if(i>=j)
        m->a[i*(i-1)/2+j-1]=x;
}

//getting row major mapping
int getr(struct matrix m,int i,int j)
{
    if(i>=j)
        return m.a[i*(i-1)/2+ j-1];
    else 
        return 0;
}

//display row major mapping
void displayr(struct matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i>=j)
                printf("%d ",m.a[i*(i-1)/2+j-1]);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

//column major mapping
void setc(struct matrix *m,int i,int j,int x)
{
    if(i>=j)
        m->a[m->n*(j-1)+(j-2)*(j-1)/2+(i-j)]=x;
}

//getting column major mapping
int getco(struct matrix m,int i,int j)
{
    if(i>=j)
        return m.a[m.n*(j-1)+(j-2)*(j-1)/2+(i-j)];
    else 
        return 0;
}

//display column major mapping
void displayc(struct matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i>=j)
                printf("%d ",m.a[m.n*(j-1)+(j-2)*(j-1)/2+(i-j)]);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct matrix m;
    int x;
    printf("Enter the dimension of array: ");
    scanf("%d",&m.n);

    //delcearing dynamic array
    m.a=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));

    printf("Enter all elements: \n");
    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            //setr(&m,i,j,x);    //row major
            setc(&m,i,j,x);
        }
    }

    printf("\n\n");

    //row major mapping
    //printf("%d\n",getr(m,2,1));
    //displayr(m);

    //column major
    displayc(m);

    return 0;
}