#include "monty.h"

/**
 * is_integer - Check if a string is an integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (str == NULL)
		return (0);

	int i = 0;

	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * push - Push an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, int line_number)
{
	char *arg;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

