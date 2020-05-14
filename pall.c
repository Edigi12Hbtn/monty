#include "monty.h"

/**
 * pall - print all the values in the stack,
 * starting from the top of the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void pall(stack_t **stack, unsigned int line_number)
{
        printf("pall\n");
        if (stack == NULL)
                printf("stack is NULL\n");
        printf("ln: %u\n", line_number);
}
