#include "sort.h"

/**
 * swap -> A function is used to swap 2 elements in an array
 *@arr: It's an Array
 *@item1: The Item 1
 *@item2: The Item 2
 *@order: It's a (1) Ascending Order (0) Descending Order
 */

void swap(int arr[], int item1, int item2, int order)
{

	int b;

	if (order == (arr[item1] > arr[item2]))
	{

		b = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = b;

	}

}

/**
 * merge -> A function to Sort an array of integers
 *in ascending order
 *
 *@arr: It's an Array
 *@low: It's a (1) Element
 *@n_elemnt: The Element of Number
 *@order: It's a (1) Ascending Order (0) Descending Order
 */

void merge(int arr[], int low, int n_elemnt, int order)
{
	int m, i;

	if (n_elemnt > 1)
	{

		m = n_elemnt / 2;

		for (i = low; i < low + m; i++)
		{
			swap(arr, i, i + m, order);
		}

		merge(arr, low, m, order);
		merge(arr, low + m, m, order);

	}
}

/**
 * ssort_bitonic -> A function to Sort an array of
 *integers in ascending order
 *
 *@arr: It's an Array
 *@low: It's a (1) Element
 *@n_elemnt: The Element of Number
 *@order: It's a (1) Ascending Order (0) Descending Order
 *@size: The List of size
 */

void ssort_bitonic(int arr[], int low, int n_elemnt, int order, int size)
{
	int m;

	if (n_elemnt > 1)
	{

		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}

		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}

		m = n_elemnt / 2;
		ssort_bitonic(arr, low, m, 1, size);
		ssort_bitonic(arr, low + m, m, 0, size);
		merge(arr, low, n_elemnt, order);

		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}

		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}
	}
}

/**
 * bitonic_sort -> Write a function that sorts an array of integers
 *in ascending order using the Bitonic sort algorithm
 *
 *@array: It's an Array
 *@size: The List of size
 */

void bitonic_sort(int *array, size_t size)
{

	int order = 1;

	if (!array || size < 2)
	{
		return;
	}

	ssort_bitonic(array, 0, size, order, size);

}
