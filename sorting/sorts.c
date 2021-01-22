#include <stdio.h>
#include <stdlib.h>

void swap_no(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//bubble sort
int bubblesort(int a[], int n)
{
    int i, j;
    int flag; //used to check wheather give array is sorted or not
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap_no(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

//insertion sort
int insertionsort(int a[], int n)
{
    int j, i, x;
    for (i = 0; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

//selectionsort
void selectionsort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        swap_no(&a[i], &a[k]);
    }
}

//quick sort

//partion
int partion(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
            swap_no(&a[i], &a[j]);
    } while (i < j);

    swap_no(&a[l], &a[j]);
    return j;
}

//main quick sort
void quicksort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partion(a, l, h);
        quicksort(a, l, j);
        quicksort(a, j + 1, h);
    }
}

//mergeing single array with two parts
void merge(int a[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[100];

    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    //for remaining elements
    for (; i <= mid; i++)
        b[k++] = a[i];
    for (; j <= h; j++)
        b[k++] = a[j];

    for (int i = 0; i <= h; i++) //changing sorted array back to A
        a[i] = b[i];
}

//mergesort in array
void mergesort(int a[], int n)
{
    int p, i, l, mid, h;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = ((l + h) / 2);
            merge(a, l, mid, h);
        }
    }
    if (p / 2 < n)
        merge(a, 0, p / 2 - 1, n - 1);
}

//recursive merge sort
void rmergesort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        rmergesort(a, l, mid);
        rmergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int findmax(int a[], int n) //to find max value element from array
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

//count sorting
void countsort(int a[], int n)
{
    int max;
    int *c;
    max = findmax(a, n);
    c = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
        c[i] = 0;
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    int i = 0, j = 0;
    while (j < max + 1)
    {
        if (c[j] > 0)
        {
            a[i++] = j;
            c[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int a[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10, i;

    countsort(a, n);

    //printing array
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}