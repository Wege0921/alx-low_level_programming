#include <stdio.h>
#include "main.h"
/**
 * main - FizzBuzz program
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	int print_space = 0;

	for (i = 1; i <= 100; i++)
	{
		if (print_space)
			printf("\t");
		else
			print_space = 1;

		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%d", i);
	}

	printf("\n");
	return (0);
}
