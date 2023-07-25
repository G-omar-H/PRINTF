#include "main.h"

/**
 * print_bits - Prints the binary representation of an unsigned integer
 * to standard output
 * @numb: The unsigned integer to be printed in binary
 *
 * Return: The number of characters printed.
 */
int print_bits(unsigned int numb)
{
	unsigned char   bit;
	int             i;
	int             len;

	i = 32;
	len = 0;
	while (i--)
	{
		bit = (numb >> i & 1) + 48;
		if (bit > '0' && bit <= '9')
			len += _putchar(bit);
		else if (len)
			len += _putchar(bit);
	}
	if (!numb)
		len += _putchar('0');
	return (len);
}
