#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, rounds;
	int tmp, not_sorted;

	if (!array)
		return;

	rounds = 0;

	do {
		not_sorted = 0;
		for (i = 0; i < size - 1 - rounds; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				not_sorted = 1;
			}
			else if (i == (size - 1 - rounds - 1))
				rounds++;
		}
		rounds++;
	} while (not_sorted);
}
