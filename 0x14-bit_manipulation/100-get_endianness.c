
#include "main.h"


/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	/* If the least significant byte is 1, it's little endian. */
	if (*c)
		return (1); /* Little Endian */
	else
		return (0); /* Big Endian */
}

