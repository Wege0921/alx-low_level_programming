#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int digit;

	for (digit = 48; digit <= 57; digit++)
	{
		putchar(digit);
		if (digit == 57)
		{
			continue;
		}
		else
		{
		putchar(',');
		putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
