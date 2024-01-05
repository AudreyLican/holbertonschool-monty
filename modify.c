#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this swap is called
 */
void swap(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;
	GlobalMonty *Monty = getGlobalMonty();
	int stack_height = 0, temp_num;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		stack_height++;
	}
	if (stack_height < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);

		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp_num = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_num;
}
/**
 * add - adds the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this add is called
 */
void add(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{

}
