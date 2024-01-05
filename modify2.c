#include "monty.h"

/**
 * mod - modulo the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this add is called
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int stack_height = 0;
	GlobalMonty *Monty = getGlobalMonty();

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		stack_height++;
	}
	if (stack_height < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n %= temp->n;
	*stack = temp->next;
	free(temp);
}
