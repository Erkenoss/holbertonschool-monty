#include "monty.h"

/**
* get_func - check the instruction gave by monty file
*
* @list: actual stack
* @line_number: actual line of monty instruction
* @instruct: instruction take in the monty file
*
* Return: No return, void function
*/

void get_func(stack_t **stack, char *instruct, unsigned int line_number)
{
    instruction_t exec[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"add", add},
        {"nop", nop},
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
            exec[iteration].f(stack, line_number);
            return;
        }
        iteration++;
    }
    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token[0]);
    do_free(stack);
    exit(EXIT_FAILURE);
}