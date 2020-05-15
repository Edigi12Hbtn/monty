#include "monty.h"

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number + 1);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n %= (*stack)->n;
	pop(stack, line_number);
}
