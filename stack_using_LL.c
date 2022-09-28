#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void Pushing_data(int input)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = input;
    if (head == NULL)
        newNode->next = NULL;
    else
        newNode->next = head;
    head = newNode;
}

int Pop_data()
{
    if (head == NULL)
    {
        printf("STACK is empty!!");
    }
    else
    {
        struct node *temp = head;
        int temp_data = temp->data;
        head = temp->next;
        free(temp);
        return temp_data;
    }
}

void Display()
{
    struct node *temp = head;
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
    printf("1 - push data\n");
    printf("2 - pop data\n");
    printf("3 - display data\n");
    printf("4 - exit\n");
    while (Id != 4)
    {
        printf("enter your choise...");
        scanf("%d", &Id);
        switch (Id)
        {
        case 1:; // i put semicolon beacause of it get error called "a label can only be part of a statement and a declaration is not a statement" meaning is we cant declare variable after the case so to resolve it we do such kind of thing we also put brackkets as in case 2.
            int input;
            printf("enter the value you want to enter:- ");
            scanf("%d", &input);
            Pushing_data(input);
            break;

        case 2:
        {
            int data;
            data = Pop_data();
            printf("%d is removed from stack.\n", data);
            break;
        }
        case 3:
            Display();
            break;
        }
    }
}
