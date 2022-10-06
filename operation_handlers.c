#include "monty.h"
#include "lists.h"

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = atoi(data.words[1]);
	(void) line_number;

	new = add_dnodeint(stack, num);

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}


/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack)
		print_dlistint(*stack);
}
