#include "monty.h"

/**
 * num_lines - return the number of lines in buffer.
 *
 * @buf: buffer with data.
 *
 * Return: number of lines in buffer.
 */

int num_lines(char *buf)
{
	int tot_lines = 0;

	while (*buf != '\0')
	{
		if (*buf == '\n')
			tot_lines++;
		buf++;
	}

	return (tot_lines);
}
