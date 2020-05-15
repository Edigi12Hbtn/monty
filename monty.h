#ifndef MONTY_PROJECT_H
#define MONTY_PROJECT_H



#include <stdio.h>
#include <stdlib.h>

/* Libraries for open */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* Libraries for open */

/* Library for read, write and close system calls*/
#include <unistd.h>
/* Library for read, write and close system calls*/




/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PROTOTYPES */
void error_exit(char *message1, char *message2);
void (*instruction_func(char *instruction))(stack_t **, unsigned int);
int _strcmp(char *str1, char *str2);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_stack_t(const stack_t *h);
int num_lines(char *buf);
void get_arguments(char **line_args, char *buf, int line_number);
void free_stack_t(stack_t *head);
void instr_error(int line_num, int fd, char *buf, stack_t *stack);
void free_all(int fd, char *buf, stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
int delete_stack_t_at_index(stack_t **head, unsigned int index);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_PROJECT_H */
