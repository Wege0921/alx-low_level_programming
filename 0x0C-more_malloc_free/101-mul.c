#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int _putchar(char c);
/**
 * is_valid_number - checks if a string contains only digits
 * @str: string to be evaluated
 *
 * Return: 1 if str contains only digits, 0 otherwise
 */
int is_valid_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * get_string_length - returns the length of a string
 * @str: string to evaluate
 *
 * Return: the length of the string
 */
int get_string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * print_error_and_exit - prints an error message
 *	and exits the program with status 98
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *num1_str, *num2_str;
	int len1, len2, result_length, i, carry, digit1, digit2;
	int *result, is_non_zero = 0;

	if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
		print_error_and_exit();

	num1_str = argv[1];
	num2_str = argv[2];

	len1 = get_string_length(num1_str);
	len2 = get_string_length(num2_str);
	result_length = len1 + len2 + 1;

	result = malloc(sizeof(int) * result_length);
	if (!result)
		return (1);

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1_str[len1] - '0';
		carry = 0;

		for (len2 = get_string_length(num2_str) - 1; len2 >= 0; len2--)
		{
			digit2 = num2_str[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}

	for (i = 0; i < result_length - 1; i++)
	{
		if (result[i])
			is_non_zero = 1;
		if (is_non_zero)
			_putchar(result[i] + '0');
	}

	if (!is_non_zero)
		_putchar('0');

	_putchar('\n');
	free(result);
	return (0);
}
