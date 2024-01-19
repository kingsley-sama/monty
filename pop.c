#include "monty.h"
#include <stdio.h>

/**
* pop - removes the top element of the stack
* @stack: pointer to the address of the stack
* @line_number: line number in the Monty bytecode file
*
* Description:
* This function removes the top element of the stack.
* If the stack is empty, it prints an error message to stderr
* and exits with EXIT_FAILURE.
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *current_top = *stack;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
*stack = current_top->next;
free(current_top);
if (*stack != NULL)
{
(*stack)->prev = NULL;
}
}
