#include "sort.h"

/**
* swap -> A function is used to swap 2 elements in an array
*@array: It's an Array
*@item1: The Item 1
*@item2: The Item 2
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{

	int b;

	b = array[item1];
	array[item1] = array[item2];
	array[item2] = b;

}

/**
 * hoare_partition -> A function is implementing the
 *Hoare partition scheme for the Quick Sort algorithm
 *
 *@array: It's an Array
 *@first: The Element (1)
 *@last: The Element (Last)
 *@size: The Array of size
 *Return: Value
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int a = first - 1, b = last + 1;
	int p = array[last];

	while (1)
	{
		do {
			a++;
		} while (array[a] < p);

		do {
			b--;
		} while (array[b] > p);

		if (a >= b)
		{
			return (a);
		}

		swap(array, a, b);
		print_array(array, size);

	}
}

/**
 * quick_ssort -> A function to Quick Sort of Algorithm
 *@array: It's an Array
 *@first: The Element (1)
 *@last: The Element (2)
 *@size: The Array of size
 */

void quick_ssort(int *array, ssize_t first, ssize_t last, int size)
{

	ssize_t b = 0;

	if (first < last)
	{

		b = hoare_partition(array, first, last, size);
		quick_ssort(array, first, b - 1, size);
		quick_ssort(array, b, last, size);

	}

}

/**
 *quick_sort_hoare -> Write a function that sorts an array of
 *integers in ascending order using the Quick sort algorithm
 *
 *@array: It's an Array
 *@size: The Array of size
 */

void quick_sort_hoare(int *array, size_t size)
{

	if (!array || size < 2)
	{
		return;
	}

	quick_ssort(array, 0, size - 1, size);
}
