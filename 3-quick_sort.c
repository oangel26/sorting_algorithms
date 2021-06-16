#include "sort.h"

/**
 * quick_sort - sorts array of int. in ascending order using Quick sort algo.
 * @array: pointer to array of integers
 * @size: size of array
 * Return: Void
 */

size_t partition(int *array, size_t lo, size_t hi, size_t n);
void quicksort(int *array, size_t lo, size_t hi, size_t n);

void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
void quicksort(int *array, size_t lo, size_t hi, size_t n)
{
	size_t i;

	if (lo >= hi)
		return;

	i = partition(array, lo, hi, n);

	if (i == hi)
	{
		quicksort(array, lo, i - 1, n);
	}
	else if (i == 0)
        {
                quicksort(array, i + 1, hi, n);
        }
	else if (i > 0)
	{
		quicksort(array, lo, i - 1, n);
		quicksort(array, i + 1, hi, n);
	}
	else if (lo >= hi)
		return;
}

size_t partition(int *array, size_t lo, size_t hi, size_t n)
{
	int pivot = array[hi];
	size_t i = lo;
	int tmp;
	size_t j;
	
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			/* Swap */
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (j != i)
				print_array(array, n);
			i++;
		}
	}
	/* Swap i and hi*/
	tmp = array[i];
	array[i] = array[hi];
	array[hi] = tmp;
	print_array(array, n);
	return i;
}
