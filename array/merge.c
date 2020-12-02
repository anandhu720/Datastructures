#include<stdio.h>
#include<stdlib.h>

struct array
{
    int *a;
    int lenght;
    int size;
};

int display(struct array arr2)
{
    int i;
    for(i=0;i<arr2.lenght;i++)
        printf("d ",arr2.a[i]);
    printf('\n');
}

struct array * merge(struct array *arr,struct array *arr1)
{
    int i=0,j=0,k=0;
    struct array *arr2=(struct array *)malloc(sizeof(struct array));
    while(i<arr->lenght && j<arr1->lenght)
    {
        if(arr->a[i]<arr1->a[j])
            arr2->a[k++]==arr->a[i++];
        arr2->a[k++]==arr1->a[j++];
    }
    for(;i<arr->lenght;i++)
        arr2->a[k++]=arr->a[i];
    for(;j<arr1->lenght;j++)
        arr2->a[k++]=arr1->a[j];
    arr2->lenght=arr->lenght+arr1->lenght;
    arr2->size=10;

    return arr2;
}


int main()
{
    struct array arr;
    arr.a=(int *)malloc(10*sizeof(int));
    arr.a[0]=2;arr.a[1]=6;arr.a[2]=10;arr.a[3]=15;arr.a[4]=25;
    arr.lenght=5;
    arr.size=10;

    struct array arr1;
    arr1.a[0]=3;arr1.a[1]=4;arr1.a[2]=7;arr1.a[3]=18;arr1.a[4]=20;
    arr1.lenght=5;
    arr1.size=10;

    struct array *arr2;

    arr2=merge(&arr,&arr1);
    display(*arr2);

}