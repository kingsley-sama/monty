#include "monty.h"
#include <stdio.h>

/**
* pstr - Prints the string starting at the top of th
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function prints the string starting at the to
* The integer stored in each element of the stack is
* The string stops when either:
* - The stack is over
* - The value of the element is 0
* - The value of the element is not in the ASCII table
* If the stack is empty, it prints only a new line.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;
while (current != NULL && current->n != 0
	   && (current->n >= 0
											  && current->n <= 127))
{
putchar(current->n);
current = current->next;
}
putchar('\n');
}
