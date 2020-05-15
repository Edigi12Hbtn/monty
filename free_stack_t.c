#include "monty.h"

/**
 * free_stack_t - free a double linked list.
 *
 * @head: head of linked list.
 */

void free_stack_t(stack_t *head)
{
	stack_t *ptr_to_free = head;

	while (head != NULL)
	{
		ptr_to_free = head;
		head = head->next;
		free(ptr_to_free);
	}
}
