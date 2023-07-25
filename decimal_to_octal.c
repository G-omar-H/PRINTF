#include "main.h"

/**
 * decimal_to_octal - Converts a decimal number to octal and prints
 * it to stdout
 * @num: The decimal number to convert
 *
 * Return: The number of characters printed
 */
int decimal_to_octal(unsigned int num)
{
	int octal[32];
	int index;
	int len;
	char n;

	index = 0;
	len = 0;
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num > 0)
	{
		octal[index++] = num % 8;
		num /= 8;
	}
	index -= 1;
	while (index >= 0)
	{
		n = octal[index--] + 48;
		len += write(1, &n, 1);
	}
	return (len);
}
