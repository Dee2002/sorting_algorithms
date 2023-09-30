#include <stdio.h>
#include "sort.h"

/**
* bitonic_merge - Merges two subarrays in bitonic order
* @array: The array containing the integers
* @size: The size of the array
* @up: 1 if merging in ascending order, 0 if descending
* @step: The step size for merging
*/
void bitonic_merge(int *array, size_t size, int up, size_t step)
{
size_t i;
int temp;

for (i = 0; i < size / 2; i++)
{
if ((array[i] > array[i + step]) == up)
{
temp = array[i];
array[i] = array[i + step];
array[i + step] = temp;
}
}
}

/**
*  * bitonic_sort_recursive - Recursively sorts a bitonic sequence
*   * @array: The array containing the integers
*    * @size: The size of the array
*     * @up: 1 if sorting in ascending order, 0 if descending
*      * @step: The step size for sorting
*       */
void bitonic_sort_recursive(int *array, size_t size, int up, size_t step)
{
if (size <= 1)
return;

printf("Merging [%lu/%lu] (%s):\n", size, size, up ? "UP" : "DOWN");
print_array(array, size);

bitonic_sort_recursive(array, size / 2, 1, step / 2);
bitonic_sort_recursive(array + size / 2, size / 2, 0, step / 2);
bitonic_merge(array, size, up, step);

printf("Result [%lu/%lu] (%s):\n", size, size, up ? "UP" : "DOWN");
print_array(array, size);
}

/**
* bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
* @array: The array to be sorted
* @size: The size of the array (must be a power of 2)
*/
void bitonic_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

bitonic_sort_recursive(array, size, 1, size);
}
