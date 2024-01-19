#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
*pall - this function prints all the nodes of a stack
*@stack: a pointer to the address of the stack
*@line_number: this is the index to printf
*Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;
while (current != NULL)
{
fprintf(stdout, "%d\n", current->n);
current = current->next;
}
}
