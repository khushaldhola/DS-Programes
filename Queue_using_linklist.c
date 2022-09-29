#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enQueue(int input)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = input;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
int deQueue()
{
    int temp_data;
    if (front == NULL && rear == NULL)
    {
        printf("your Queue is Empty.");
        return;
    }
    else
    {
        struct node *temp = front;
        temp_data = temp -> data;
        front = temp->next;
        free(temp);
    }
    return temp_data;
}
void display()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int Id;
    printf("enter correct id to do following tasks....\n");
    printf("1 - enqueue data\n");
    printf("2 - dequeue data\n");
    printf("3 - display data\n");
    printf("4 - exit\n");
    while (Id != 4)
    {
        printf("enter your choise...");
        scanf("%d", &Id);
        switch (Id)
        {
        case 1:;
            int input;
            printf("enter the value you want to enter:- ");
            scanf("%d", &input);
            enQueue(input);
            break;

        case 2:
        {
            int data;
            data = deQueue();
            printf("%d is removed from stack.\n", data);
            break;
        }
        case 3:
            display();
            break;
        }
    }
}
