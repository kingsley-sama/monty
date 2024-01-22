#include "monty.h"

/**
* stack - Sets the format of the data to a stack (LIFO)
* @stack: Pointer to the stack
* @line_number: Line number in the Monty file
*/
void stack(stack_t **stack, unsigned int line_number)
{
(void)line_number;
(void)stack;

}

/**
* queue - Sets the format of the data to a queue (FIFO)
* @stack: Pointer to the stack
* @line_number: Line number in the Monty file
*/
void queue(stack_t **stack, unsigned int line_number)
{
stack_t *temp = NULL;

(void)line_number;
reverseStack(stack);
if (*stack != NULL && (*stack)->next != NULL)
{
temp = (*stack)->next;
temp->prev = NULL;
(*stack)->next = NULL;
*stack = temp;
}
}

/**
* reverseStack - Reverses a doubly linked list (stack)
* @stack: Pointer to the stack
*/
void reverseStack(stack_t **stack)
{
stack_t *current = *stack;
stack_t *temp = NULL;

while (current != NULL)
{
temp = current->prev;
current->prev = current->next;
current->next = temp;
current = current->prev;
}
if (temp != NULL)
{
*stack = temp->prev;
}
}
