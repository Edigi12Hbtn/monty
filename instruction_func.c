#include "global.h"
#include "monty.h"

/**
 * instruction_func - function that read line of monty
 * file, finds the command and returns the pointer to
 * function that executes that command.
 *
 * @str: contents of monty file.
 * @line_number: number of line to analyse.
 *
 * Return: pointer to function of instruction or NULL if fails.
 */
void (*instruction_func(char *str, int line_number))(stack_t **, unsigned int)
{
	instruction_t name_func[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};
	char *instruction = NULL;
	int i = 0, match = 0;

	if (*str == '\0')
		return (NULL);

	while (line_number != 0)/*look for line*/
	{
		if (*str == '\n')
			line_number--;
		else if (*str == '\0')
			return (NULL);
		str++;
	}

	while (*str == ' ' || *str == '\n')/*look for first instruction letter*/
	{/*     what if there is an strange symbol before the instruction?*/
		if (*str == '\n')/*Error if any instruction is not find*/
			return (NULL);
		str++;
	}

	instruction = malloc(10 * sizeof(char));

	while (str[i] != '\n' && str[i] != ' ' && i < 9)/*get instruction*/
	{
		instruction[i] = str[i];
		i++;
	}
	instruction[i] = '\0';

	i = 0;
	while ((name_func[i]).opcode != NULL && match == 0)
	{
		match = _strcmp(instruction, (name_func[i]).opcode);
		if (match == 0)
			i++;
	}

	free(instruction);
	return ((name_func[i]).f);
}
