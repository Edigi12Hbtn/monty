#include "monty.h"

/**
 * delete_stack_t_at_index - deletes the node.
 * at index index of a stack_t linked list.
 *
 * @head: head of linked list.
 * @index: index where the new node is going to be added.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_stack_t_at_index(stack_t **head, unsigned int index)
{
	stack_t *node_to_del = NULL;

	if (head == NULL || *head == NULL)
		return (-1);

	node_to_del = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(node_to_del);
		if ((*head) != NULL)
			(*head)->prev = NULL;
		return (1);
	}

	while (node_to_del != NULL && index > 0)
	{
		node_to_del = node_to_del->next;
		index--;
	}

	if (node_to_del == NULL)
		return (-1);

	(node_to_del->prev)->next = node_to_del->next;
	if (node_to_del->next != NULL)
		(node_to_del->next)->prev = node_to_del->prev;

	free(node_to_del);

	return (1);
}
