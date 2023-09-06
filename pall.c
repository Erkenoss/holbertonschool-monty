#include "monty.h"

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