#include "main.h"

/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 * Return: Always returns 0 for success.
 */
int main(int argc, char *argv[])
{
	char *command, *value;
	(void)(argc);

	while (1)
	{
		command = read_command();
		if(strcmp(command, "") == 0)
			continue;
		if (strcmp(command, "exit") == 0)
                        exit(0);
		if (command[0] == '/')
		{
			if (strchr(command, ' '))
				execute_command_with_args(command, argv);
			else
				execute_command(command, argv);
		}
		else
		{
			value = find_path(command);
			if (value)
			{
				if (strchr(command, ' ') == 0)
					execute_command_with_args(value, argv);
				else
					execute_command(value, argv);
				free(value);
			}
			else
			{
				printf("%s: 1: %s: not found\n", argv[0], command);
			}
		}
	}
	return (0);
}
