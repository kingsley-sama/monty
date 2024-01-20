#include "monty.h"
#include <stdio.h>

/**
* sub - Subtracts the top element of the stack from the second top element
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function subtracts the top element of the stack from the second top element.
* If the stack contains less than two elements, it prints an error message to stderr
* and exits with EXIT_FAILURE. The result is stored in the second top element of the stack,
* and the top element is removed.
*/
void sub(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
(*stack)->next->n -= (*stack)->n;
pop(stack, line_number);
}
