#include "monty.h"

/**
* rotl - Rotates the stack to the top
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* The top element of the stack becomes the last one,
* and the second top element of the stack becomes the first one.
* rotl never fails.
*/
void rotl(stack_t **stack, unsigned int line_number)
{
(void)line_number;

if (*stack != NULL && (*stack)->next != NULL)
{
stack_t *last = *stack;

while (last->next != NULL)
{
last = last->next;
}

last->next = *stack;
(*stack)->prev = last;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}
}
