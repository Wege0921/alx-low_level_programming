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
	int nums;

	for (nums = 0; nums < 10; nums++)
	{
		putchar(nums + 48);
	}
	putchar('\n');
	return (0);
}
