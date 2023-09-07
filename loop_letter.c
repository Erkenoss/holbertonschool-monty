#include "monty.h"

/**
* loop_letter - check if there is letter in argument give
* with push
*
* @global_token: argument for push
*
* Return: no return, void function
*/

void loop_letter(stack_t **list, char *global_token, unsigned int line_number)
{
    int i = 0;

    if (global_token[0] == '-')
    {
        return;
    }

    if (global_token == NULL || global_token[0] == '\0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
		do_free(list);
		exit(EXIT_FAILURE);
    }

    while (global_token[i] != '\0')
    {
        if (global_token[i] < '0' || global_token[i] > '9')
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
		    do_free(list);
		    exit(EXIT_FAILURE);
        }
        i++;
    }
}