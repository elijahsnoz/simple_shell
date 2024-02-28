#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void type_prompt() {
    printf("$ ");
    fflush(stdout); /* Make sure the prompt is displayed immediately */
}

void read_command(char *command) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1) {
        if (feof(stdin)) { /* End of file (Ctrl+D) */
            exit(EXIT_SUCCESS); /* Exit the shell */
        } else {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }

    /* Remove the newline character at the end of the input */
    if (line[read - 1] == '\n') {
        line[read - 1] = '\0';
    }

    /* Copy the input to command buffer */
    strncpy(command, line, BUFFER_SIZE);
    free(line);
}

int main() {
    char command[BUFFER_SIZE];
    pid_t pid;
    int status;

    while (1) {
        char *argv[2]; /* Adjusted to meet C90 standards */

        type_prompt(); /* Display the prompt */
        read_command(command); /* Read a command from the user */

        if (strlen(command) == 0) {
            continue; /* If the user just hits enter, show the prompt again */
        }

        if (access(command, F_OK) != 0) {
            /* The command is not found */
            printf("%s: Command not found\n", command);
            continue;
        }

        pid = fork(); /* Create a new process */
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { /* Child process */
            argv[0] = command;
            argv[1] = NULL;
            if (execve(command, argv, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else { /* Parent process */
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}
