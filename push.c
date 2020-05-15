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
	int n = 0, idx = 0;

	if (line_args[1] == NULL)
		line_args[1] = "imnotnum";

	while (line_args[1][idx] != '\0')
	{
		if (line_args[1][idx] < 48 || line_args[1][idx] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
			exit(EXIT_FAILURE);
		}
		idx++;
	}

	n = atoi(line_args[1]);

	add_dnodeint(stack, n);
}
