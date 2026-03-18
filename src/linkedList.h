#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

typedef struct linkedList
{
    node* head;
} linkedList;

void printList(linkedList* l);
void insert(linkedList* l, int a);