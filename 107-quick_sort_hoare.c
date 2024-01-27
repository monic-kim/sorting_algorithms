#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index
 * @right: The ending index
 *
 * Return: The final partition index.
 * Description: Uses the last element
 * of the partition as the driver.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int driver, up, down;

	driver = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < driver);
		do {
			down--;
		} while (array[down] > driver);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Implement the
 * quicksort algorithm through recursion.
 * @array: An array of integers
 * @size: The size of the array.
 * @left: The starting index
 * @right: The ending index
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, belong - 1);
		hoare_sort(array, size, belong, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers
 *                    using the quicksort algorithm.
 * @array: An array
 * @size: size of the array.
 * Description: Uses the Hoare partition scheme.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

