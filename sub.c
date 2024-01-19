#include "monty.h"
#include <stdio.h>

/**
* sub - Subtracts the top element of
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function subtracts the top ele
* If the stack contains less than two
* and exits with EXIT_FAILURE. The re
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
