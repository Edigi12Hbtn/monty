#include "global.h"
#include "monty.h"

/**
 * _strcmp - compare two strings.
 *
 * @str1: string 1.
 * @str2: string 2.
 *
 * Return: 1 if match else 0.
 * 0 if anyone is NULL.
 */
int _strcmp(char *str1, char *str2)
{
	int match = 1, i = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);

	while (str1[i] != '\0' && str2[i] != '\0' && match == 1)
	{
		if (str1[i] != str2[i])
			match = 0;
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
		return (match);
	else
		return (0);
}
