#include "sort.h"


/**
 *selection_sort - a function to sort an array in ascending order
 *@array: pointer to the first item in array
 *@size: the size of the array
 *
 *Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t  min, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
