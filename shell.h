/* shell.h */
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

/* Function prototypes */
void loop(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

#endif
