#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


void display_prompt(void);
void read_command(char *command, size_t size);
void print_message(const char *message);
void execute_command(const char *command);

#endif

