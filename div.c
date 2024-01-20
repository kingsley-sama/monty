#include "monty.h"
#include <stdio.h>

/**
* div_op - Divides the second top
* @stack: Pointer to the address of the stack
* @line_number: Line number in the
*
* Description:
* This function divides the second
* If the stack contains less than
* and exits with EXIT_FAILURE. The
* and the top element is removed.
* If the top element of the stack
* and exits with EXIT_FAILURE.
*/
void div_op(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
(*stack)->next->n /= (*stack)->n;
pop(stack, line_number);
}
