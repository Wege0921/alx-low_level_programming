#include "shell.h"


/**
 * bfree - Frees a pointer and sets its address to NULL.
 * @ptr: Address of the pointer to free.
 *
 * This function frees the memory occupied by the pointer and then sets
 * the pointer's address to NULL, ensuring it is no longer usable.
 *
 * Return: 1 if memory was freed, otherwise 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);/* Return */
}

