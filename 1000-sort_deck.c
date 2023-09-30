#include "deck.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* card_cmp - Compare two card values
* @a: First card to compare
* @b: Second card to compare
* Return: Integer less than, equal to, or greater than zero if a is less than,
* equal to, or greater than b, respectively
*/
int card_cmp(const void *a, const void *b)
{
return strcmp(((card_t *)a)->value, ((card_t *)b)->value);
}

/**
* kind_cmp - Compare two card kinds
* @a: First card to compare
* @b: Second card to compare
* Return: Integer less than, equal to, or greater than zero if a is less than,
* equal to, or greater than b, respectively
*/
int kind_cmp(const void *a, const void *b)
{
return ((card_t *)a)->kind - ((card_t *)b)->kind;
}

/**
* sort_deck - Sorts a deck of cards
* @deck: A pointer to the deck of cards
*/
void sort_deck(deck_node_t **deck)
{
if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
return;

qsort(*deck, 52, sizeof(deck_node_t), card_cmp);
qsort(*deck, 13, sizeof(deck_node_t), kind_cmp);

(*deck)->prev = NULL;
(*deck)->next->prev = *deck;
*deck = (*deck)->next;

sort_deck(deck);
}

