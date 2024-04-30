#include "sort.h"

/**
 * bubble_sort - Sorts array of int in ascending order using z Bubble algorithm
 * @array: The array of integers to be sorted
 * @size: Number of elements in the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
