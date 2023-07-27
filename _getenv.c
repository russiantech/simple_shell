#include "shell1.h"

/**
 * _getenv - Get the value of an environment variable.
 * @var_name: The name of the environment variable
 *
 * Return: A pointer to the value of the environment variable if found,
 * or NULL if the variable does not exist or if 'var_name' is empty.
 */

char *_getenv(const char *var_name)
{
	int i;
	char *env_var, *var_ptr, *env_var_ptr;

	if (var_name == NULL || *var_name == '\0')
		return (NULL);
	i = 0;
	while (environ[i] != NULL)
	{
		env_var = environ[i];
		var_ptr = (char *)var_name;
		env_var_ptr = env_var;
		while (*var_ptr != '\0' && *env_var_ptr != '=' && *var_ptr == *env_var_ptr)
		{
			var_ptr++;
			env_var_ptr++;
		}
		if (*var_ptr == '\0' && *env_var_ptr == '=')
			return (env_var_ptr);
		i++;
	}
	return (NULL);
}
