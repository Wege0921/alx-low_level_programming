#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number.
 * @index: Index of the bit to clear.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		/* Check if index is out of bounds */
		return (-1);

	*n &= ~(1 << index);
	/* Clear the bit at the given index by using bitwise NOT */

	return (1);
}
