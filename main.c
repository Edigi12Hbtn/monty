#include "monty.h"

char *buf; /*Readed bytes from file*/

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
	int fd = 0, line_number = 0;
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

	if (readed != 0)/*line_number > real line_number*/
	{
		while (1)
		{
			f = instruction_func(buf, line_number);
			if (f == NULL)
				break;
			else
				f(&stack, line_number);
			line_number++;
		}
	}
	close(fd);
	free(buf);

	return (0);
}
