#include "sort.h"

/**
 * quick_sort_rec -> Write a function that sorts an array of integers in
 *ascending order using the Quick sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 *@array_init: The Initial of Array
 *@size_init: The Initial Array of size
 */

void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size)
{
	size_t y, a;
	int b;
	int i = -1, n, p = array[size - 1];

	if (array && size > 1)
	{
		for (y = 0; y < size - 1; y++)
		{
			if (array[y] < p)
			{
				i++;
				a = i;

				if (a != y && array[y] != array[a])
				{
					n = array[y];
					array[y] = array[i];
					array[i] = n;
					print_array(array_init, size_init);
				}
			}
		}

		b = size;

		if (b - 1 != i + 1 && array[b - 1] != array[i + 1])
		{
			array[size - 1] = array[i + 1];
			array[i + 1] = p;
			print_array(array_init, size_init);
		}

		if (i > 0)
		{
			quick_sort_rec(array_init, size_init, array, i + 1);
		}

		quick_sort_rec(array_init, size_init, array + i + 2,  size - (i + 2));
	}
}

/**
 * quick_sort -> function is sorting an array of integers
 *in ascending order using the Quick sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 */

void quick_sort(int *array, size_t size)
{

	int *_array;
	size_t _size;

	if (array)
	{

		_array = array;
		_size = size;
		quick_sort_rec(_array, _size, array, size);

	}

}
