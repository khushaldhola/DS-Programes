#include <stdio.h>

int SIZE = 100;
int TOP = -1;
char stackArr[100];

int isEmpty()
{
    if (TOP == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (TOP == SIZE)
        return 1;
    else
        return 0;
}

int topData()
{
    return stackArr[TOP];
}

char push(char x)
{
    if (!isFull())
    {
        TOP = TOP + 1;
        stackArr[TOP] = x;
    }
    else
    {
        printf("stack is full..\n");
    }
}

int pop()
{
    if (!isEmpty())
    {
        char x = stackArr[TOP];
        TOP = TOP - 1;
        return x;
    }
    else
    {
        printf("stack is empty..\n");
    }
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    else if (x == '*' || x == '/')
        return 2;

    else if (x == '^')
        return 3;

    else
        return 0;
}

int str_len(char *str)
{
    int i = 0;

    while (*(str + 1) != '\0')
        i++;
    return i;
}

void reverse_str(char *str)
{
    int i, len;
    char *start, *end, *temp;

    len = str_len(str);
    start = str;
    end = str;

    for (i = 0; i < len - 1; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;

        start++;
        end--;
    }
}