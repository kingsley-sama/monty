#include "monty.h"
#include <stdio.h>

/**
* pchar - Prints the char at the t
* @stack: Pointer to the address o
* @line_number: Line number in the
*
* Description:
* This function prints the char at
* The integer stored at the top of
* If the value is not in the ASCII
* and exits with EXIT_FAILURE.
* If the stack is empty, it prints
*/
void pchar(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n < 0 || (*stack)->n > 127)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
putchar((*stack)->n);
putchar('\n');
}
