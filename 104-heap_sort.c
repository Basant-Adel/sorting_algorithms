#include "sort.h"

/**
 * check_tree -> A function is used to check and maintain
 *the heap property of a binary tree
 *
 *@array: It's an Array
 *@size: The Array of size
 *@size_init: The Array of Initial Size
 *@i: Index
 */

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
	int n, b1, b2;
	size_t ar1, ar2;

	ar1 = i * 2 + 1;
	ar2 = ar1 + 1;
	b1 = array[ar1];
	b2 = array[ar2];

	if (((ar1 < size) && (ar2 < size) && (b1 >= b2 && b1 > array[i]))
		|| ((ar1 == size - 1) && b1 > array[i]))
	{
		n = array[i];
		array[i] = b1;
		array[ar1] = n;
		print_array(array, size_init);
	}

	else if ((ar1 < size) && (ar2 < size) && (b2 > b1 && b2 > array[i]))
	{
		n = array[i];
		array[i] = b2;
		array[ar2] = n;
		print_array(array, size_init);
	}

	if (ar1 < size - 1)
	{
		check_tree(array, size_init, size, ar1);
	}

	if (ar2 < size - 1)
	{
		check_tree(array, size_init, size, ar2);
	}
}

/**
 * heap_sort -> Write a function that sorts an array of integers
 *in ascending order using the Heap sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 */

void heap_sort(int *array, size_t size)
{

	size_t x, size_init = size;
	int n;

	if (!array)
	{
		return;
	}

	for (x = 0; x < size / 2 ; x++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - x);
	}

	for (x = 0; x < size_init - 1; x++)
	{
		n = array[0];
		array[0] = array[size - 1 - x];
		array[size - 1 - x] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - x - 1, 0);
	}

}
