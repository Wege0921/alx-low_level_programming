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
	int lowerC = 97;
	int upperC = 65;

	for (; lowerC < 123; lowerC++)
	{
		putchar(lowerC);
	}
	for (; upperC < 91; upperC++)
	{
		putchar(upperC);
	}
	putchar('\n');
	return (0);
}
