#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_params_s - parameters for instruction functions
 * @stack: pointer to the stack
 * @value: value associated with the opcode (if applicable)
 * @line_number: line number in the Monty file
 *
 * Description: parameters structure for instruction functions
 */
typedef struct
{
    stack_t **stack;
    int value;
    unsigned int line_number;
} instruction_params_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(instruction_params_t *params);
} instruction_t;

void initializeStack(stack_t **stack);
void push(instruction_params_t *params);
void pall(instruction_params_t *params);
void pint(instruction_params_t *params);
void pop(instruction_params_t *params);
void swap(instruction_params_t *params);
void add(instruction_params_t *params);
void nop(instruction_params_t *params);
void sub(instruction_params_t *params);
void div_op(instruction_params_t *params);
void mul(instruction_params_t *params);
void mod(instruction_params_t *params);
void pchar(instruction_params_t *params);
void pstr(instruction_params_t *params);
void rotl(instruction_params_t *params);
void rotr(instruction_params_t *params);
void stack(instruction_params_t *params);
void queue(instruction_params_t *params);
void reverseStack(instruction_params_t *params);
void execute_instruction(char *opcode, instruction_params_t *params);
void execute_instruction(char *opcode, int value, stack_t **stack, unsigned int line_number);
#endif
