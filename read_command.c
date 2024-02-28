#include "shell.h"

/**
 * read_command - funtion to read stdin
 *
 * Returns: buffer
 */

char *read_command(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	characters_read = getline(&buffer, &bufsize, stdin);
	if (characters_read == -1)
	{
		if (feof(stdin))
		{
			print_message("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	if (buffer[characters_read - 1] == '\n')
	{
		buffer[characters_read - 1] = '\0';
	}
	return (buffer);
}
