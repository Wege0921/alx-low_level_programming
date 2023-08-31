#include "main.h"


/**
 * flip_bits - Returns the number of bits to flip to get from n to m.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m; /* XOR of n and m */
	unsigned int count = 0;

	while (xor_result)
	{
		count += xor_result & 1;
		/* Check the least significant bit */
		xor_result >>= 1; /* Right shift to check the next bit */
	}

	return (count);
}
