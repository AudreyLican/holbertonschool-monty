#include "monty.h"

/**
 * pall - print all values on the stack,starting from the top
 * @stack: stack where to push the element
 * @line_number: line where this pall is called
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *cursor;

	cursor = *stack;
	if (!cursor)
		return;
	while (cursor)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}

/**
 * pint - prints the value at the top of the stack,follow by a new line
 * @stack: stack where to push the element
 * @line_number: line where this push is called
 */
void pint(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	GlobalMonty *Monty = getGlobalMonty();

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);

		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
