#include "monty.h"

/**
 * free_data - frees the data.line and data.words,
 */

void free_data(void)
{
	int i;

	if (data.line || data.words)
	{
		free(data.line);
		data.line = NULL;

		while (data.words[i])
		{
			free(data.words[i]);
			i++;
		}
		data.words = NULL;
	}
}
/**
 * free_stack - frees the entire stack
 */

void free_stack(void)
{
	if (data.stack)
	{
		free_dlistint(data.stack);
		data.stack = NULL;
	}
	if (data.fptr)
	{
		fclose(data.fptr);
		data.fptr = NULL;
	}
}
