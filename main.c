#include "monty.h"
#include "global.h"


/**
 * main - Interpreter for Monty ByteCodes files.
 *
 * @argc: Number of arguments passed to the program.
 * @argv: Arguments passed to the program.
 *
 * Return: 0 in success.
 */

int main(int argc, char *argv[])
{
	int fd = 0, line_number = 0, tot_lines = 0;
	void (*f)(stack_t **, unsigned int) = NULL;
	stack_t *stack = NULL;
	char *buf = NULL; /*Readed bytes from file*/

	if (argc != 2)
		error_exit("USAGE: monty file", NULL);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't open file ", argv[1]);

	buf = malloc(1024 * sizeof(char));/*what if it's not enough*/
	if (buf == NULL)
		close(fd), error_exit("Error: malloc failed", NULL);
	line_args = malloc(2 * sizeof(char *));
	if (line_args == NULL)
	{
		free(buf), close(fd);
		error_exit("Error: malloc failed", NULL);
	}
	read(fd, buf, 1024);/*what if it fails?*/
	tot_lines = num_lines(buf);

	while (line_number < tot_lines)
	{
		get_arguments(line_args, buf, line_number);
		if (line_args[0] == NULL)
		{
			line_number++;
			continue;
		}
		f = instruction_func(line_args[0]);
		if (f == NULL)
			instr_error(line_number, fd, buf, stack);
		f(&stack, line_number++);
		free(line_args[0]), free(line_args[1]);
	}
	free_all(fd, buf, stack);
	return (0);
}

char **line_args = NULL;

/**
 * get_arguments - get arguments of line.
 *
 * @line_args: array with split arguments from line.
 * @buf: readed bytes of file.
 * @line_number: number of line to analyse.
 */

void get_arguments(char **line_args, char *buf, int line_number)
{
	int len_arg = 0, idx = 0, arg = 0;

	line_args[0] = NULL;
	line_args[1] = NULL;

	while (line_number != 0)
	{
		if (*buf == '\n')
			line_number--;
		buf++;
	}

	for (arg = 0; arg < 2; arg++)
	{
		idx = 0, len_arg = 0;

		while (*buf == ' ')
			buf++;

		if (*buf == '\n')
			return;

		while (buf[len_arg] != ' ' && buf[len_arg] != '\n')
			len_arg++;

		line_args[arg] = malloc((len_arg + 1) * sizeof(char));
		/*if malloc fails*/
		while (idx < len_arg)
		{
			line_args[arg][idx] = buf[idx];
			idx++;
		}
		line_args[arg][idx] = '\0';

		buf += len_arg;
	}
}

/**
 * free_all - free variables.
 *
 * @fd: file descriptor.
 * @buf: buffer.
 * @stack: double linked list.
 */

void free_all(int fd, char *buf, stack_t *stack)
{
	close(fd);
	free(buf);
	free(line_args);
	free_stack_t(stack);
}
