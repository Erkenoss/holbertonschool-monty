#include "monty.h"

void push(stack_t **list, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    int number;
    
    (void) line_number;
 
    if (new_node == NULL)
        {
            fprintf(stderr, "Error: malloc failed");
            exit(EXIT_FAILURE);
        }

    number = atoi(global_token);

    if (!isdigit(global_token[0]))
        {
            fprintf(stderr, "Error: invalid argument\n");
            exit(EXIT_FAILURE);
        }

    new_node->n = number;
    new_node->next = *list;
    new_node->prev = NULL;

    if (*list != NULL)
        (*list)->prev = new_node;

    *list = new_node;
}