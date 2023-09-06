#include "monty.h"

void pop(stack_t **list, unsigned int line_nbr)
{
    stack_t *temp_pop;

    if (*list == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_nbr);
        exit(EXIT_FAILURE);
    }

    temp_pop = *list;
    *list = (*list)->next;
    if (*list != NULL)
        (*list)->prev = NULL;
    
    free(temp_pop);
}