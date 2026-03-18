#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* firstNeven(int n)
{
    int* array = malloc(n * sizeof(int));
    if (!array) return NULL;
    
    for (int i = 0; i < n; i++)
    {
        array[i] = i * 2;
    }
    
    return array;
}

int main()
{
    int n = 10;
    int* array = firstNeven(n);

    for (int i = 0; i < n; i++)
    {
        printf("%i\n", array[i]);
    }
    free(array);
    return 0;
}