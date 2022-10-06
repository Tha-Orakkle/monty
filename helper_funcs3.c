#include "monty.h"

/**
 * stack_len - returns number of nodes in a linked list
 * @h: linked list
 *
 * Return: number of nodes
 */
size_t stack_len(const stack_t *h)
{
	size_t count = 0;

	if (!h)
		return (0);
	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * delete_dnodeint_at_index - deletes node of a doubly linked list at a
 * specific index
 * @head: doubly linked list
 * @index: position
 *
 * Return: 1 if succeeded and -1 if otherwise
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current = *head, *backward, *forward;
	unsigned int i;

	if (!head || index >= stack_len(current))
		return (-1);

	if (!index)
	{
		forward = current->next;
		if (forward)
			forward->prev = NULL;
		current->next = NULL;
		free(current);
		*head = forward;
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		backward = current;
		current = current->next;
		forward = current->next;
	}
	backward->next = forward;
	if (forward)
		forward->prev = backward;
	free(current);

	return (1);
}

/**
 * *get_dnodeint_at_index - gets node at specific index
 * of a doubly linked list
 * @head: linked list
 * @index: index of list
 *
 * Return: nth node, otherwise NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	stack_t *current = head;
	unsigned int i = 0, count = 0;

	if (!head)
		return (NULL);
	while (current)
	{
		count++;
		current = current->next;
	}
	if (index >= count)
		return (NULL);

	while (i < index)
	{
		head = head->next;
		i++;
	}

	return (head);
}
