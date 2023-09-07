#include "monty.h"

/**
* add - adds the top two elements of the stack
*
* @list: actual stack
* @line_number: actual line of monty instruction
*
* Return: No return, void function
*/

void add(stack_t **list, unsigned int line_number)
{
    if (*list == NULL || (*list)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*list)->next->n += (*list)->n;
    pop(list, line_number);
}
