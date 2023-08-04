#include "main.h"

/**
 * _abs -  checks if the number is negative or positive.
 * @i: input number
 *
 * Return: absolute value of a number.
 */
int _abs(int i)
{
	if (i >= 0)
	{
		return (i);
	}
	else
	{
		return (i * -1);
	}
}
