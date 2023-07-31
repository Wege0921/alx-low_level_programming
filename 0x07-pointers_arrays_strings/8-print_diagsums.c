#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - Prints the sum of the two
 *		diagonals of a square matrix.
 * @a: Pointer to the 2D square matrix.
 * @size: Size of the matrix.
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int sum1 = 0;
	int sum2 = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", sum1, sum2);
}
