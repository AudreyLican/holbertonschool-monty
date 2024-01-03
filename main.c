#include "header.h"

int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t readStatus = 1;
	char *lineBuffer;
	unsigned int line_number = 0;
	size_t lineSize = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readStatus > 0)
	{
		lineBuffer = NULL;
		readStatus = getline(&lineBuffer, &lineSize, file);
		line_number++;
		if (readStatus > 0)
		{
			parse_and_run(lineBuffer, file, &stack, line_number);
		}
		free(lineBuffer);
	}
	fclose(file);
	return (0);
}

int parse_and_run(char *content, FILE *file, stack_t **stack, unsigned int line_number)
{
	/*changer le nom des functions*/
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
	char *token, *token_arg;
	int i = 0;

	token = strtok(content, " \n\t");  /*store le token de la fonction( ex push)*/
	token_arg = strtok(NULL, " \n\t"); /* store ce qu'il y a juste apres (ex 1)*/
	while (opcodes[i].opcode != NULL && token != NULL)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number); /*TODO: trouver comment passer token_arg a la fonction*/
			return (0);
		}
		i++;
	}
	if (token != NULL && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		free(content);
		free(token);
		free(token_arg);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	return (1);
}
