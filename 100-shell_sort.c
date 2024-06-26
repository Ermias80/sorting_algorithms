#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (gap <= (int)(size / 3))
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= (size_t)gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
