#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if the input is invalid.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	/* Validate input */
	if (b == NULL)
		return (0);

	while (*b)
	{
		/* Check for valid binary digits */
		if (*b != '0' && *b != '1')
			return (0);

		/* Left-shift result and add current digit */
		result <<= 1;
		result += (*b - '0');
		b++;
	}

	return (result);
}
