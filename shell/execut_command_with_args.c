#include "main.h"

/**
 *
 *
 *
 *
 */
void execute_command_with_args(char *command, char *argv[])
{
	pid_t child;
	char *args[MAX_ARGUMENTS];
	int i = 0;

	char *token = strtok(command, " ");
	while(token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	child = fork();
	if(child == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if(child == 0)
	{
		if(execve(args[0], args, NULL) == -1)
		{
			_printf("%s: No such file or directory\n", argv[0]);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
