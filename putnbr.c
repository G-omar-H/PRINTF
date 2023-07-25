#include "main.h"

/**
 * putnbru - Prints an unsigned integer to standard output
 * @n: The unsigned integer to be printed
 *
 * Return: The number of characters printed.
 */
int	putnbru(unsigned int n)
{
	int	len;

	len = 0;
	len = count_numb(n);
	if (n > 9)
	{
		putnbru(n / 10);
		putnbru(n % 10);
	}
	else
		_putchar(n + 48);
	return (len);
}

/**
 * putnbr - Prints an integer to standard output
 * @n: The integer to be printed
 *
 * Return: The number of characters printed.
 */
int	putnbr(int n)
{
	int	len;

	len = count_numb(n);
	if (n == -2147483648)
	{
		_putchar(45);
		_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		_putchar(45);
		putnbr(n * -1);
	}
	if (n >= 0 && n <= 9)
		_putchar(n + 48);
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	return (len);
}
