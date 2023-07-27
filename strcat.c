#include "shell1.h"

/**
 * *_strcat - concatenates strings
 * @source: source
 * @destination: destination
 *
 * Return: resulting string destination
 */

char *_strcat(char *destination, const char *source)
{
	char *dest_ptr = destination;

	while (*dest_ptr != '\0')
		dest_ptr++;
	while (*source != '\0')
	{
		*dest_ptr = *source;
		dest_ptr++;
		source++;
	}
	*dest_ptr = '\0';
	return (destination);
}
