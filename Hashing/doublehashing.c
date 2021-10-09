#include <stdio.h>
#include <stdlib.h>

#define size 10
#define prime 7

int hash(int key)
{
    return key % size;
}

int primehash(int key)
{
    return prime - (key % prime);
}

int doublehash(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while (h[(hash(index) + i * primehash(index)) % size] != 0)
        i++;
    return (index + i * primehash(index)) % size;
}

void insert(int h[], int key)
{
    int index = hash(key);

    if (h[index] != 0)
        index = doublehash(h, key);
    h[index] = key;
}

int search(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while (h[(hash(index) + i * primehash(index)) % size] != key)
    {
        i++;
        if (h[(hash(index) + i * primehash(index)) % size] == 0)
            return -1;
    }
    return (hash(index) + i * primehash(index)) % size;
}

int main()
{
    int a[] = {5, 25, 15, 35, 95};
    int n = sizeof(a) / sizeof(a[0]);

    //hash Table
    int h[10] = {0};
    for (int i = 0; i < n; i++)
    {
        insert(h, a[i]);
    }

    int index = search(h, 25);
    printf("key found at:%d\n", index);

    index = search(h, 35);
    printf("value found at:%d\n", index);

    return 0;
}