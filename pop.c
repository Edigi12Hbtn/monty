#include "monty.h"

/**
 * pop - print the value in the top of the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	delete_stack_t_at_index(stack, 0);
}
