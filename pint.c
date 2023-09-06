#include "monty.h"

void pint(stack_t **list, unsigned int line_number)
{
    if (*list == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*list)->n);
}