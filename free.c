#include "monty.h"

/**
 * free_everything - frees arrays of string
 * @args: array of strings to free
 */
void free_everything(char **args)
{
	int i;

	if (!args)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}

/**
 * free_data - frees the data.line and data.words,
 * @check: flag to indicate what to free
 */

void free_data(int check)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;

		free_everything(data.words);
		data.words = NULL;
	}

	if (check)
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
}
