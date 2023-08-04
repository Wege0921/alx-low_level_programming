#include "main.h"

/**
 * _memcpy - Copies memory area.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to copy.
 *
 *
 * Return: A pointer to the destination memory area.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int u;

	for (u = 0; u < n; u++)
		dest[u] = src[u];

	return (dest);
}
