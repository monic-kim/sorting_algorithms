#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - prints an array of integers
 * @array: array to print
 * @size: no of elements in array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
