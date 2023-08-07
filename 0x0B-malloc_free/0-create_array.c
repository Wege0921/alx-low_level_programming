#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates an array of chars and
 *	initializes it with a specific char.
 * @size: The size of the array.
 * @c: The char to initialize the array with.
 *
 * Return: A pointer to the array, or NULL if size is 0
 *	or if memory allocation fails.
 */
char *create_array(unsigned int size, char c)
{
	tabchar *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = (char *)malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
