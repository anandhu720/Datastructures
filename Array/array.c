#include <stdio.h>
#include <stdlib.h>

struct array  //creating dynamic array
{
    int *a;
    int size;
    int lenght;
};

void display(struct array arr)  //displaying array
{
    int i;
    for (i = 0; i < arr.lenght; i++)
        printf("%d ", arr.a[i]);
    printf("\n");
}

void append(struct array *arr, int x) //appending element to array
{
    if (arr->lenght < arr->size)
        arr->a[arr->lenght++] = x;
}

void insert(struct array *arr, int index, int x) //inserting element in an array
{
    if (index >= 0 && index < arr->lenght)
    {
        for (int i = arr->lenght; i > index; i--)
            arr->a[i] == arr->a[i - 1];
        arr->a[index] = x;
        arr->lenght++;
    }
}

void delete (struct array *arr, int index) //deleting element from array
{
    if (index >= 0 && index < arr->lenght)
    {
        int x = arr->a[index];
        for (int i = index; i < arr->lenght - 1; i++)
            arr->a[i] = arr->a[i + 1];
        arr->lenght--;
    }
}

int swap(int *x, int *y) //swapping two element
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearsearch(struct array *arr, int key) //linear search
{
    int i;
    for (i = 0; i < arr->lenght; i++)
    {
        if (key == arr->a[i])
        {
            //swap(&arr->a[i],&arr->a[i-1]);   //transpositon swapping
            swap(&arr->a[i], &arr->a[0]); //move to tail/head swapping
            return i;
        }
    }
    return -1;
}

int binarysearch(struct array arr, int key) //binarysearching element using loop
{                                           //more preferable
    int l = 0, h = arr.lenght, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.a[mid])
            return mid;
        else if (key < arr.a[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int rbinarysearch(int a[], int l, int h, int key) //binarysearch using recursion
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return rbinarysearch(a, l, mid - 1, key);
        else
            return rbinarysearch(a, mid + 1, h, key);
    }
    return -1;
}

int get(struct array arr, int index) //getting an element from array
{
    if (index >= 0 && index < arr.lenght)
        return arr.a[index];
    return -1;
}

int set(struct array *arr, int index, int x) //replacing a number in index
{
    if (index >= 0 && index < arr->lenght)
        arr->a[index] = x;
}

int max(struct array arr) //to find max value element from array
{
    int max = arr.a[0];
    for (int i = 1; i < arr.lenght; i++)
    {
        if (arr.a[i] > max)
            max = arr.a[i];
    }
    return max;
}

int min(struct array arr) //to find the min value element from array
{
    int min = arr.a[0];
    for (int i = 1; i < arr.lenght; i++)
    {
        if (arr.a[i] < min)
            min = arr.a[i];
    }
    return min;
}

int sum(struct array arr) //sum of all elements in an array     //by using loop(more prefferable)
{
    int total = 0;
    for (int i = 0; i < arr.lenght; i++)
        total += arr.a[i];
    return total;
}

int rsum(struct array arr, int n) //sum of all elements in an array  //by using recursion(tail recursion)
{
    if (n >= 0)
        return rsum(arr, n - 1) + arr.a[n];
    return 0;
}

float average(struct array arr) //average of all elements in an array
{
    return (float)sum(arr) / arr.lenght;
}

int reverse1(struct array *arr) //reversing array with swapping
{
    int i = 0, j = arr->lenght - 1;
    while (i < j)
    {
        swap(&arr->a[i], &arr->a[j]);
        i++;
        j--;
    }
}

int reverse2(struct array *arr) //reversing array by another array  //some problem is there
{
    int i, j;
    int *b;
    b = (int *)malloc(arr->lenght * sizeof(int));
    for (j = arr->lenght - 1, j = 0; i >= 0; i++, j--)
        b[j] = arr->a[i];
    for (int i = 0; i < arr->lenght; i++)
    {
        arr->a[i] = b[i];
        printf("%d ", arr->a[i]);
    }
    printf("\n");
    free(b);
}

int leftshift(struct array *arr) //left_shift of array
{
    for (int i = 1; i <= arr->lenght - 1; i++)
        arr->a[i - 1] = arr->a[i];
    arr->a[arr->lenght - 1] = 0;
}

int rotate(struct array *arr) //rotating an array
{
    int temp;
    temp = arr->a[0];
    for (int i = 1; i <= arr->lenght - 1; i++)
        arr->a[i - 1] = arr->a[i];
    arr->a[arr->lenght - 1] = temp;
}

int nmissing(struct array arr) //for find missing element of n natural number sorted array
{
    int sum = 0;
    for (int i = 0; i < arr.lenght; i++)
        sum += arr.a[i];
    int n = arr.a[arr.lenght - 1];
    int s = n * (n + 1) / 2;
    printf("the missing element is %d\n", s - sum);
}

int missng1(struct array arr1) //for finding one missing element in an sorted array
{
    int i, a;
    int base = arr1.a[0];
    for (int i = 1; i < arr1.lenght; i++)
    {
        a = arr1.a[i] - i;
        if (base != a)
            return base + i;
    }
    return -1;
}

