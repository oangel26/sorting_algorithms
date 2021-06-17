#include "sort.h"

/**
 * selection_sort - sorts an array of int. in ascending order (Selection sort)
 * @array: pointer to array of integers
 * @size: size of the array
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index, count;
	int min;
	int flag;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		index = i;
		count = 0;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			count++;
			if (array[j] < min)
			{
				min = array[j];
				index = i + count;
				flag = 1;
			}
		}
		if (flag == 0)
			continue;

		array[index] = array[i];
		array[i] = min;
		print_array(array, size);
	}
}
