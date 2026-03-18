#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUCKETS 32

typedef struct mapNode 
{
    char* key;
    int value;
    struct mapNode* next;
} mapNode;

typedef struct map
{
    mapNode* buckets[NUM_BUCKETS];
} map;

void insertNode(mapNode* l, mapNode* n)
{
    mapNode* current = l;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = n;
    return;
}

int hashFunction(char* key)
{
    int hash = 0;
    while (*key != '\0')
    {
        hash += *key;
        key++;
    }
    return hash % NUM_BUCKETS;
}

void put(map* m, char* k, int v)
{
    int hash = hashFunction(k);
    mapNode* new = malloc(sizeof(mapNode));
    new->value = v;
    new->key = k;
    new->next = NULL;
    if (m->buckets[hash] == NULL)
        m->buckets[hash] = new;
    else
        insertNode(m->buckets[hash], new);
}

int get(map* m, char* k)
{
    int hash = hashFunction(k);
    if (m->buckets[hash] == NULL) return -1;
    mapNode* current = m->buckets[hash];

    while(strcmp(current->key, k) != 0)
    {
        if (current == NULL) return -1;
        current = current->next;
    }
    
    return current->value;
}

void delete(map* m, char* k)
{
    int hash = hashFunction(k);
    if (m->buckets[hash] == NULL) return;
    mapNode* current = m->buckets[hash];
    mapNode* past;

    if (strcmp(current->key, k) == 0)
    {
        m->buckets[hash] = current->next;
        free(current);
        return;
    }

    while(strcmp(current->key, k) != 0)
    {
        past = current;
        current = current->next;
    }
    past->next = current->next;
    free(current);
}

int main()
{
    map testMap = {0};
    put(&testMap, "H", 10);
    put(&testMap, "Hello", 23);
    put(&testMap, "a", 16);
    put(&testMap, "tac", 25);
    put(&testMap, "cat", 28);
    printf("%i\n", get(&testMap, "H"));
    printf("%i\n", get(&testMap, "Hello"));
    printf("%i\n", get(&testMap, "a"));
    printf("%i\n", get(&testMap, "tac"));
    printf("%i\n", get(&testMap, "cat"));
    delete(&testMap, "H");
    printf("%i\n", get(&testMap, "H"));
}