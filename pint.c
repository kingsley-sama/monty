#include "monty.h"
#include <stdio.h>

/**
* pint - prints the value at the top of the stack
* @stack: pointer to the address of the stack
* @line_number: line number in the Monty bytecode file
*
* Description:
* This function prints the value at the top of the stack,
* followed by a new line. If the stack is empty, it prints
* an error message to stderr and exits with EXIT_FAILURE.
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
