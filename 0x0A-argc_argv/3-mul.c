#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _mul - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0
 *	if no valid conversion could be performed
 */
int _mul(char *s)
{
	int i = 0, sign = 1, result = 0;

	/* Skip leading whitespace */
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;

	/* Handle sign */
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;

	/* Convert digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}
