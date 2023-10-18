#include "main.h"

/**
 * custom_strdup - Duplicates a string.
 * @source: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *_strdup(const char *source)
{
	size_t length;
	char *duplicate;

        if (source == NULL)
                return NULL;

        length = _strlen(source) + 1;

        duplicate = malloc(length * sizeof(char));

        if (duplicate != NULL)
        {
                _strcpy(duplicate, source);
        }

        return duplicate;
}

