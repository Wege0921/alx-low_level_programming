#include <stdio.h>

/**
 * print_name - Prints a name using a specified printing function.
 * @name: Pointer to the name to be printed.
 * @f: Pointer to the printing function.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
