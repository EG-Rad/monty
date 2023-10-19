#include "monty.h"

/* Implementation of pint opcode */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_stack();
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
