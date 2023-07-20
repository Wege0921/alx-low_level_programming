#include <stdio.h>
#include <math.h>

/**
 * is_prime - Checks if a number is prime
 *
 * @num: The number to check for primality
 * Return: 1 if prime, 0 otherwise
 */
int is_prime(unsigned long num)
{
	if (num < 2)
		return (0);

	if (num == 2 || num == 3)
		return (1);

	if (num % 2 == 0)
		return (0);
	unsigned long i;

	for (i = 3; i <= sqrt(num); i += 2)
	{
		if (num % i == 0)
			return (0);
	}

	return (1);
}

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 *
 * @num: The number to find the largest prime factor for
 * Return: The largest prime factor
 */
unsigned long largest_prime_factor(unsigned long num)
{
	unsigned long largest_prime = 0;

	while (num % 2 == 0)
	{
		largest_prime = 2;
		num /= 2;
	}
	unsigned long i;

	for (i = 3; i <= sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			largest_prime = i;
			num /= i;
		}
	}

	if (num > 2)
		largest_prime = num;

	return (largest_prime);
}
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	unsigned long number = 612852475143;
	unsigned long largest_prime = largest_prime_factor(number);

	printf("%lu\n", largest_prime);
	return (0);
}
