#include "main.h"

/**
 * phex - Prints an unsigned long integer in hexadecimal format
 * @n: The unsigned long integer to print
 * @arr: The array containing the hexadecimal characters (0-9, a-f)
 *
 * Return: The number of characters printed (excluding null byte)
 */
int	phex(unsigned long n, char *arr)
{
	if (!n)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	pxx(n, arr);
	return (count_numb_hex(n) + 2);
}

/**
 * pxx - Helper function to recursively print the hexadecimal
 * representation of a number
 * @n: The unsigned long integer to print in hexadecimal
 * @arr: The array containing the hexadecimal characters (0-9, a-f)
 */
void	pxx(unsigned long int n, char *arr)
{
	if (n > 0)
	{
		pxx(n / 16, arr);
		write(1, &arr[n % 16], 1);
	}
}

/**
 * xhex - Prints an unsigned integer in hexadecimal format
 * to standard output
 * @n: The unsigned integer to be printed in hexadecimal
 * @arr: The array containing hexadecimal digits
 *
 * Return: The number of characters printed.
 */
int	xhex(unsigned int n, char *arr)
{
	if (n == 0)
		write(1, "0", 1);
	else
		pxx(n, arr);
	return (count_numb_hex(n));
}
