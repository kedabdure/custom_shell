#include "main.h"

/**
 * execute_command - Executes the given command.
 * @buf: The command to be executed.
 * @argv: The arguments array.
 */
void execute_command(char *buf, char *argv[]) {
	pid_t child;
	char **arg = NULL;

	arg = malloc(2 * sizeof(char *));
	if (arg == NULL) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	child = fork();
	if (child == -1) {
		perror("fork failed");
		free(arg);
		exit(EXIT_FAILURE);
	}

	if (child == 0) {
		arg[0] = buf;
		arg[1] = NULL;
		if (execve(buf, arg, NULL) == -1) {
			_printf("%s: No such file or directory\n", argv[0]);
			free(arg);
			exit(EXIT_FAILURE);
		}
	} else {
		wait(NULL);
		free(arg);
	}
}
