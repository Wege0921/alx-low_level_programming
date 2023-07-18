#include "main.h"
/**
 * print_sign -  checks if the input is greater, less or equal to zero.
 * @n: The input number
 * Return: 1 if n is greater, -1 if n is less than zero and 0 if n is zero.
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
_putchar('\n');
}
