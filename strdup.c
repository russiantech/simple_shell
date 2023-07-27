#include "shell1.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string
 *
 * Return: On success returns a pointer, on failure returns NULL
 */

char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		char *p = dup;

		while (*str != '\0')
		{
			*p = *str;
			p++;
			str++;
		}
		*p = '\0';
	}
	return (dup);
}
