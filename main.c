#include "monty.h"

data_t data = {NULL, NULL, NULL, NULL, 0};

/**
 * monty - opens and reads and gets a line from
 * a file containing monty bytecode and calls the right function
 * for the instruction found in the monty bytecode
 * @args: points to a struct of arguments passed to main
 */

void monty(args_t *args)
{
	size_t size = 0;
	int val;
	void (*code_func)(stack_t **, unsigned int);

	data.fptr = fopen(args->file_name, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->file_name);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->line_number++;
		val = getline(&(data.line), &size, data.fptr);

		if (val < 0)
			break;
		data.words = split_into_words(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_data();
			continue;
		}
		code_func = call_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_number, data.words[0]);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_number);
		free_data();
	}
	free_stack();
}




/**
 * main - interprets a monty bytecode
 * @argc: arguments counter
 * @argv: an array of arguments
 *
 * Return: EIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	args_t args;


	if (argc != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}

	args.line_number = 0;
	args.file_name = argv[1];
	monty(&args);

	return (EXIT_SUCCESS);
}

