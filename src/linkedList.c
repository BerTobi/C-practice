#include "linkedList.h"

void printList(linkedList* l)
{
    node* current = l->head;

    while (current->next != NULL)
    {
        printf("%i - ", current->value);
        current = current->next;
    }
    printf("%i\n", current->value);
}

void insert(linkedList* l, int a)
{
    node* current = l->head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    node* new = malloc(sizeof(node));
    new->value = a;
    new->next = NULL;
    current->next = new;
    return;
}

int main()
{
    node first = {1, NULL};
    linkedList list = {&first};

    insert(&list, 3);
    insert(&list, 4);
    insert(&list, 9);
    insert(&list, 2);

    printList(&list);

    node* current = list.head->next;
    while (current != NULL)
    {
        node* next = current->next;
        free(current);
        current = next;
    }

}