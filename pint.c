#include "monty.h"

/**
 * pint - display the nhead of the stack
 *
 * @list: actual stack
 * @line_number: actual line of monty instruction
 *
 * Return: No return, void function
 */

void pint(stack_t **list, unsigned int line_number)
{
	if (*list == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*list)->n);
}
