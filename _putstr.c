#include "main.h"

/**
 * print_rev - Prints a string in reverse to standard output
 * @s: The string to be printed in reverse
 *
 * Return: The number of characters printed.
 */
int print_rev(char *s)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (s && s[i])
		i++;
	while (s && --i > -1)
		len += write(1, &s[i], 1);
	return (len);
}

/**
 * _putstr - Prints a string to standard output
 * @str: The string to be printed
 *
 * Return: The number of characters printed.
 */
int	_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		_putchar(str[i++]);
	return (i);
}
