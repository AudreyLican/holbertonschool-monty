#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this swap is called
 */
void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);

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
void add(stack_t **stack, unsigned int line_number)
{
	stack_t	*top;
	int	a = 0, b = 0;
	GlobalMonty *Monty = getGlobalMonty();

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	a = top->n;
	b = top->next->n;
	top->next->n = a + b;
	*stack = top->next;

	free(top);
}

/**
 * sub - substract the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this add is called
 */
void sub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n -= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * _div - divide the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this add is called
 */
void _div(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	*stack = (*stack)->next;
	(*stack)->n = ((*stack)->n) / (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * mul - multiply the top two elements of the stack
 * @stack: stack where to push the element
 * @line_number: line where this add is called
 */
void mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all_close_file(Monty->lineContent, stack, Monty->openFile);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n *= temp->n;
	*stack = temp->next;
	free(temp);
}
