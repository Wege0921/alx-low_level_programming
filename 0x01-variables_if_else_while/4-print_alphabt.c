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
	int upperC = 97;

	for (; upperC < 123; upperC++)
	{
		if (upperC == 101 || upperC == 113)
		{
			upperC++;
			continue;
		}
		putchar(upperC);
	}
	putchar('\n');
	return (0);
}
