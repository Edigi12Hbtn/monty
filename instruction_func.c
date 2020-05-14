#include "monty.h"

/**
 * instruction_func - function that read line of monty
 * file, finds the command and returns the pointer to
 * function that executes that command.
 *
 * @buf: contents of monty file.
 * @line_number: number of line to analyse.
 *
 * Return: pointer to function of instruction or NULL if fails.
 */
void (*instruction_func(char *buf, int line_number))(stack_t **, unsigned int)
{
        instruction_t name_func[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};
        char *instruction = NULL;
        int i = 0, match = 0;

        if (*buf == '\0')
                return (NULL);

        while (line_number != 0)/*look for line*/
        {
                if (*buf == '\n')
                        line_number--;
                else if (*buf == '\0')
                        return (NULL);
                buf++;
        }

        while (*buf < 97 && *buf > 122)/*look for first instruction letter*/
        {/*     what if there is an strange symbol before the instruction?*/
                if (*buf == '\n')/*Error if any instruction is not find*/
                        return (NULL);
                buf++;
        }

        instruction = malloc(10 * sizeof(char));

        while (buf[i] != '\n' && buf[i] != ' ' && i < 9)/*get instruction*/
        {
                instruction[i] = buf[i];
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
