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
	int alpha;

	for (digit = 48; digit <= 57; digit++)
	{
		if (digit == 57)
		{
			putchar(digit);
		}
		else
		{
		putchar(digit);
		putchar(',');
		putchar(' ');
		}
	}
	return (0);
}


