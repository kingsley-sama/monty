#include "monty.h"
#include <stdio.h>

/**
* pchar - Prints the char at the top of the stack, followed by a new line
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function prints the char at the top of the stack,
* followed by a new line.
* The integer stored at the top of the stack is treated as the
* ASCII value of the character to be printed.
* If the value is not in the ASCII table (man ascii), it prints
* an error message to stderr
* and exits with EXIT_FAILURE.
* If the stack is empty, it prints an error message to stderr
* and exits with EXIT_FAILURE.
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
