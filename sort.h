#ifndef SORT_H
#define SORT_H


/* The C Standard Library */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Data structures */


/**
 * struct listint_s -> Doubly linked list node
 *
 *@n: Integer stored in the node
 *@prev: Pointer to the previous element of the list
 *@next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Prototypes  */


int max_val(int *array, size_t size);
void print_list(const listint_t *list);
void heap_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
/* void quick_sort(int *array, size_t size); */
void merge_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void bitonic_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void print_array(const int *array, size_t size);
/* void swap(int *array, ssize_t item1, ssize_t item2); */
/* void swap(int arr[], int item1, int item2, int order); */
listint_t *swap_node(listint_t *node, listint_t **list);
/* void merge(int arr[], int low, int n_elemnt, int order); */
/* void merge(int *array, int *left, int *right, size_t size); */
void swap1(listint_t **list, listint_t *head, listint_t *aux);
void swap2(listint_t **list, listint_t *head, listint_t *aux);
int hoare_partition(int *array, int first, int last, int size);
/* void quick_sort(int *array, ssize_t first, ssize_t last, int size); */
void check_tree(int *array, size_t size_init, size_t size, size_t i);
void ssort_bitonic(int arr[], int low, int n_elemnt, int order, int size);
void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size);


#endif
