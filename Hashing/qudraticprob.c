#include <stdio.h>
#define size 10

//hashing key
int hash(int key)
{
    return key % size;
}

//qudratic probing function
int qudraticprob(int ht[], int key)
{
    int index = hash(key);
    int i = 0;
    //searching for free space in hashtable
    while (ht[index + i * i] % size != 0)
        i++;
    return (index + i * i) % size;
}

//inserting to hash table
void insert(int ht[], int key)
{
    int index = hash(key);

    if (ht[index] != 0)
    {
        index = qudraticprob(ht, key);
    }
    ht[index] = key;
}

//search function
int search(int ht[], int key)
{
    int index = hash(key);

    int i = 0;

    while (ht[(index + i * i) % size] != key)
        i++;
    return (index + i * i) % size;
}

int main()
{
    int ht[10] = {0};

    insert(ht, 12);
    insert(ht, 25);
    insert(ht, 35);
    insert(ht, 15);

    printf("key found at %d\n", search(ht, 15));
    return 0;
}