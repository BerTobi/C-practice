#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
    int* array;
    int size;
    int cSize;
} vector;

vector init(int initialSize)
{
    vector v;
    v.array = malloc(initialSize * sizeof(int));
    v.size = initialSize;
    v.cSize = 0;
    return v;
}

void push(vector* v, int a)
{
    if (v->cSize < v->size)
    {
        v->array[v->cSize] = a;
        v->cSize++;
    }
    else
    {
        int* newArray = realloc(v->array, v->size * 2 * sizeof(int));
        v->size *= 2;
        v->array = newArray;
        v->array[v->cSize] = a;
        v->cSize++;
        
    }
}

int get(vector* v, int i)
{
    if (i < v->cSize) return v->array[i];
    else return -1;
}

int main()
{
    vector v = init(1);
    
    for (int i = 0; i < 10; i++)
    {
        push(&v, i*3);
    }

    printf("%i", get(&v, 5));
}