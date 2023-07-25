#ifndef DECK_H
#define DECK_H


/* The C Standard Library */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Data structures */


/**
 * enum kind_e -> A function to list of card
 *@SPADE: The Spade
 *@HEART: The Heart
 *@CLUB: The Club
 *@DIAMOND: The Diamond
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;


/**
 * struct card_s -> A function to Play card
 *@value: Value of the card
 *From "Ace" to "King"
 *@kind: Kind of the card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;


/**
 * struct deck_node_s -> A function to Deck of card
 *@card: Pointer to the card of the node
 *@prev: Pointer to the previous node of the list
 *@next: Pointer to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;


/* Prototypes  */


/* char get_value(deck_node_t *card); */
void sort_deck(deck_node_t **deck);
/* int _strcmp(const char *b3, const char *b4); */
/* void insertion_sort_deck_kind(deck_node_t **deck); */
/* void insertion_sort_deck_value(deck_node_t **deck); */


#endif
