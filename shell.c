#include "shell.h"

/**
 *  main - entry point
 *
 *  Return: 0
 */

int main(void)
{
	char *command;
	while (1)
	{
		command = read_command();
		if (command == NULL)
		{
			break;
		}
		execute_command(command);
		free(command);
	}
	return (0);
}
