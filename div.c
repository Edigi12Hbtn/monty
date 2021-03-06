#include "monty.h"

/**
 * divi - divide the two first elements of stack,
 * the result is added to the second node,
 * the first one is deleted.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void divi(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number + 1);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n /= (*stack)->n;
	pop(stack, line_number);
}
