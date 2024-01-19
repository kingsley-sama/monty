#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *push - this function pushes to the stack
 *@stack: this is a pointer to the address of the stack
 *@value: this is the integer value for the node of the stack
 *@line_number: line number
 */

void push(stack_t **stack, unsigned int line_number, int value)
{
		stack_t *new_node = malloc(sizeof(stack_t));

		(void) value;
		if (new_node == NULL)
		{
				fprintf(stderr, "Error: Memory allocation failed\n");
				exit(EXIT_FAILURE);
		}
		new_node->n = value;
		new_node->prev = NULL;
		new_node->next = *stack;
		if (*stack != NULL)
				(*stack)->prev = new_node;
		*stack = new_node;
}
