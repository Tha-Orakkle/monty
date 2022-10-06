#include "lists.h"
#include <stdlib.h>

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode = NULL;

	if (head == NULL)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));
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

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tail = NULL;
	dlistint_t *current = NULL;

	if (head == NULL)
		return (NULL);

	tail = malloc(sizeof(dlistint_t));
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

void free_dlistint(dlistint_t *head)
{
	if (head != NULL)
		free_dlistint(head->next);
	free(head);
}

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int count = 0;
	dlistint_t *new = malloc(sizeof(dlistint_t)), *cursor = *h, *rep;

	if (!new || !h)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->prev = NULL;
		if (*h)
		{
			new->next = *h;
			(*h)->prev = new;
		}
		*h = new;
		return (new);
	}
	else
	{
		while (count < (idx - 1))
		{
			rep = cursor, cursor = cursor->next;
			if (cursor == NULL)
			{
				free(new);
				return (NULL);
			}
			count++;
		}
		if (cursor->next == NULL)
		{
			cursor->next = new, new->prev = cursor;
			new->next = NULL;
			return (new);
		}
		new->next = cursor->next, new->prev = cursor;
		rep = cursor->next;
		cursor->next = new, rep->prev = new;
		return (new);
	}
}
