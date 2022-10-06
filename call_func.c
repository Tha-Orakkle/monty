#include "monty.h"

/**
 * call_func - searches and finds the matching function
 * @search: the line gotten from the bytecode serving as the
 * instructions
 *
 * Return: pointer to function that matches. NULL if otherwise
 */

void (*call_func(char **search))(stack_t **, unsigned int)
{
	instruction_t instructions_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
/**
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
*/
		{NULL, NULL}
	};
	int op_codes = 17, i;

	for (i = 0; i < op_codes; i++)
	{
		if (strcmp(instructions_arr[i].opcode, search[0]) == 0)
			return (instructions_arr[i].f);
	}

	return (NULL);
}
