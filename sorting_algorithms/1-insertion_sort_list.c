#include <stdio.h>
#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
*                       order using the Insertion sort algorithm.
*
* @list: Pointer to a pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *temp;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;

while (current != NULL)
{
temp = current;
prev = current->prev;

while (prev != NULL && prev->n > temp->n)
{
prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = prev;
temp->next = prev;
temp->prev = prev->prev;
prev->prev = temp;

if (temp->prev != NULL)
temp->prev->next = temp;
else
*list = temp;

prev = temp->prev;
print_list(*list); /*Print the list after each swap*/
}

current = current->next;
}
}

