#include "monty.h"

/**
* rotr - Rotates the stack to the bottom
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* The last element of the stack becomes the top element of the stack.
* rotr never fails.
*/
void rotr(stack_t **stack, unsigned int line_number)
{
(void)line_number;

if (*stack != NULL && (*stack)->next != NULL)
{
stack_t *last = *stack;
stack_t *secondLast = NULL;

while (last->next != NULL)
{
secondLast = last;
last = last->next;
}

last->next = *stack;
(*stack)->prev = last;
secondLast->next = NULL;
last->prev = NULL;
*stack = last;
}
}
