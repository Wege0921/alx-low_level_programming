#include "shell.h"

/**
 * _erratoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted number if successful, -1 on error.
 */


int _erratoi(char *s)
{
	int k = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;  /* Skip leading '+' sign if present */
	for (k = 0;  s[k] != '\0'; k++)
	{
		if (s[k] >= '0' && s[k] <= '9')
		{
			res *= 10;
			res += (s[k] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);/*Return the converted number*/
}

/**
 * print_error - Prints an error message.
 * @info: The parameter and return info struct.
 * @estr: String containing specified error type.
 *
 * Return: None.
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Prints a decimal (integer) number (base 10).
 * @input: The input number.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters printed.
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int k, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_abs_ / k)
		{
			__putchar('0' + current / k);
			count++;
		}
		current %= k;
	}
	__putchar('0' + current);
	count++;

	return (count);/*Return the result */
}

/**
 * convert_number - Converts a number to a string representation.
 * @number: The number to convert.
 * @base: The base for the conversion (e.g., 10 for decimal).
 * @flags: Flags specifying the conversion behavior.
 *
 * Return: The string representation of the number.
 */


char *convert_number(long int number, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = number;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 *
 * Return: Always 0.
 */

void remove_comments(char *buf)
{
	int k;

	for (k = 0; buf[k] != '\0'; k++)
		if (buf[k] == '#' && (!k || buf[k - 1] == ' '))
		{
			buf[k] = '\0';
			break;
		}
}

