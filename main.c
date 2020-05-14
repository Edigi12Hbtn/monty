#include "monty.h"

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
	int fd = 0, line_number = 1;
	char *buf = NULL; /*Readed bytes from file*/
	ssize_t readed = 0; /*Number of readed bytes from file*/
	void (*f)(stack_t **, unsigned int) = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
		error_exit("USAGE: monty file", NULL);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't open file ", argv[1]);

	buf = malloc(1024 * sizeof(char));/*what if it's not enough*/
	if (buf == NULL)
	{
		close(fd);
		error_exit("Error: malloc failed", NULL);
	}

	readed = read(fd, buf, 1024);
	/*what if it fails?*/

	printf("Number %d, Readed bytes:\n%s", (int) readed, buf);
	printf("line_number: %d\n", line_number);

	if (readed != 0)/*line_number > real line_number*/
	{
		f = instruction_func(buf, line_number);
		if (f == NULL)
			printf("function end with NULL\n");
		else
			f(&stack, line_number);
	}
	close(fd);
	free(buf);

	return (0);
}
