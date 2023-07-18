#include "main.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
void print_alphabet(void)
{
	int alpha;
	int tenx;

	for (tenx = 0; tenx < 10; tenx++)
	{
		for (alpha = 97; alpha < 123; alpha++)
		{
			_putchar(alpha);
		}
		_putchar('\n');
	}
}
