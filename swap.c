#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @list: actual stack
 * @line_number: current line
 *
 * Return: no return because void function
 */
void swap(stack_t **list, unsigned int line_number)
{
	stack_t *current_head;
	stack_t *new_head;

	if (*list == NULL || (*list)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current_head = *list;
	new_head = (*list)->next;

	new_head->prev = NULL;
	current_head->next = new_head->next;
	if (new_head->next != NULL)
	{
		new_head->next->prev = current_head;
	}
	new_head->next = current_head;
	current_head->prev = new_head;

	*list = new_head;
}
