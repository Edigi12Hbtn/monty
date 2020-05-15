#include "monty.h"

/**
 * swap - swap the two first elements of stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int n_temp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number + 1);
		exit(EXIT_FAILURE);
	}

	n_temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = n_temp;
}
