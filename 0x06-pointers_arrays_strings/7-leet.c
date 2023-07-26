#include "main.h"

/**
 * leet - Encodes a string using the 'leet' or '1337' language.
 * @n: The input string to be encoded.
 *
 * Return: A pointer to the modified string.
 */
char *leet(char *n)
{
	int x, y;
	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	for (x = 0; n[x] != '\0'; x++)
	{
		for (y = 0; y < 10; y++)
		{
			if (n[x] == s1[y])
			{
				n[x] = s2[y];
			}
		}
	}
	return (n);
}