void sortmissing(struct array arr1) //finding missing element in an sorted arry
{
    int i, a;
    int base = arr1.a[0];
    for (i = 0; i < arr1.lenght; i++)
    {
        a = arr1.a[i] - i;
        if (base != a)
        {
            while (base < a)
            {
                printf("%d\n", base + i);
                base++;
            }
        }
    }
}

int unsortmissing(struct array arr1) //to find missing elements in unsorted array
{
    int l, h, n;
    l = min(arr1);
    h = max(arr1);
    int *hash;
    hash = (int *)malloc(h * sizeof(int));
    hash[0] = 0;
    for (int i = 0; i < arr1.lenght; i++)
    {
        hash[arr1.a[i]]++;
    }
    for (int i = l; i < h; i++)
    {
        if (hash[i] == 0)
            printf("%d ", i);
    }
    free(hash);
}

int sortduplicate(struct array arr1) //to find duplicate element in sorted array
{
    int last_duplicate = 0;
    for (int i = 0; i < arr1.lenght; i++)
    {
        if (arr1.a[i] == arr1.a[i + 1] && arr1.a[i] != last_duplicate)
        {
            printf("%d\n", arr1.a[i]);
            last_duplicate = arr1.a[i];
        }
    }
}

int sortduplicate1(struct array arr1) //for find duplicate element and no of times it repeating in an sorted array
{
    for (int i = 0; i < arr1.lenght; i++)
    {
        if (arr1.a[i] == arr1.a[i + 1])
        {
            int j = i + 1;
            while (arr1.a[j] == arr1.a[i])
                j++;
            printf("%d is repeating %d times\n", arr1.a[i], j - i);
            i = j - 1;
        }
    }
}

int hashduplicate(struct array arr1) //for find duplicate element by hashing for sorted and unsorted array
{
    int h = max(arr1);
    int *hash;
    hash = (int *)malloc(h * sizeof(int));
    hash[0] = 0;
    for (int i = 0; i < arr1.lenght; i++)
        hash[arr1.a[i]]++;
    for (int i = 0; i <= h; i++)
    {
        if (hash[i] > 1)
            printf("the duplicate number is %d and it repeats %d times\n", i, hash[i]);
    }
    free(hash);
}

int pairsum(struct array arr1, int k) //find the pair with sum k
{
    for (int i = 0; i < arr1.lenght - 1; i++)
    {
        for (int j = i + 1; j < arr1.lenght; j++)
        {
            if (arr1.a[i] + arr1.a[j] == k)
                printf("%d + %d =%d\n", arr1.a[i], arr1.a[j], k);
        }
    }
}

int pairsum1(struct array arr1, int k) //find the pair with sum k by hashing(unsorted)
{
    int h = max(arr1);
    int *hash;
    hash = (int *)malloc(h * sizeof(int));
    hash[0] = 0;
    for (int i = 0; i < arr1.lenght; i++)
    {
        if (hash[k - arr1.a[i]] != 0)
            printf("%d + %d = %d\n", arr1.a[i], k - arr1.a[i], k);
        hash[arr1.a[i]]++;
    }
}

int pairsum2(struct array arr1, int k) //find the pair with sum k (sorted)
{
    int i = 0;
    int j = arr1.lenght - 1;
    while (i < j)
    {
        if (arr1.a[i] + arr1.a[j] == k)
        {
            printf("%d + %d = %d\n", arr1.a[i], arr1.a[j], k);
            i++;
            j--;
        }
        else if (arr1.a[i] + arr1.a[j] < k)
            i++;
        else
            j--;
    }
}

int wave(struct array *arr1, int n) //wave of array
{
    for (int i = 0; i < n; i++)
    {
        swap(&arr1->a[i], &arr1->a[i + 1]);
        i++;
    }
    for (int i = 0; i < arr1->lenght; i++)
        printf("%d ", arr1->a[i]);
    printf("\n");
}

int main()
{
    struct array arr;
    arr.a = (int *)malloc(10 * sizeof(int)); //array one
    arr.a[0] = 1;
    arr.a[1] = 2;
    arr.a[2] = 0;
    arr.a[3] = 4;
    arr.a[4] = 9;
    arr.lenght = 10;
    arr.size = 10;

    struct array arr1;
    arr1.a = (int *)malloc(10 * sizeof(int)); //array two
    arr1.a[0] = 1;
    arr1.a[1] = 3;
    arr1.a[2] = 4;
    arr1.a[3] = 5;
    arr1.a[4] = 6;
    arr1.a[5] = 8;
    arr1.a[6] = 9;
    arr1.a[7] = 10;
    arr1.a[8] = 12;
    arr1.a[9] = 14;
    arr1.lenght = 10;
    arr1.size = 10;

    struct array arr2; //array three
    arr2.a = (int *)malloc(10 * sizeof(int));
    arr2.lenght = 0;
    arr2.size = 10;

    /********************************************************************/

    wave(&arr1, 10);
    return 0;
}
