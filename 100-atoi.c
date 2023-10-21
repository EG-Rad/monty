#include "monty.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
int sign = 1; /* Positive by default */
int result = 0;
int i = 0;

    /* Skip whitespace */
while (s[i] == ' ')
{
i++;
}

    /* Check for sign */
if (s[i] == '-' || s[i] == '+')
{
if (s[i] == '-')
sign = -1;
i++;
}

    /* Convert string to integer */
while (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}

return (result *sign);
}

