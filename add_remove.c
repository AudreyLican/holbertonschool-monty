#include "monty.h"

/**
 * push - push an element to the stack
 * @stack: stack where to push the element
 * @line_number: line where this push is called
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i = 0, isint = 0, arg_number;
	stack_t *new_node, *temp_node;

	if (argument)
	{
		if (argument[0] == '-')
			i++;
		while (argument[i] != '\0')
		{
			if (argument[i] < 48 || argument[i] > 57)
			{
				isint = 1;
			}
			i++;
		}
	}
	if (!argument || isint == 1)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		free_all_close_file(lineContent, stack, openFile);
		exit(EXIT_FAILURE);
	}
	arg_number = atoi(argument);
	temp_node = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error Malloc");
		free_all_close_file(lineContent, stack, openFile);
		exit(EXIT_FAILURE);
	}
	if (temp_node)
		temp_node->prev = new_node;
	new_node->n = arg_number;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * pop - removes the top element of the stack
 * @stack: stack where to push the element
 * @line_number: line where this pop is called
 */

void pop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
}
