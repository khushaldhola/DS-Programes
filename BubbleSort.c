#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("enter the value of array size :- ");
    scanf("%d",&size);
    int arr[size];


    for (int i = 0; i < size; i++)
    {
        printf("enter arr[%d] :- ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Sorting
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Display
    for (int i = 0; i < size; i++)
        printf("\narr[%d] = %d", i + 1, arr[i]);
}
