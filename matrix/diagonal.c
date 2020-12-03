#include<stdio.h>
#include<stdlib.h>

struct matrix
{
    int *a;
    int n;
};

//set values in diagonal matrix
void set(struct matrix *m,int i,int j,int x)
{
    if(i==j)
        m->a[i-1]=x;
}

//get valus in diagonal matrix
int get(struct matrix m,int i,int j)
{
    if(i==j)
        return m.a[i-1];
    return 0;
}

//display
void display(struct matrix m)
{
    int i,j;
    for(i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++)
        {
            if(i==j)
                printf("%d ",m.a[i]);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int size;
    struct matrix m;
    printf("Enter the size of array: ");
    scanf("%d",&size);

    //delcearing dynamic array
    m.a=(int *)malloc(size*sizeof(int));
    m.n=5;


    //userdefined functions
    set(&m,1,1,5);set(&m,2,2,8);set(&m,3,3,9);set(&m,4,4,1);set(&m,5,5,3);
    display(m);



    
    return 0;
}