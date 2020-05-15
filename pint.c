#include "monty.h"

/**
 * pint - print the value in the top of the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
