#include "monty.h"
/*char *argument;*/

/**
 * parse_and_run - find the right function (if any) associated
 * to the command from the file and execute it.
 * @content: line from the file to check
 * @file: file where commands are written
 * @stack: stack where to push the element
 * @line_number: line number that is analyzed
 * Return: (0) on success
 */

int parse_and_run(char *content, FILE *file,
stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}

	};
	char *token;
	int i = 0;
	GlobalMonty *Monty = getGlobalMonty();

	token = strtok(content, " \n\t$");
	if (!token)
		return (1);
	Monty->argument = strtok(NULL, " \n\t$");
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		free_all_close_file(content, stack, file);
		exit(EXIT_FAILURE);
	}
	return (1);
}
