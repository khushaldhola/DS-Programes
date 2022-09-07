#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int items[SIZE], front = -1, rear = -1;

void enQueue();
void deQueue();
void display();

int main()
{
    enQueue(120);
    enQueue(20);
    enQueue(30);
    deQueue();
    display();

    return 0;
}

void enQueue(int data)
{
    if (rear == SIZE-1)
        printf("Queue is full.\n");
    else
    {
        if(front == -1)
        {
            front = 0;
            rear++;
            items[rear] = data;
        }
        else{
            rear++;
            items[rear] = data;
        }
    }
}

void deQueue()
{
    if (front == -1)
        printf("Queue is empty.\n");
    else
    {
        printf("%d is to be deleted from the queue\n", items[front]);
        front++;

        if (front == rear + 1) // or we can simply write (front > rear)
        {
            rear = -1;
            front = -1;
        }
    }
}
void display()
{
    if (rear == -1)
        printf("sorry! Queue is empty\n");
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d\n",items[i]);
        }
    }
}