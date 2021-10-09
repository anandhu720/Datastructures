#include <iostream>
using namespace std;

class queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    //creating a queue by using array
    queue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }

    queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];
    }

    void enqueue(int x);
    void display();
    int dequeue();
};

void queue::enqueue(int x)
{
    if (rear == size - 1)
        printf("queue overflow!!!!!!\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}

void queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        printf("%d ", Q[i]);
    printf("\n");
}

int queue::dequeue()
{
    int x = -1;
    if (front == rear)
        printf("queue underflow!!!!!!\n");
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

//main function!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main()
{
    queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << "\n";

    q.display();

    return 0;
}