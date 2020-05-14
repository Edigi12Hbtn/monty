#include "monty.h"

/**
 * push - pushes an element to the stack.
 *
 * @stack: double pointer to head of stack.
 * @line_number: number of line where the instruction is.
 */

void push(stack_t **stack, unsigned int line_number)
{
/*        int bytes_in_line = 0;*/
/**
*        while (line_number != 0)
*        {
*                if (*buf == '\n')
*                        line_number--;
*                else if (*buf == '\0')
*                        return (NULL);
*                buf++;
*        }
*/

        printf("push\n");
        if (stack == NULL)
                printf("stack is NULL\n");
        printf("ln: %u\n", line_number);
}
