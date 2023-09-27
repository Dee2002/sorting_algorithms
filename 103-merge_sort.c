#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
* merge - Merges two sub-arrays of the array.
* @array: The array to be merged.
* @left: The left sub-array.
* @right: The right sub-array.
* @size: The size of the array.
*/
void merge(int *array, int *left, int *right, size_t size)
{
int *temp = malloc(sizeof(int) * size);
size_t i = 0, j = 0, k = 0;

printf("Merging...\n[left]: ");
print_array(left, size / 2);
printf("[right]: ");
print_array(right, size - size / 2);

while (i < size / 2 || j < size - size / 2)
{
if (j >= size - size / 2 || (i < size / 2 && left[i] <= right[j]))
temp[k++] = left[i++];
else
temp[k++] = right[j++];
}

for (i = 0; i < size; i++)
array[i] = temp[i];

printf("[Done]: ");
print_array(array, size);
free(temp);
}

/**
* merge_sort - Sorts an array of integers using Merge sort algorithm.
* @array: The array to be sorted.
* @size: Size of the array.
*/
void merge_sort(int *array, size_t size)
{
if (size > 1)
{
size_t mid = size / 2;
int *left = array;
int *right = array + mid;

merge_sort(left, mid);
merge_sort(right, size - mid);
merge(array, left, right, size);
}
}

