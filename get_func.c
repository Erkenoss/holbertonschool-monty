#include "monty.h"

void get_func(stack_t **stack, char *instruct, unsigned int line_nbr)
{
    instruction_t exec[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"add", add},
        {NULL, NULL}
    };
    char *number;
    int iteration = 0;
    char *token[100];
    int i = 0;
    
    number = strtok(instruct, " \t");
    while(number != NULL)
    {
        token[i] = number;
        i++;
        number = strtok(NULL, " \t");
    }
    global_token = token[1];

    while (exec[iteration].opcode != NULL)
    {        
        if (strcmp(exec[iteration].opcode, token[0]) == 0)
        {
            exec[iteration].f(stack, line_nbr);
            return;
        }
        iteration++;
    }
    fprintf(stderr, "L%d: unknown instruction %s\n", line_nbr, token[0]);
    exit(EXIT_FAILURE);
}