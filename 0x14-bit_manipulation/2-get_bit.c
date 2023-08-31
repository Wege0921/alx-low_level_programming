#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number from which to retrieve the bit.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the
 *	specified index, or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8) /* Check if index is out of range */
		return (-1);
	return ((n >> index) & 1);
	/* Right-shift n to the desired index and mask with 1 */
}
