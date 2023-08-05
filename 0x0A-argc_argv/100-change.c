#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * calculate_coins - calculates the minimum
 *	number of coins to make change
 * for an amount of money
 * @amount: the amount of money
 *
 * Return: the minimum number of coins
 */
int calculate_coins(int amount)
{
	int num_coins = 0;
	int coin_values[] = {25, 10, 5, 2, 1};
	int i;

	if (amount < 0)
		return (0);

	for (i = 0; i < 5 && amount >= 0; i++)
	{
		while (amount >= coin_values[i])
		{
			num_coins++;
			amount -= coin_values[i];
		}
	}

	return (num_coins);
}

/**
 * main - prints the minimum number of coins
 *	to make change for an amount of money
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int money_amount, total_coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	money_amount = atoi(argv[1]);
	total_coins = calculate_coins(money_amount);

	printf("%d\n", total_coins);
	return (0);
}
