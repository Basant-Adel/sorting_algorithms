#include "sort.h"

/**
 * merge -> A function is responsible for merging 2 sub arrays of an array
 *@array: It's an Array
 *@size: The Array of size
 *@left: Left side
 *@right: Right side
 */

void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int L, R;

	L = size / 2;
	R = size - L;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, L);
	printf("[right]: ");
	print_array(right, R);

	while (i < L && j < R)
	{

		if (left[i] < right[j])
		{
			array[k++] = left[i++];
		}

		else
		{
			array[k++] = right[j++];
		}

	}

	while (i < L)
	{
		array[k++] = left[i++];
	}

	while (j < R)
	{
		array[k++] = right[j++];
	}

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort -> Write a function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 **/

void merge_sort(int *array, size_t size)
{

	size_t m = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
	{
		return;
	}

	if (size < 2)
	{
		return;
	}

	m = size / 2;

	for (i = 0; i < m; i++)
	{
		left[i] = array[i];
	}

	for (i = m; i < size; i++)
	{
		right[i - m] = array[i];
	}

	merge_sort(left, m);
	merge_sort(right, size - m);
	merge(array, left, right, size);

}
