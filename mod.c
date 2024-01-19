#include "monty.h"
#include <stdio.h>

/**
* mod - Computes the rest of the division of
*       of the stack by the top element
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function computes th
* of the stack by the top element.
* If the stack contains les
* and exits with EXIT_FAILU
* and the top element is removed.
* If the top element of the
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
