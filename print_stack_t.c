#include "global.h"
#include "monty.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 *
 * @h: head of linked list.
 *
 * Return: Number of nodes.
 */

size_t print_stack_t(const stack_t *h)
{
	size_t Nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		Nodes += 1;
		h = h->next;
	}

	return (Nodes);
}
