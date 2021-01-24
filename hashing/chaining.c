#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node **ht;

//creating hash table
void hashtable()
{
    ht = (struct node **)malloc(10 * sizeof(struct node *));
    for (int i = 0; i < 10; i++)
        ht[i] = NULL;
}

//hashing key
int hash(int key)
{
    return key % 10;
}

//inserting to hash Table
void insert(int key)
{
    int hidx = hash(key); //finding hash table index
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->next = NULL;

    //case 1:NO nodes in the linked list
    if (ht[hidx] == NULL)
    {
        ht[hidx] = t;
    }
    else
    {
        struct node *p = ht[hidx];
        struct node *q = ht[hidx];
        //traverse to find inset position
        while (p != NULL && p->data < key)
        {
            q = p;
            p = p->next;
        }
        //case 2: insertion in the frist position
        if (q == ht[hidx])
        {
            t->next = ht[hidx];
            ht[hidx] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

//searching an element in hashtable function
int search(int key)
{
    int hidx = hash(key);
    struct node *p;
    p = ht[hidx];
    while (p)
    {
        if (p->data == key)
        {
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

int main()
{
    int a[] = {16, 25, 12, 39, 6, 122, 5, 68, 75};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        insert(a[i]);
    }

    printf("Successfully search\n");
    int key = 6;
    int value = search(key);
    printf("Key:%d , value:%d \n", key, value);
    key = 95;
    value = search(key);
    printf("Key:%d , value:%d \n", key, value);

    return 0;
}