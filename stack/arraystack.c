#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

//creating a stack by using array
void create(struct stack *st)
{
    printf("enter the size of the stack\n");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

//displaying a stack by using array
void display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

//inserting to a stack by using array
void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("stack overflow!!!!!!!!!!!!\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

//delete from a stack by using array
int pull(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("stack underflow!!!!!!!!!!!!\n");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

//getting any value from a stack by using array
int peak(struct stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("index is invalid!!\n");
    else
        x = st.s[st.top - index + 1];
    return x;
}

//checking stack top in stack by using array
int iffull(struct stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}

//finding sttack top element in stack by using array
int stacktop(struct stack st)
{
    if (st.top == -1)
        return -1;
    return st.s[st.top];
}

//checking if stack is empty in stack by using array
int ifempty(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int main()
{
    struct stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    printf("%d\n", peak(st, 4));

    display(st);
    return 0;
}