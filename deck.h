#ifndef DECK_H
#define DECK_H

/**
* enum kind_e - Represents the kinds of cards
* @SPADE: Spades
* @HEART: Hearts
* @CLUB: Clubs
* @DIAMOND: Diamonds
*/
typedef enum kind_e
{
SPADE = 0,
HEART,
CLUB,
DIAMOND
} kind_t;

/**
* struct card_s - Represents a playing card
* @value: The card's value (e.g., "Ace" to "King")
* @kind: The card's kind (e.g., SPADE, HEART, CLUB, DIAMOND)
*/
typedef struct card_s
{
const char *value;
const kind_t kind;
} card_t;

/**
* struct deck_node_s - Represents a node in a deck of cards
* @card: Pointer to the card
* @prev: Pointer to the previous node
* @next: Pointer to the next node
*/
typedef struct deck_node_s
{
const card_t *card;
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;

/* Function prototype for sorting the deck of cards */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
