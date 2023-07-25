#include "sort.h"

/**
 * selection_sort -> Write a function that sorts an array of integers in
 *ascending order using the Selection sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, z, n;
	int a, b;

	if (array)
	{
		for (x = 0; x < size; x++)
		{
			a = array[x];
			b = 0;

			for (y = x; y < size ; y++)
			{
				if (array[y] < a)
				{
					n = y;
					a = array[y];
					b = 1;
				}
			}

			if (b == 1)
			{
				z = array[x];
				array[x] = array[n];
				array[n] = z;
				print_array(array, size);
			}
		}
	}
}
