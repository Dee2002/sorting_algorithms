#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list.
* @list: Pointer to a pointer to the head of the list.
* @left: Pointer to the left node.
* @right: Pointer to the right node.
*/
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left->prev)
left->prev->next = right;
else
*list = right;
if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;

left->prev = right;
right->next = left;
}

/**
* cocktail_sort_list - Sorts a doubly linked list using
*                      the Cocktail Shaker Sort algorithm.
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

