#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


void display_prompt(void);
char *read_command(void);
void print_message(const char *message);
int execute_command(const char *command);

#endif

