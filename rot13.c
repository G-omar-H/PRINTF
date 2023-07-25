#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
size_t	_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * _strcpy - Copies the string pointed to by src to the buffer.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to be duplicated.
 *
 * Return: If successful, a pointer to the newly allocated duplicated string.
 *         If memory allocation fails or str is NULL, returns NULL.
 */
char	*_strdup(char *str)
{
	int		i;
	char	*s_malloc;

	if (!str)
		return (NULL);
	i = (int)_strlen(str);
	s_malloc = (char *)malloc(sizeof(char) * i + 1);
	if (!s_malloc)
		return (NULL);
	s_malloc = _strcpy(s_malloc, str);
	s_malloc[i] = 0;
	return (s_malloc);
}

/**
 * rot13 - Applies the ROT13 encryption to a string
 * @str: The input string to be encrypted using ROT13
 *
 * Return: The number of characters printed.
 */
int	rot13(char *str)
{
	char *s;
	int	i;
	int len;

	i = 0;
	len = 0;
	s = _strdup(str);
	while (s && s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm'))
			s[i] += 13;
		else if ((s[i] >= 'N' && s[i] <= 'Z') || (s[i] >= 'n' && s[i] <= 'z'))
			s[i] -= 13;
		len += write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (len);
}
