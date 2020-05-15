#include "monty.h"

/**
 * mul - add the two first elements of stack,
 * the result is added to the second node,
 * the first one is deleted.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number + 1);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n *= (*stack)->n;
	pop(stack, line_number);
}
