#include "main.h"

/**
 * reverse_array - Reverse array of integers
 * @a: Array to be reversed
 * @n: Number of elements in the array
 *
 * Description: This function reverses the order of elements.
 * Return: Nothing (void)
 */
void reverse_array(int *a, int n)
{
	int x;
	int y;

	for (x = 0; x < n--; x++)
	{
		y = a[x];
		a[x] = a[n];
		a[n] = y;
	}
}
