#include "main.h"
/**
 * print_alphabet_x10 - check the code
 *
 * Return: Always 0.
 */
void print_alphabet_x10(void)
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
