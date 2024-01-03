#include "header.h"

void push(stack_t **stack, unsigned int line_number)
{
	int i = 0, isint = 0, arg_number;
	stack_t *new_node, *temp_node;

	if (argument) /*si y'a un argument, verifie que c'est bien des chiffres*/
	{
		while (argument[i] != '\0')
		{
			if (argument[i] < 48 || argument[i] > 57)
			{
				isint = 1;
			}
		}
	}
	if (!argument || isint == 1) /*si y'a pas que des chiffre, ou pas d'argument*/
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		/*y'a des trucs a free ici*/
		exit(EXIT_FAILURE);
	}
	arg_number = atoi(argument);
	temp_node = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error Malloc");
		/*surement des trucs a free ici aussi*/
		exit(EXIT_FAILURE);
	}
	if (temp_node)
		temp_node->prev = new_node;
	new_node->n = arg_number;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

void pop(__attribute__((unused)) stack_t **stack,__attribute__((unused)) unsigned int line_number)
{
}