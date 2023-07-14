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
	int digits;
	int alpha;

	for (digits = 48; digits < 58; digits++)
	{
		putchar(digits);
	}
	for (alpha = 97; alpha < 103; alpha++)
	{
		putchar(alpha);
	}
	putchar('\n');
	return (0);
}
