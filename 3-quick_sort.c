#include "sort.h"

/**
 *swap - function swaping the value of 2 integers
 *@a: integer
 *@b: integer
 *
 *Return: Nothing
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *algo_partition - partitions the array
 *@array: the integer array to sort
 *@size: the size of the array
 *@low: the low index of the sort range
 *@high: the high index of the sort range
 *
 *Return: index
 */

int algo_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int j, i;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);
		}
	}
	return (i);
}

/**
 *algo_quick_sort - sorting arrays partitions
 *@array: integer array to sort
 *@size: size of the array
 *@low: the lowest index
 *@high: the high index/pivot
 *
 *Return: Nothing
 */

void algo_quick_sort(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = algo_partition(array, size, low, high);
		algo_quick_sort(array, size, low,  p - 1);
		algo_quick_sort(array, size, p + 1, high);
	}
}

/**
 *quick_sort - function to call algo_quick_sort
 *@array: integer array to sort
 *@size: size of the array
 *
 *Return: Nothing
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	algo_quick_sort(array, size, 0, size - 1);
}
