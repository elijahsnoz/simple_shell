#include "shell.h"

/**
 * execute_command - function prototype
 *
 * @command: commands to be executed
 * Return: 0
 */

int execute_command(const char *command)
{
	pid_t pid;
	int status;
	
	pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	
	if (pid == 0)
	{
		char **argv = (char **)malloc(2 * sizeof(char *));
		
		if (argv == NULL)
		{
			perror("malloc");
			_exit(EXIT_FAILURE);
		}
		
		argv[0] = (char *)command;
		argv[1] = NULL;
		
		if (execve(command, argv, NULL) == -1)
		{
			perror("execve");
			free(argv);
			_exit(EXIT_FAILURE);
		}
		
		free(argv);
	} 
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}

