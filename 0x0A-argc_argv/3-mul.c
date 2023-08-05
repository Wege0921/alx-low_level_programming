#include <stdio.h>
#include "main.h"

/**
 * string_to_int - converts a string to an integer
 * @str: string to be converted
 *
 * Return: the integer converted from the string
 */
int string_to_int(char *str)
{
	int i, sign, num, len, found_digit;

	i = 0;
	sign = 0;
	num = 0;
	len = 0;
	found_digit = 0;

	while (str[len] != '\0')
		len++;

	while (i < len && !found_digit)
	{
		if (str[i] == '-')
			sign++;

		if (str[i] >= '0' && str[i] <= '9')
		{
			int digit = str[i] - '0';

			if (sign % 2)
				digit = -digit;
			num = num * 10 + digit;
			found_digit = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			found_digit = 0;
		}
		i++;
	}

	if (!found_digit)
		return (0);

	return (num);
}

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int result, operand1, operand2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	operand1 = string_to_int(argv[1]);
	operand2 = string_to_int(argv[2]);
	result = operand1 * operand2;

	printf("%d\n", result);

	return (0);
}
