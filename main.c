#include "monty.h"
	FILE *openFile;
	char *lineContent;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: value of arguments
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int readStatus = 1;
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
	openFile = file;
	while (readStatus > 0)
	{
		lineBuffer = NULL;
		readStatus = getline(&lineBuffer, &lineSize, file);
		line_number++;
		if (readStatus > 0 && lineBuffer[0] != '#' && lineBuffer[0] != '\n')
		{
			lineContent = lineBuffer;
			parse_and_run(lineBuffer, file, &stack, line_number);
		}
		free(lineBuffer);
	}
	free_all_close_file(lineBuffer, NULL, argument, &stack, file);
	return (0);
}
