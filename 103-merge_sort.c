#include "sort.h"


/**
 * merge_sort - Implementation of merge sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int mid;
	int *temp_array = NULL;
	size_t i;

	if (size > 1)
	{
		mid = size / 2;
		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);
		temp_array = merge(array, array + mid, mid, size - mid);
		printf("[Done]: ");
		print_array(temp_array, size);
		if (temp_array == NULL)
			return;
		for (i = 0; i < size; i++)
			array[i] = temp_array[i];
		free(temp_array);
	}
}

/**
 * merge - merges two sorted arrays
 * @arrayA: first array
 * @arrayB: second array
 * @size_A: size of the first array
 * @size_B: size of the second array
 *
 * Return: the sorted array
 */
int *merge(int *arrayA, int *arrayB, int size_A, int size_B)
{
	int *temp_array = NULL;
	int i, j, k;

	temp_array = malloc(sizeof(*temp_array) * (size_A + size_B));
	if (temp_array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arrayA, size_A);
	printf("[right]: ");
	print_array(arrayB, size_B);
	while (i < size_A && j < size_B)
	{
		if (arrayA[i] < arrayB[j])
			temp_array[k++] = arrayA[i++];
		else
			temp_array[k++] = arrayB[j++];
	}
	for (; i < size_A; i++)
		temp_array[k++] = arrayA[i];
	for (; j < size_B; j++)
		temp_array[k++] = arrayB[j];
	return (temp_array);
}
