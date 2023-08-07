#include <stdlib.h>

/**
 * create_array - Creates an array of
 *	chars and initializes it with a specific char.
 * @size: The size of the array.
 * @c: The char to initialize the array with.
 *
 * Return: A pointer to the array, or NULL
 *	if size is 0 or if memory allocation fails.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int index;

	array = malloc(sizeof(char) * size);
	if (size == 0 || array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		array[index] = c;

	return (array);
}
