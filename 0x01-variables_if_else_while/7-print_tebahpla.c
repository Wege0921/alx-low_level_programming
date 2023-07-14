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
	int alpha = 122;

	for (; alpha > 96; alpha--)
	{
		putchar(alpha);
	}
	putchar('\n');
	return (0);
}
