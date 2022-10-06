#include "lists.h"

void print_dlistint(const stack_t *h)
{
	while(h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
