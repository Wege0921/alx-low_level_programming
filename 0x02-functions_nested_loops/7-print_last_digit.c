#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @num: The input number
 *
 * Return: The last digit of the number.
 */
int print_last_digit(int num)
{
	int lastD;

	lastD = num % 10;
	if (lastD < 0)
	{
		_putchar(-lastD + '0');
		return (-lastD);
	}
	else
	{
		_putchar(lastD + '0');
		return (lastD);
	}
}

