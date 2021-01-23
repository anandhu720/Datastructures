#include <stdio.h>
#include <stdlib.h>

struct array
{
    char *a;
    int size;
    int lenght;
} arr;

int rotate(struct array *arr) //rotation of array
{
    int a = 0;
    char temp;
    while (a <= 10)
    {
        temp = arr->a[0];
        for (int i = 1; i <= arr->lenght - 1; i++)
            arr->a[i - 1] = arr->a[i];
        arr->a[arr->lenght - 1] = temp;
        for (int j = 0; j < arr->lenght; j++) //display of n array
            printf("%c  ", arr->a[j]);
        a++;
        printf("\n");
    }
}

int main()
{
    arr.a = (char *)malloc(10 * sizeof(char));
    arr.size = 10;
    arr.lenght = 7;
    arr.a[0] = 'e';
    arr.a[1] = 'W';
    arr.a[2] = 'e';
    arr.a[3] = 'l';
    arr.a[4] = 'c';
    arr.a[5] = 'o';
    arr.a[6] = 'm';

    // *************************************************************** //

    rotate(&arr);
    return 0;
}
