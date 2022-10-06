#ifndef MONTY_H_
#define MONTY_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @words: parsed line
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;


/**
 * struct args_s - structure for arguments from main
 * @av: argv[1] which is the file from the command line
 * @ac: number of arguments from main
 * @line_number: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 */
typedef struct args_s
{
	char *file_name;
	unsigned int line_number;
} args_t;

extern data_t data;

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%d: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define DATA_INIT {NULL, NULL, NULL, NULL, 0}
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"


/* main.c */
void monty(args_t *args);

/* split.c */
int count_word(char *s);
char **split_into_words(char *str);

/* call_func.c */
void (*call_func(char **search))(stack_t **, unsigned int);

/* operation_handlers.c */
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);

/* operation_handlers.c */
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);


/* helper_funcs.c */
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);


/*helper_funcs3.c*/
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t stack_len(const stack_t *h);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);



/* free.c */
void free_data(void);
void free_stack(void);
#endif
