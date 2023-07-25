#include "sort.h"

/**
 * swap_2_ints - A function to Swap 2 integers in an array
 *@a: The integer (1)
 *@b: The next integer (2)
 */

void swap_2_ints(int *a, int *b)
{

	int sum;

	sum = *a;
	*a = *b;
	*b = sum;

}

/**
 * shell_sort -> Write a function that sorts an array of integers
 *in ascending order using the Shell sort algorithm,
 *using the Knuth sequence
 *
 *@array: It's an Array
 *@size: The Array of size
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, s, d;

	if (array == NULL || size < 2)
	{
		return;
	}

	gap = 1;

	while (gap < (size / 3))
	{
		gap = gap * 3 + 1;
	}

	while (gap >= 1)
	{

		s = gap;

		while (s < size)
		{

			d = s;

			while (d >= gap && array[d - gap] > array[d])
			{
				swap_2_ints(array + d, array + (d - gap));
				d -= gap;
			}

			s++;

		}

		gap /= 3;
		print_array(array, size);

	}
}
