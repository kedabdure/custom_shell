#include "main.h"
/**
 *
 *
 */

char *read_command(void) {
    char *line = NULL;
    size_t len = 0;
	while(1)
	{
		printf("#cisfun$ ");
		if(getline(&line, &len, stdin) == -1)
		{
			perror("getline failed");
			free(line);
			exit(EXIT_FAILURE);
		}
		line[strlen(line) - 1] = '\0';
		return line;
	}
}

