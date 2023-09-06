#include "monty.h"

/**
* do_free - free all the stack
*
* @list: actual stack to free
*
* Return: No return, void function
*/

void do_free(stack_t **stack)
{
    stack_t *temp_ptr;
    stack_t *current = *stack;

    while (current != NULL)
    {
        temp_ptr = current->next;
        free(current);
        current = temp_ptr;
    }
}