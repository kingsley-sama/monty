#include "monty.h"

/**
 * execute_instruction - Execute Monty bytecode instructions
 * @opcode: Opcode to execute
 * @value: Value associated with the opcode (if applicable)
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void execute_instruction(char *opcode, int value, stack_t **stack, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"sub", sub},
        {"div", div_op},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"queue", queue},
        {NULL, NULL}
    };

    int i = 0;
    while (instructions[i].opcode != NULL)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instruction_params_t params = {stack, value, line_number};
            instructions[i].f(&params);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
