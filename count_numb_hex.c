#include "main.h"

/**
 * count_numb - Counts the number of digits in a long integer,
 * including the sign
 * @n: The long integer to count the digits of
 *
 * Return: The number of digits in the long integer
 */
int	count_numb(long int n)
{
	int	i;

	i = 1;
	while (1)
	{
		if (n < 0)
		{
			i++;
			n *= -1;
		}
		n = n / 10;
		if (n)
			i++;
		else
			break;
	}
	return (i);
}

/**
 * count_numb_hex - Counts the number of digits in an-
 * unsigned long integer (in hexadecimal representation)
 * @n: The unsigned long integer to count the digits of
 *
 * Return: The number of digits in the unsigned long integer in
 * hexadecimal representation
 */
int	count_numb_hex(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}
