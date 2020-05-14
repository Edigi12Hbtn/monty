#include "monty.h"
#include "global.h"

/**
 * push - pushes an element to the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void push(stack_t **stack, unsigned int line_number)
{
	int bytes_in_line = 0, n = 0;
	extern char *buf;
	char *line = buf;

	while (line_number != 0)
	{
		if (*line == '\n')
			line_number--;
		else if (*line == '\0')
			return;
		line++;
	}

	while (*line < 48 || *line > 57)
		line++;

	while (line[bytes_in_line] != '\n')
		bytes_in_line++;

	line[bytes_in_line] = '\0';

	n = atoi(line);
	/* printf("line: %s, n: %d\n", line, n); */

	add_dnodeint(stack, n);

	line[bytes_in_line] = '\n';
}
