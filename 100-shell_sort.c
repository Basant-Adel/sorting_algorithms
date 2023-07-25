#include "sort.h"

/**
 * swaprs_ints - Swap Alternate two integers in an array.
 * @x: the initial swapped integer to swap.
 * @z: The next integer to be swapped swap.
 */
void swaprs_ints(int *x, int *z)
{
int tmp;

tmp = *x;
*x = *z;
*z = tmp;
}

/**
 * shell_sort - sort Integer arrays should sorted ascending.
 *     utilising the shell sort algorithm arrange.
 * @array: a array  collection of integers.
 * @size: The size array's dimensions.
 * Description: utilises the Knuth interval hierarchy.
 */

void shell_sort(int *array, size_t size)
{
size_t gap,
z, u;

if (array ==
NULL ||
size < 2)
return;

gap = 1;
while (gap < (size / 3))
gap = gap * 3 + 1;

while (gap >= 1)
{
z = gap;
while (z < size)
{
u = z;
while (u >= gap &&
array[u - gap] > array[u])
{
swaprs_ints(array + u,
array + (u - gap));
u -= gap;
}
z++;
}
gap /= 3;
print_array(array, size);
}
}
