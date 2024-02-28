/* main.c */
#include "shell.h"

void loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(void) {
    /* Run command loop */
    loop();
    return EXIT_SUCCESS;
}

