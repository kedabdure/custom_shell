#include "main.h"

/**
 * custom_getenv - Custom implementation of getenv function.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value associated with the specified name,
 * or NULL if the name is not found in the environment.
 */
char *_getenv(const char *name)
{
	int i;
	extern char **environ;
	size_t name_len = _strlen(name);

	for (i = 0; environ[i] != NULL; ++i)
	{
		if(_strncmp(name, environ[i], name_len) == 0 && environ[i][name_len] == '=')
		{
			return environ[i] + name_len + 1;
		}
	}

	return NULL;
}

