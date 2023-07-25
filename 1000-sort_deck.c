#include "deck.h"

/**
 * _strcmp -> 2 string comparisons
 *@s3: The first string
 *@s4: The second string
 *Return: Successful (0)
 */

int _strcmp(const char *s3, const char *s4)
{
	for (; *s3 && *s4 && *s3 == *s4; s3++, s4++)
	{
	}

	if (*s3 != *s4)
	{
		return (*s3 - *s4);
	}

	return (0);
}


/**
 * get_value -> A function to Obtain a card's numerical value
 *@card:a deck_node_t card pointer
 *Return: The card's numerical value
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
	{
		return (1);
	}
	if (_strcmp(card->card->value, "2") == 0)
	{
		return (2);
	}
	if (_strcmp(card->card->value, "3") == 0)
	{
		return (3);
	}
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind -> A function From spades to diamonds
 *@deck: A pointer to the doubly-linked list
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *ital, *inert, *tmp;

	ital = (*deck)->next;
	while (ital != NULL)
	{
		tmp = ital->next;
		inert = ital->prev;
		while (inert != NULL && inert->card->kind > ital->card->kind)
		{
			inert->next = ital->next;
			if (ital->next != NULL)
			{
				ital->next->prev = inert;
			}
			ital->prev = inert->prev;
			ital->next = inert;
			if (inert->prev != NULL)
			{
				inert->prev->next = ital;
			}
			else
			{
				*deck = ital;
			}
			inert->prev = ital;
			inert = ital->prev;
		}
		ital = tmp;
	}
}


/**
 * insertion_sort_deck_value -> A function to Sort a deck of cards
 *@deck: A pointer to the doubly-linked list
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *ital, *inert, *tmp;

	ital = (*deck)->next;
	while (ital != NULL)
	{
		tmp = ital->next;
		inert = ital->prev;
		while (inert != NULL && inert->card->kind == ital->card->kind &&
				get_value(inert) > get_value(ital))
		{
			inert->next = ital->next;
			if (ital->next != NULL)
			{
				ital->next->prev = inert;
			}
			ital->prev = inert->prev;
			ital->next = inert;
			if (inert->prev != NULL)
			{
				inert->prev->next = ital;
			}
			else
			{
				*deck = ital;
			}
			inert->prev = ital;
			inert = ital->prev;
		}
		ital = tmp;
	}
}


/**
 * sort_deck -> A function to Sort the cards in a deck from ace to king
 *@deck: A pointer to the doubly-linked list
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{
		return;
	}

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
