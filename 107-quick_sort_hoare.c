#include "sort.h"

/**
* hoare_partition - Perform the Hoare partition for quicksort.
* @array: The array to be sorted.
* @low: The low index of the partition to be sorted.
* @high: The high index of the partition to be sorted.
* @size: The size of the array.
*
* Return: The pivot index.
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j = high + 1;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return j;

/* Swap array[i] and array[j] */
if (i != j)
{
int temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}

/**
* quicksort_hoare_recursive - Implement the Hoare quicksort recursively.
* @array: The array to be sorted.
* @low: The low index of the partition to be sorted.
* @high: The high index of the partition to be sorted.
* @size: The size of the array.
*/
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = hoare_partition(array, low, high, size);

quicksort_hoare_recursive(array, low, pivot_index, size);
quicksort_hoare_recursive(array, pivot_index + 1, high, size);
}
}

/**
* quick_sort_hoare - Sort an array of integers in ascending order
*                    using the Quick sort algorithm (Hoare partition).
* @array: The array to be sorted.
* @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort_hoare_recursive(array, 0, size - 1, size);
}

