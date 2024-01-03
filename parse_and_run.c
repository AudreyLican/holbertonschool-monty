#include "header.h"
char *argument;

int parse_and_run(char *content, FILE *file, stack_t **stack, unsigned int line_number)
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

	token = strtok(content, " \n\t$");  /*store le token de la fonction( ex push)*/
	if (!token)
		return (1);
	argument = strtok(NULL, " \n\t$"); /* store ce qu'il y a juste apres (ex 1) dans la variable globale*/
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number); /*argument sera passé par la variable globale*/
			return (0);
		}
		i++;
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		free(content);
		free(token);
		free(argument);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	return (1);
}