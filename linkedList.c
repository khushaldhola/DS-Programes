#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// struct node *InsByValue(struct node *head_ref, int data);
insertFirst(struct node **head_ref, int input);
insertLast(struct node **head_ref, int input);
inAtPos(struct node **head_ref, int input, int pos);

int main()
{

    struct node *first = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *head = NULL;
    head = first;

    first->data = 1;
    first->next = second;

    second->data = 5;
    second->next = third;

    third->data = 7;
    third->next = NULL;

    insertFirst(&head, 11);
    // head = InsByValue(head, 11);
    insertLast(&head, 15);
    inAtPos(&head, 3, 2);
    printall(head);

    return 0;
}

printall(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

insertFirst(struct node **head_ref, int input)
{ // pass by reference
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = input;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}
/*
struct node *InsByValue(struct node *head_ref, int input){      //pass by value
    struct node *anotherNode = malloc(sizeof(struct node));
    anotherNode -> input = input;
    anotherNode -> next = head_ref;
    head_ref = anotherNode;
    return head_ref;
}*/

insertLast(struct node **head_ref, int input)
{
    struct node *ptr = NULL;
    ptr = (*head_ref);
    while ((ptr->next) != NULL)
    {
        ptr = ptr->next;
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = input;
    newNode->next = NULL;
    ptr->next = newNode;
}

inAtPos(struct node **head_ref, int input, int pos)
{
    struct node *new = NULL;
    new = (*head_ref);
    int count = 1;
    while (count != pos-1)
    {
        new = new->next;
        count++;
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = input;
    newNode->next = (new->next);
    new->next = newNode;
}