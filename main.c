#include "monty.h"

char *global_token = NULL;

/**
* main - check the code, entry point
*
* @argc: nbr of arguments gave by the user
* @argv: arguments gave by the user
*
* Return: always 0
*/

int main(int argc, char *argv[])
{
    FILE *file = NULL;
    stack_t *list = NULL;
    char *instruct = NULL;
    char *line = NULL;
    size_t line_nbr = 0;
    size_t len = 0;
    ssize_t read = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if(file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    read = getline(&line, &len, file);
    while (read != -1)
    {
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
        line_nbr++;
        instruct = strtok(line, "\n");
        while (instruct != NULL)
        {
            get_func(&list, instruct, line_nbr);
            instruct = strtok(NULL, "\n");
        }
        free(line);
        line = NULL;
        read = getline(&line, &len, file);
    }
    free(line);
    do_free(&list);
    fclose(file);
    return (0);
}