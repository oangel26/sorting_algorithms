#include "sort.h"

size_t partition(int *array, size_t lo, size_t hi, size_t n);
void quicksort(int *array, size_t lo, size_t hi, size_t n);

/**
 * quick_sort - sorts array of int. in ascending order using Quick sort algo.
 * @array: pointer to array of integers
 * @size: size of array
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - sorts array of int. in ascending order using Quick sort algo.
 * @array: pointer to array of integers
 * @lo: low value of array
 * @hi: hi value of array
 * @n: size of array
 * Return: position of pivot partition
 */

void quicksort(int *array, size_t lo, size_t hi, size_t n)
{
	size_t i;

	if (array == NULL)
	{
		return;
	}

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
}

/**
 * partition - partition of array accordint to pivot
 * @array: pointer to array of integers
 * @lo: low value of array
 * @hi: hi value of array
 * @n: size of array
 * Return: position of pivot partition
 */

size_t partition(int *array, size_t lo, size_t hi, size_t n)
{
	int pivot = array[hi];
	size_t i = lo;
	int tmp;
	size_t j;

	if (array == NULL)
	{
		return (0);
	}

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (j != i)
			{
				/* Swap */
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, n);
			}
			i++;
		}
	}
	/* Swap i and hi*/
	if (i != hi)
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, n);
	}
	return (i);
}
