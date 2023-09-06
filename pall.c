#include "monty.h"

/**
* pall - display all the stack
*
* @list: actual stack
* @line_number: actual line of monty instruction
*
* Return: No return, void function
*/

void pall(stack_t **list, unsigned int line_number)
{
    stack_t *ptr = *list;
    (void) line_number;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}