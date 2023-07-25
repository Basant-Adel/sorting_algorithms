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
	int x, y, z = 1, temp, flag = 0;

	if (!array || size < 2)
	{
		return;
	}

	while (z < (int)size)
	{
		z = 3 * z + 1;
	}

	while (z > 0)
	{

		for (x = z; x < (int)size; x++)
		{
			temp = array[x];
			y = x;

			while (y >= z && temp < array[y - z])
			{
				array[y] = array[y - z];
				y -= z;
				flag = 1;
			}

			array[y] = temp;

		}

		z /= 3;

		if (flag == 1)
		{
			print_array(array, size);
			flag = 0;
		}
	}
}
