#include "sort.h"

/**
* swap - Swaps two integers in an array
* @array: The array containing the integers
* @size: The size of the array
* @a: Index of the first integer to swap
* @b: Index of the second integer to swap
*/
void swap(int *array, size_t size, int a, int b)
{
int temp;

if (a != b)
{
temp = array[a];
array[a] = array[b];
array[b] = temp;
print_array(array, size);
}
}

/**
* heapify - Heapify a binary tree into a max heap
* @array: The array containing the integers
* @size: The size of the array
* @root: Index of the root node
* @max_size: The maximum size of the heap
*/
void heapify(int *array, size_t size, int root, size_t max_size)
{
size_t largest = root;
size_t left = 2 * root + 1;
size_t right = 2 * root + 2;

if (left < max_size && array[left] > array[largest])
largest = left;

if (right < max_size && array[right] > array[largest])
largest = right;

if (largest != (size_t)root)
{
swap(array, size, (int)root, (int)largest);
heapify(array, size, largest, max_size);
}
}

/**
* heap_sort - Sorts an array of integers in ascending order using Heap sort
* @array: The array to be sorted
* @size: The size of the array
*/
void heap_sort(int *array, size_t size)
{
int i;

if (!array || size < 2)
return;

for (i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);

for (i = size - 1; i > 0; i--)
{
swap(array, size, 0, i);
heapify(array, size, 0, i);
}
}

