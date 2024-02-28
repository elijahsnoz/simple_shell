#include "shell.h"

/**
 * print_message - function mimic of  printf
 *
 * @massage: string to display
 * Return: nothing
 */

void print_message(const char *message) 
{
	write(STDOUT_FILENO, message, strlen(message));
}

