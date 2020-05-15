#include "monty.h"

/**
 * pall - print all the values in the stack,
 * starting from the top of the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void pall(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	print_stack_t(*stack);
}
