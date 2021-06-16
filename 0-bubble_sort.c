#include "sort.h"

/**
 * bubble_sort - Sorts an array of intergers in ascending order by Bubble sort
 * @array: pointer to array of intergers
 * @size: size of array
 * Return: VOID
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int tmp;
	int flag;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
