#include "monty.h"

/**
 * push - add a node on the head of the stack
 *
 * @list: actual stack
 * @line_number: actual line of monty instruction
 *
 * Return: No return, void function
 */

void push(stack_t **list, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int number;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (!isdigit(global_token[0]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		do_free(list);
		exit(EXIT_FAILURE);
	}

	number = atoi(global_token);

	new_node->n = number;
	new_node->next = *list;
	new_node->prev = NULL;

	if (*list != NULL)
		(*list)->prev = new_node;

	*list = new_node;
}
