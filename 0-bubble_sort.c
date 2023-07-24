#include "sort.h"

/**
 * bubble_sort -> Write a function that sorts an array of integers
 *in ascending order using the Bubble sort algorithm
 *
 *@array: It's an Array
 *@size: It's a size
 **/

void bubble_sort(int *array, size_t size)
{
	size_t b, n, s;

	for (b = 0; b < size; b++)
	{

		for (n = 1; n < size - b; n++)
		{

			if (array[n - 1] > array[n])
			{

				s = array[n];
				array[n] = array[n - 1];
				array[n - 1] = s;
				print_array(array, size);

			}

		}

	}

}
