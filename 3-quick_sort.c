#include "sort.h"

/**
 * swap_int - swaps two integers in an array and prints the array
 * @a: pointer to first integer
 * @b: pointer to second integer
 * @array: array to print after swap
 * @size: size of the array
 */
void swap_int(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: array size (for printing)
 * Return: final pivot index
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_int(&array[i], &array[j], array, size);
		}
	}
	swap_int(&array[i + 1], &array[high], array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive Quick Sort function
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: array size (for printing)
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pi = lomuto_partition(array, low, high, size);

		if (pi > 0)
			quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
