#include "global.h"
#include "monty.h"

/**
 * instruction_func - function that read line of monty
 * file, finds the command and returns the pointer to
 * function that executes that command.
 *
 * @instruction: instruction to execute.
 *
 * Return: pointer to function of instruction or NULL if fails.
 */
void (*instruction_func(char *instruction))(stack_t **, unsigned int)
{
	instruction_t name_func[] = {{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}};
	int i = 0, match = 0;

	while ((name_func[i]).opcode != NULL && match == 0)
	{
		match = _strcmp(instruction, (name_func[i]).opcode);
		if (match == 0)
			i++;
	}

	return ((name_func[i]).f);
}
