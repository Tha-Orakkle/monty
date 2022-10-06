#include "monty.h"

/**
 * print_dlistint - print all the elements
 * @h: head of list
 * Return: nodes
 */
size_t print_dlistint(const stack_t *h)
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


/**
 * add_dnodeint - add node at beginning
 * @head: points to pointer to head
 * @n: integer to be inserted
 * Return: address of the new element or NuLL if it failed
 */
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


/**
 * add_dnodeint_end - add node at end of dllist
 * @head: points to pointer to head
 * @n: integer to be inserted
 * Return: address of the new element or NuLL if it failed
 */
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


/**
 * free_dlistint - free list_t list
 * @head: pointers to head of dlistint_t
 */
void free_dlistint(stack_t *head)
{
	if (head != NULL)
		free_dlistint(head->next);
	free(head);
}


/**
 * insert_dnodeint_at_index - inserts a node at a given position
 *
 * @h: the pointer to the first node of the list
 * @idx: the index to get to
 * @n: the data to populate data field
 * Return: The address of the newly created node.
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	unsigned int count = 0;
	stack_t *new = malloc(sizeof(stack_t)), *cursor = *h, *rep;

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
