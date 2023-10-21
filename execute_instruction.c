#include "monty.h"

/* Function to execute Monty instructions */
void execute_instruction(char *line, unsigned int line_number)
{
    char *opcode;
    opcode = strtok(line, " \t\n");

    if (opcode == NULL || *opcode == '#')
        return;  

    if (strcmp(opcode, "push") == 0)
    {
        push(&stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(&stack, line_number);
    }
    else if (strcmp(opcode, "pint") == 0) 
    {
        pint(&stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        free_stack();
        exit(EXIT_FAILURE);
    }
}

