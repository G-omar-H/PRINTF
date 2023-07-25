#include "main.h"

/**
 * s_to_hex - prints a string may contain unprintible characters
 * @str: string to print
 * Return: lenght of the string
*/
int s_to_hex(char *str)
{
	int i, len = 0;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			len += char_to_hex(str[i]);
		else
		{
			write(1, &str[i], 1);
			len += 1;
		}
	}
	return (len);
}

/**
 * char_to_hex -  convert a character to ascii hex
 * @c: character to convert
 * Return: void.
 */
int  char_to_hex(char c)
{
	char hex[] = UHEX;
	char out[3];
	int len = 0;

	out[0] = hex[c >> 4];
	out[1] = hex[c & 15];
	out[2] = 0;
	write(1, "\\", 1);
	write(1, "x", 1);
	len += _putstr(out);
	return (len + 2);
}
