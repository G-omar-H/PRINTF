#include "main.h"

/**
 * ft_putnbru - Prints an unsigned integer to standard output
 * @n: The unsigned integer to be printed
 *
 * Return: The number of characters printed.
 */
int	ft_putnbru(unsigned int n)
{
	int	len;

	len = 0;
	len = ft_count_numb(n);
	if (n > 9)
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (len);
}

/**
 * ft_putnbr - Prints an integer to standard output
 * @n: The integer to be printed
 *
 * Return: The number of characters printed.
 */
int	ft_putnbr(int n)
{
	int	len;

	len = ft_count_numb(n);
	if (n == -2147483648)
	{
		ft_putchar(45);
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar(45);
		ft_putnbr(n * -1);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
