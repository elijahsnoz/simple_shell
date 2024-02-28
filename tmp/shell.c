#include "shell.h"

/**
 *  main - entry point
 *
 *  Return: 0
 */

int main(void)
{
	char command[256];

	while (1)
	{
		display_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}
