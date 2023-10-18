#include "main.h"

/**
 *
 *
 *
 *
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	/* Loop through strings and compare characters */
	while (n > 0 && *str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
		return 0;
	
	return (*str1 - *str2);
}

