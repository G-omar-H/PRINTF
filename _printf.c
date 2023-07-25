#include "main.h"

/**
 * count_m - Counts the number of consecutive '%' characters at the
 * beginning of the format string and checks if the count is even.
 *
 * @format: The format string to be analyzed.
 *
 * Return:
 *   - If the number of consecutive '%' characters is even and followed
 * by a format specifier,
 *     the function returns half the count of '%' characters
 * (valid specifier count).
 *   - If the number of consecutive '%' characters is odd or followed by a
 * non-format specifier
 *     character, the function returns -1 to indicate an error or an invalid
 * specifier count.
 */
int count_m(const char *format)
{
	int	i;

	i = 0;
	while (format[i] == '%')
		i++;
	if (!format[i] || format[i] == ' ' || format[i] == '\t')
	{
		if (i % 2)
			return (-1);
	}
	return (0);
}

/**
 * check_format - Checks the input format specifier and calls
 * corresponding functions
 * @input: The va_list containing the arguments to be printed
 * @c: The format specifier character
 *
 * Return: The total count of characters printed for this format
 * specifier
 */
int	check_format(va_list input, const char c)
{
	int	len;

	len = 0;
	if (c == 'o')
		len += decimal_to_octal(va_arg(input, unsigned int));
	else if (c == 'R')
		len += rot13(va_arg(input, char *));
	else if (c == 'c')
		len += _putchar(va_arg(input, int));
	else if (c == 's')
		len += _putstr(va_arg(input, char *));
	else if (c == 'r')
		len += print_rev(va_arg(input, char *));
	else if (c == 'd' || c == 'i')
		len += putnbr(va_arg(input, int));
	else if (c == 'b')
		len += print_bits(va_arg(input, unsigned int));
	else if (c == 'p')
		len += phex(va_arg(input, unsigned long), LHEX);
	else if (c == 'x')
		len += xhex(va_arg(input, unsigned int), LHEX);
	else if (c == 'X')
		len += xhex(va_arg(input, unsigned int), UHEX);
	else if (c == 'u')
		len += putnbru(va_arg(input, unsigned int));
	else if (c == 'S')
		len += s_to_hex(va_arg(input, char *));
	else
	{
		if (c != '%')
		{
			_putchar('%');
			len++;
		}
		len += _putchar(c);
	}
	return (len);
}

/**
 * _printf - Custom implementation of printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The total count of characters printed
 */
int	_printf(const char *format, ...)
{
	va_list	input;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!format || (format[i] == '%' && (!format[i + 1] || format[i + 1] == 48)))
		return (-1);
	va_start(input, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				len += check_format(input, format[i]);
		}
		else
			len += _putchar(format[i]);
		if (!format[i])
			break;
		i++;
	}
	va_end(input);
	if (count_m(format))
		len = -1;
	return (len);
}
