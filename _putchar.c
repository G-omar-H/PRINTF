#include "main.h"

/**
 * _putchar - Writes a single character to standard output
 * @c: The character to be written
 *
 * Return: On success, 1 is returned.
 */
int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
