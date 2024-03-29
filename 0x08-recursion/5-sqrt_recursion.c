#include "main.h"

/**
 * sqrt_recursive - Helper function to recursively
 *	calculate the square root.
 * @n: The number to calculate the square root of.
 * @i: The current guess for the square root.
 *
 * Return: The square root of n, or -1 if n
 *	does not have a natural square root.
 */
int sqrt_recursive(int n, int i);

/**
 * _sqrt_recursion - Calculate the square root
 *	of a number using recursion.
 * @n: The number to calculate the square root of.
 *
 * Return: The square root of n, or -1
 *	if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (sqrt_recursive(n, 1));
}

/**
 * sqrt_recursive - Helper function to recursively
 *	calculate the square root.
 * @n: The number to calculate the square root of.
 * @i: The current guess for the square root.
 *
 * Return: The square root of n, or -1
 *	if n does not have a natural square root.
 */
int sqrt_recursive(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (sqrt_recursive(n, i + 1));
}
