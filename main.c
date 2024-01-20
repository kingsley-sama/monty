#include "monty.h"
/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
		char opcode[10];
		size_t len;
		FILE *file;
		int value = 0;
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
		while (fscanf(file, "%9s", opcode) != EOF)
		{
				len = strlen(opcode);
				if (len > 0 && opcode[len - 1] == '$')
						opcode[len - 1] = '\0';
				if (strcmp(opcode, "push") == 0)
				{
						if (fscanf(file, "%d", &value) != 1)
						{
								if (opcode[0] == '#')
								{
										while (fgetc(file) != '\n' && !feof(file))
												;
								}
								fprintf(stderr, "Error: usage: push integer\n");
								exit(EXIT_FAILURE);
						}
						push(&stack, value);
				}
				else if (strcmp(opcode, "pall") == 0)
				{
						pall(&stack, 0);
				}
				else if (strcmp(opcode, "pall") != 0 && strcmp(opcode, "push")
						 != 0 && strlen(opcode) != 0)
				{
						execute_instruction(opcode, value, &stack, line_number);
				}
				line_number++;
		}
		fclose(file);
		while (stack != NULL)
				pop(&stack, 0);
		return (EXIT_SUCCESS);
}
