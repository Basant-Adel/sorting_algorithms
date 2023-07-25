#include "sort.h"

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
	size_t kun[1000], k = 0, y = 0, i;
	int n;

	if (!array)
	{
		return;
	}

	while (y * 3 + 1 < size)
	{
		kun[k] = y * 3 + 1;
		y = kun[k++];
	}

	for (i = 0; i < k; i++)
	{
		for (y = 0; y < size; y++)
		{
			if ((y + kun[k - i - 1]) > size - 1)
			{
				break;
			}
			k = y;

			while (array[k] > array[k + kun[k - i - 1]])
			{
				n = array[k];
				array[k] =  array[k + kun[k - i - 1]];
				array[k + kun[k - i - 1]] = n;
				k = k - kun[k - i - 1];

				if (k > 0)
				{
					break;
				}
			}
		}
		print_array(array, size);
	}
}
