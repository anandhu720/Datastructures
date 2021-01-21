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

int main()
{
    int a[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10, i;

    quicksort(a, 0, n);

    //printing array
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}