#include "deck.h"

int _strcmp(const char *s3, const char *s4);
char get_valud(deck_node_t *card);
void inssttion_sort_deck_kind(deck_node_t **deck);
void inssttion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - two string comparisons.
 * @s3: the initial string being compared.
 * @s4: comparing the second string.
 * Return: a difference of one byte in favour if s3 > s4
 *     0 if s3 == s4
 *      If s3 > s4, the byte difference is negative
 */
int _strcmp(const char *s3,
const char *s4)
{
for (; *s3 && *s4 && *s3 ==
*s4; s3++, s4++)
{
}

if (*s3 !=
*s4)
return (*s3 - *s4);
return (0);
}


/**
 * get_valud - Obtain a card's numerical value.
 * @card:a deck_node_t card pointer.
 * Return: The card's numerical value.
 */
char get_valud(deck_node_t *card)
{
if (_strcmp(card->card->value,
"Ace") == 0)
return (0);
if (_strcmp(card->card->value,
"1") == 0)
return (1);
if (_strcmp(card->card->value,
"2") == 0)
return (2);
if (_strcmp(card->card->value,
"3") == 0)
return (3);
if (_strcmp(card->card->value,
"4") == 0)
return (4);
if (_strcmp(card->card->value,
"5") == 0)
return (5);
if (_strcmp(card->card->value,
"6") == 0)
return (6);
if (_strcmp(card->card->value,
"7") == 0)
return (7);
if (_strcmp(card->card->value,
"8") == 0)
return (8);
if (_strcmp(card->card->value,
"9") == 0)
return (9);
if (_strcmp(card->card->value,
"10") == 0)
return (10);
if (_strcmp(card->card->value,
"Jack") == 0)
return (11);
if (_strcmp(card->card->value,
"Queen") == 0)
return (12);
return (13);
}

/**
 * inssttion_sort_deck_kind - From spades to diamonds,oer deck of cards.
 * @deck: a pointer to the doubly-linked list called deck_node_t.
 */
void inssttion_sort_deck_kind(deck_node_t **deck)
{
deck_node_t *itar,
*innert, *tmp;

itar = (*deck)->next;
while (itar != NULL)
{
tmp = itar->next;
innert = itar->prev;
while (innert != NULL &&
innert->card->kind > itar->card->kind)
{
innert->next = itar->next;
if (itar->next != NULL)
itar->next->prev = innert;
itar->prev = innert->prev;
itar->next = innert;
if (innert->prev != NULL)
innert->prev->next = itar;
else
*deck = itar;
innert->prev = itar;
innert = itar->prev;
}
itar = tmp;
}
}


/**
 * inssttion_sort_deck_value - Sort a deck of cards starting from the suit
 *             from ace to king, from spades to diamonds.
 * @deck: a pointer to the doubly-linked list called deck_node_t.
 */
void inssttion_sort_deck_value(deck_node_t **deck)
{
deck_node_t *itar, *innert,
*tmp;

itar = (*deck)->next;
while (itar != NULL)
{
tmp = itar->next;
innert = itar->prev;
while (innert != NULL &&
innert->card->kind == itar->card->kind &&
get_valud(innert) > get_valud(itar))
{
innert->next = itar->next;
if (itar->next != NULL)
itar->next->prev = innert;
itar->prev = innert->prev;
itar->next = innert;
if (innert->prev != NULL)
innert->prev->next = itar;
else
*deck = itar;
innert->prev = itar;
innert = itar->prev;
}
itar = tmp;
}
}


/**
 * sort_deck - Sort the cards in a deck from ace to king, and
 *   between spades and diamonds.
 * @deck: a pointer to the doubly-linked list called deck_node_t.
 */
void sort_deck(deck_node_t **deck)
{
if (deck == NULL || *deck == NULL ||
(*deck)->next == NULL)
return;

inssttion_sort_deck_kind(deck);
inssttion_sort_deck_value(deck);
}
