#include "monty.h"
#include "global.h"

/**
 * instr_error - print error to stderr and exit.
 *
 * @line_num: line where the error is.
 * @fd: file descriptor of file to close.
 * @buf: buffer to free.
 * @stack: linked list to free.
 */

void instr_error(int line_num, int fd, char *buf, stack_t *stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num + 1, line_args[0]);
	free(line_args[0]);
	free(line_args[1]);
	free(line_args);
	close(fd);
	free(buf);
	free_stack_t(stack);
	exit(EXIT_FAILURE);
}
