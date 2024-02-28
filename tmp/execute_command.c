#include "shell.h"

/**
 * execute_command - function prototype
 *
 * @command: commands to be executed
 * Return: 0
 */

void execute_command(const char *command) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process

        // Construct the full path to the command
        char command_path[256];
        snprintf(command_path, sizeof(command_path), "/bin/%s", command);

        // Allocate a mutable copy of command for args
        char *mutable_command = strdup(command);
        if (!mutable_command) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        char *args[] = {mutable_command, NULL};
        execve(command_path, args, NULL);

        // If execve returns, it must have failed
        perror("execve");
        free(mutable_command);  // Clean up allocated memory
        exit(EXIT_FAILURE);
    } else {
        // Parent process waits for child to complete
        wait(NULL);
    }
}

