#include "shell1.h"

/**
 * _exe - Execute the given command.
 * @argv: The array of arguments containing the command and its arguments.
 *
 */

void _exe(char **argv)
{
	char *command = NULL, *or = NULL;

	if (argv)
	{
		command = argv[0];
		or = get_location(command);
		if (execve(or, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}

size_t _strlen(const char *str);

/**
 * main - The entry point
 * @ac: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: Always returns 0
 */
int main(int ac, char **argv)
{
	char *line = NULL, *copy = NULL, *token;
	size_t n = 0;
	ssize_t num_chars;
	const char *delim = " \n";
	int num_tokens = 0;
	int i;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		num_chars = getline(&line, &n, stdin);
		if (num_chars == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		copy = malloc(sizeof(char) * num_chars);
		if (copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		_strcpy(copy, line);
		token = strtok(copy, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(line, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		_exe(argv);
		for (i = 0; i < num_tokens - 1; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(copy);
	}
	free(line);
	return (0);
}
