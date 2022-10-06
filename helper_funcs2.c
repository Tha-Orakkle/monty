#include "lists.h"

int popStack(stack_t *h)
{
	stack_t *temp;
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
		temp = h->next;
		free(h);
		h = temp;
	}
	return (val);
}
