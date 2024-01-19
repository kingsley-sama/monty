#include "monty.h"
#include <stdio.h>
/**
* swap - Swaps the top two elements of the stack
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function swaps the top two elements of the stack.
* If the stack contains less than two elements, it prints an error
* message to stderr and exits with EXIT_FAILURE.
*/
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *top = *stack;
stack_t *next_node = top->next;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}



top->next = next_node->next;
top->prev = next_node;

if (next_node->next != NULL)
{
next_node->next->prev = top;
}

next_node->prev = NULL;
next_node->next = top;

*stack = next_node;
}
