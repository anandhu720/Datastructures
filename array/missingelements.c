#include<stdio.h>
#include<stdlib.h>

struct array 
{
    int *a;
    int lenght;
    int size;
};

int nmissing(struct array arr)   //for find missing element of n natural number sorted array
{
    int sum=0;
    for(int i=0;i<arr.lenght;i++)
        sum+=arr.a[i];
    int n=arr.a[arr.lenght-1];
    int s=n*(n+1)/2;
    printf("the missing element is %d\n",s-sum);
}

int missng1(struct array arr1)  //for finding one missing element in an sorted array 
{
    int i,a;
    int base=arr1.a[0];
    for(int i=1;i<arr1.lenght;i++)
    {
        a=arr1.a[i]-i;
        if(base!=a)
            return base+i;
    }
    return -1;
}

void sortmissing(struct array arr1)  //finding missing element in an sorted arry
{
    int i,a;
    int base=arr1.a[0];
    for(i=0;i<arr1.lenght;i++)
    {
        a=arr1.a[i]-i;
        if(base!=a)
        {
            while(base<a)
            {
                printf("%d\n",base+i);
                base++;
            }
        }
    }
}

int max(struct array arr1)           //to find max value element from array
{
    int max=arr1.a[0];
    for(int i=1;i<arr1.lenght;i++)
    {
        if(arr1.a[i]>max)
            max=arr1.a[i];
    }
    return max;
} 

int min(struct array arr1)       //to find the min value element from array
{
    int min=arr1.a[0];
    for(int i=1;i<arr1.lenght;i++)
    {
        if(arr1.a[i]<min)
           min=arr1.a[i];
    }
    return min;
}

int unsortmissing(struct array arr1)  //to find missing elements in unsorted array
{
    int l,h,n;
    l=min(arr1);
    h=max(arr1);
    int *hash;
    hash=(int *)malloc(h*sizeof(int));
    hash[0]=0;
    for(int i=0;i<arr1.lenght;i++)
    {
        hash[arr1.a[i]]++;
    }
    for(int i=l;i<h;i++)
    {
        if(hash[i]==0)
            printf("%d ",i);
    }


}


int main()
{
  /*  struct array arr;
    arr.a[0]=1;
    arr.a[1]=2;
    arr.a[2]=3;
    arr.a[3]=4;
    arr.a[4]=5;
    arr.a[5]=6;
    arr.a[6]=8;
    arr.a[7]=9;
    arr.a[8]=10;
    arr.a[9]=11;
    arr.lenght=10;
    arr.size=10;    */

    // *********************************** 

    struct array arr1;
    arr1.a[0]=1;
    arr1.a[1]=2;
    arr1.a[2]=5;
    arr1.a[3]=6;
    arr1.a[4]=8;
    arr1.a[5]=9;
    arr1.a[6]=10;
    arr1.a[7]=12;
    arr1.a[8]=13;
    arr1.a[9]=15;
    arr1.a[10]=16;
    arr1.lenght=11;
    arr1.size=17;


    //sortmissing(arr1);
    unsortmissing(arr1);
}