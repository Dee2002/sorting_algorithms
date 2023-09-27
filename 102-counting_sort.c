#include <stdint.h>
#include <stdlib.h>
#include "sort.h"

/**
* counting_sort - Sorts an array of integers using Counting sort algorithm
* @array: The array to be sorted
* @size: Size of the array
*/
void counting_sort(int *array, size_t size)
{
int max = array[0];
int *output, *counting;
size_t i;

for (i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

counting = malloc(sizeof(int) * (max + 1));
if (!counting)
return;
for (i = 0; i <= (size_t)max; i++)  /*Cast max to size_t*/
counting[i] = 0;

for (i = 0; i < size; i++)
counting[array[i]]++;

for (i = 1; i <= (size_t)max; i++)  /*Cast max to size_t*/
counting[i] += counting[i - 1];

print_array(counting, max + 1);
output = malloc(sizeof(int) * size);
if (!output)
{
free(counting);
return;
}

for (i = size - 1; i != SIZE_MAX; i--)
{
output[counting[array[i]] - 1] = array[i];
counting[array[i]]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
free(output);
free(counting);
}

