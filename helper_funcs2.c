#include "monty.h"

/**
 * popStack - deletes nodes from top for stack
 * @h: pointer to dllist
 * Return: returns 0 if llist is empty
 * or value of deleted node after node has
 * been deleted
 */

int popStack(stack_t *h)
{
	stack_t *temp = h, *current;
	int val;

	if (h == NULL)
	{
		return (0);
	}
	else
	{
		val = temp->n;
		if (h->next != NULL)
		{
			h->next->prev = NULL;
		}
		current = h->next;
		free(h);
		h = current;
	}
	return (val);
}
