#include "header.h"

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
void pint(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

}