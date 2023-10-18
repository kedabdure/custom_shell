#include "main.h"

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @str: The string to be searched.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of the character c in the string str,
 * or NULL if the character is not found.
 */
char *_strchr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (char *)str;
		}
		str++;
	}
	return NULL;
}

