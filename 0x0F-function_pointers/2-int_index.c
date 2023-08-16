#include "function_pointers.h"
#include <stddef.h>
/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @cmp: Pointer to the function used to compare values.
 *
 * Return: Index of the first element for which cmp does not return 0, or -1 if no match or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array && cmp)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}
