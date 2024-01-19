#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
* main - Entry point for the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
*/
int main(int argc, char *argv[])
{
char opcode[10];
FILE *file;
int value;
stack_t *stack = NULL;
unsigned int line_number = 1;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
perror("Error opening file");
exit(EXIT_FAILURE);
}
while (fscanf(file, "%s", opcode) != EOF)
{
if (strcmp(opcode, "push") == 0)
{
if (fscanf(file, "%d", &value) != 1)
{
if (opcode[0] == '#')
{
while (fgetc(file) != '\n' && !feof(file))
;
continue;
}
fprintf(stderr, "Error: usage: push integer\n");
exit(EXIT_FAILURE);
}
}
execute_instruction(opcode, value, &stack, line_number);
line_number++;
}
fclose(file);
return (EXIT_SUCCESS);
}
