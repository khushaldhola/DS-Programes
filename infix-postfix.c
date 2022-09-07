#include<stdio.h>
#include<ctype.h>
#include"khushalstack.h"

int main()
{
    char expr[100];
    char *e,c;

    printf("\nenter your expression:-  ");
    scanf("%s",expr);

    e = expr;
    while(*e != '\0')
    {
        if(isalnum(*e)) //checks that passed argument is numaric or alphabet.
            printf("%c",*e);

        else if(*e == '(')
            push(*e);

        else if(*e == ')')
        {
            int j;
            while((j=pop()) != '(')
            {
                printf("%c",j);
            }
        }

        else if(*e == '^')
        {
            if(priority(stackArr[TOP]) <= priority(*e))
                push(*e);
        }

        else
        {
            while(priority(stackArr[TOP]) >= priority(*e))
            {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;

    }
    while(TOP!=-1)
        {
            printf("%c",pop());
        }
    return 0;
}

