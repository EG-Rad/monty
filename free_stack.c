#include "monty.h"

/* Function to free the stack */
void free_stack(void)
{
    stack_t *current = stack;
    while (current != NULL)
    {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
    stack = NULL;
}
