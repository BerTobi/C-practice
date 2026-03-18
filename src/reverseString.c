#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStringInPlace(char* s)
{
    char* end = s;
    int size = 0;

    while (*end != '\0')
    {
        end++;
        size++;
    } 
    end--;

    int current = 0;
    while (current < size / 2)
    {
        char temp = *s;
        *s = *end;
        *end = temp; 
        s++;
        end--;
        current++;
    }

    return;
}

char* reversedString(char* s)
{
    int size = 0;
    char* begin = s;

    while (*s != '\0')
    {
        s++;
        size++;
    } 
    s--;

    char* new = malloc(size + 1);
    for (int i = 0; i < size; i++)
    {
        new[i] = *s;
        s--;
    }
    new[size] = '\0';

    return new;
}

int main()
{
    char test[] = "Hello";
    reverseStringInPlace(test);
    printf(test);

    printf(reversedString(test));
}