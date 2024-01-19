#include "monty.h"

/**
* nop - Does nothing
* @stack: Pointer to the address of the stack
* @line_number: Line number in the Monty bytecode file
*
* Description:
* This function does nothing. It is used for the nop opcode,
* which doesn't perform any operation.
*/
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
