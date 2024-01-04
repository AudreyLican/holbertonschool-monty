#include "monty.h"

/**
 * nop - doesn't do anything
 * @stack: stack where to push the element
 * @line_number: line where this push is called
 */
void nop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
}

/**
 * freeStack - free the stack and it's content
 * @stack: head of the stack
 */
void freeStack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

/**
 * free_all_close_file - free everything and close the file
 * @content: line buffer to free
 * @token: token to free
 * @argument: arguments to free
 * @stack: stack to free
 * @file: file to close
 */

void free_all_close_file(char *content, stack_t **stack, FILE *file)
{
	if (content)
		free(content);
	if (*stack)
		freeStack(stack);
	if (file)
		fclose(file);
}