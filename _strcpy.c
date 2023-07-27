#include "shell1.h"

/**
 * _strcpy - Copy a string
 * @src: source
 * @dest: destination
 *
 * Return: resulting string dest
 */

char *_strcpy(char *dest, const char *src)
{
	char *d = dest;
	const char *s = src;

	while (*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (dest);
}
