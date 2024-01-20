#include "monty.h"
#include <stdio.h>

/**
* mod - Computes the rest of the division
*       of the stack by the top element
* @stack: Pointer to the address of the
* @line_number: Line number in the Monty
*
* Description:
* This function computes the rest of
* of the stack by the top element.
* If the stack contains less than two
* and exits with EXIT_FAILURE. The re
* and the top element is removed.
* If the top element of the stack is 0,
* and exits with EXIT_FAILURE.
*/
void mod(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n %= (*stack)->n;
pop(stack, line_number);
}
