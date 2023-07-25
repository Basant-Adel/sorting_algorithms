#include "deck.h"

/**
 * _strcmp -> 2 string comparisons
 *@b3: The first string
 *@b4: The second string
 *Return: Successful (0)
 */

int _strcmp(const char *b3, const char *b4)
{
	for (; *b3 && *b4 && *b3 == *b4; b3++, b4++)
	{
		if (*b3 != *b4)
		{
			return (*b3 - *b4);
		}
	}
	return (0);
}


/**
 * get_value -> A function to Obtain a card's numerical value
 *@card:a deck_node_t card pointer.
 *Return: The card's numerical value.
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
	{
		return (0);
	}
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
	{
		return (6);
	}
	if (_strcmp(card->card->value, "7") == 0)
	{
		return (7);
	}
	if (_strcmp(card->card->value, "8") == 0)
	{
		return (8);
	}
	if (_strcmp(card->card->value, "9") == 0)
	{
		return (9);
	}
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
	{
		return (12);
	}
	return (13);
}

/**
 * insertion_sort_deck_kind - A function From spades to diamonds
 *@deck: A pointer to the doubly-linked list
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *item, *inners, *tmp;

	item = (*deck)->next;

	while (item != NULL)
	{
		tmp = item->next;
		inners = item->prev;
		while (inners != NULL && inners->card->kind > item->card->kind)
		{
			inners->next = item->next;
			if (item->next != NULL)
			{
				item->next->prev = inners;
			}
			item->prev = inners->prev;
			item->next = inners;
			if (inners->prev != NULL)
			{
				inners->prev->next = item;
			}
			else
			{
				*deck = item;
			}
			inners->prev = item;
			inners = item->prev;
		}
		item = tmp;
	}
}


/**
 * insertion_sort_deck_value - A function to Sort a deck of cards
 *@deck: A pointer to the doubly-linked list
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *item, *inners, *tmp;

	item = (*deck)->next;
	while (item != NULL)
	{
		tmp = item->next;
		inners = item->prev;
		while (inners != NULL && inners->card->kind == item->card->kind &&
				get_value(inners) > get_value(item))
		{
			inners->next = item->next;
			if (item->next != NULL)
			{
				item->next->prev = inners;
			}
			item->prev = inners->prev;
			item->next = inners;
			if (inners->prev != NULL)
			{
				inners->prev->next = item;
			}
			else
			{
				*deck = item;
			}
			inners->prev = item;
			inners = item->prev;
		}
		item = tmp;
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
