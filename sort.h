#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *left, listint_t *right);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t size);
void merge_sort(int *array, size_t size);
void swap(int *array, size_t size, int a, int b);
void heapify(int *array, size_t size, int root, size_t max_size);
void heap_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_sort_recursive(int *array, size_t size, int up, size_t step);
void bitonic_merge(int *array, size_t size, int up, size_t step);
void quick_sort_hoare(int *array, size_t size);
int card_cmp(const void *a, const void *b);
int kind_cmp(const void *a, const void *b);
void sort_deck(deck_node_t **deck);
#endif /* SORT_H */
