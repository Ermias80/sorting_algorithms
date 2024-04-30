#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_index;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}

		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
