#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 *
 * @head: head of dobble linked list.
 * @n: value of integer in the new node.
 *.
 * Return: the address of the new element, or NULL if it failed.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node_ptr = NULL;

	if (head == NULL)
		return (NULL);

	node_ptr = malloc(sizeof(stack_t));
	if (node_ptr == NULL)
		return (NULL);

	node_ptr->next = *head;
	node_ptr->prev = NULL;
	node_ptr->n = n;
	if (*head != NULL)
		(*head)->prev = node_ptr;
	*head = node_ptr;

	return (*head);
}
