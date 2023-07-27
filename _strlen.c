#include "shell1.h"

/**
 * _strlen - calculates the length of a string
 * @str: the string
 *
 * Return: the length of the string
 */

size_t _strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}
