#include <stdio.h>
#include "sort.h"

/**
* lomuto_partition - Implements Lomuto partition scheme for quicksort
*
* @array: The array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Number of elements in @array
*
* Return: Index of the pivot element
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j, temp;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;
if (i != j)
print_array(array, size); /*Print the array after each swap*/
}
}

temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
if (i + 1 != high)
print_array(array, size); /* Print the array after each swap*/

return (i + 1);
}

/**
* quicksort - Implements the quicksort algorithm using Lomuto partition
*
* @array: The array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Number of elements in @array
*/
void quicksort(int *array, int low, int high, size_t size)
{
int pi;

if (low < high)
{
pi = lomuto_partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order using
*              the Quick sort algorithm (Lomuto partition).
*
* @array: The array to be sorted
* @size: Number of elements in @array
*/
void quick_sort(int *array, size_t size)
{
if (array && size > 1)
quicksort(array, 0, size - 1, size);
}

