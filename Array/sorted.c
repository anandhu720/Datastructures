#include<stdio.h>
#include<stdlib.h>

struct array
{
    int *a;
    int size;
    int lenght;
}arr;

void display(struct array arr)
{
    int i;
    for (i=0;i<arr.size;i++)
        printf("%d ",arr.a[i]);
    printf("\n");   
     
}


int insert(struct array *arr,int x)         //inserting to a sorted array 
{
    int i=arr->lenght-1;
    while (x<arr->a[i])
    {
        arr->a[i+1]=arr->a[i];
        i--;
    }
    arr->a[i+1]=x;
}

int ifsorted(struct array arr)   //checking wheather array is sorted or not
{
    for(int i=0;i<arr.lenght-1;i++)
    {
        if(arr.a[i]>arr.a[i+1])
            return 0;
    }
    return 1;
}



int main()
{
    arr.a=(int *)malloc(10*sizeof(int));
    arr.size=10;
    arr.lenght=5;
    arr.a[0]=2;
    arr.a[1]=0;
    arr.a[2]=6;
    arr.a[3]=8;
    arr.a[4]=10;

    // ********************************************  //
    

    display(arr);
    printf("%d\n",ifsorted(arr));
}