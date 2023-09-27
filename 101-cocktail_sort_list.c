#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list.
* @list: Pointer to a pointer to the head of the list.
* @a: Pointer to the first node.
* @b: Pointer to the second node.
*/
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
if (a->prev)
a->prev->next = b;
else
*list = b;

if (b->next)
b->next->prev = a;

a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}

/**
* cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort.
* @list: Pointer to a pointer to the head of the list.
*/
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *curr, *end;

if (!list || !*list || !(*list)->next)
return;

while (swapped)
{
swapped = 0;
for (curr = *list; curr->next != NULL; curr = curr->next)
{
if (curr->n > curr->next->n)
{
swap_nodes(list, curr, curr->next);
print_list(*list);
swapped = 1;
}
}
if (!swapped)
break;

swapped = 0;
for (end = curr; end->prev != NULL; end = end->prev)
{
if (end->n < end->prev->n)
{
swap_nodes(list, end->prev, end);
print_list(*list);
swapped = 1;
}
}
}
}
