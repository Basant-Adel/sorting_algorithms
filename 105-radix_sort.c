#include "sort.h"

/**
 * max_val -> A function is finding the
 *maximum value from an array of integers
 *
 *@array: It's an Array
 *@size: The Array of size
 *Return: The Max
 */

int max_val(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{

		if (array[i] > max)
		{
			max = array[i];
		}

	}

	return (max);
}

/**
 * radix_sort -> Write a function that sorts an array of
 *integers in ascending order using the Radix sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 */

void radix_sort(int *array, size_t size)
{
	int *new;
	int i, max, y = 1;
	int q = size;

	if (!array || size < 2)
	{
		return;
	}
	max = max_val(array, size);
	new = malloc(sizeof(int) * size);
	while (max / y > 0)
	{
		int brews[20] = {0};
		i = 0;
		while (i < q)
		{
			brews[(array[i] / y) % 10]++;
			i++;
		}
		if (brews != NULL)
		{
			for (i = 1; i < 10; i++)
			{
				brews[i] += brews[i - 1];
			}
			for (i = q - 1; i >= 0; i--)
			{
				new[brews[(array[i] / y) % 10] - 1] = array[i];
				brews[(array[i] / y) % 10]--;
			}
			for (i = 0; i < q; i++)
			{
				array[i] = new[i];
			}
		}
		y *= 10;
		print_array(array, size);
	}
	free(new);
}
