#include "lists.h"
#include <stdlib.h>

void print_dlistint(const stack_t *h)
{
	while(h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newNode = NULL;

	if (head == NULL)
		return (NULL);

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return (NULL);

	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head)
		(*head)->prev = newNode;

	*head = newNode;

	return (newNode);
}

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tail = NULL;
	stack_t *current = NULL;

	if (head == NULL)
		return (NULL);

	tail = malloc(sizeof(stack_t));
	if (tail == NULL)
		return (NULL);

	current = *head;

	if (current)
	{
		while (current->next)
			current = current->next;

		current->next = tail;
		tail->prev = current;
	}
	else
		*head = tail;
	tail->n = n;

	return (tail);
}

