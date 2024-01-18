#include "monty.h" 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
		char opcode[10];
		FILE *file;
		int value;
		stack_t *stack;

		if (argc != 2)
		{
				fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
				exit(EXIT_FAILURE);
		}
		file = fopen(argv[1],"r");
		if (file == NULL)
		{
				perror("Error Opening file");
				exit(EXIT_FAILURE);
		}
		
		while (fscanf(file, "%s", opcode) != EOF) {
				if (strcmp(opcode, "push") == 0) {
						if (fscanf(file, "%d", &value) != 1) {
								fprintf(stderr, "Error: usage: push integer\n");
								exit(EXIT_FAILURE);
						}
						push(&stack, value);
				} else if (strcmp(opcode, "pall") == 0) {
						pall(&stack, 0);
				}
		}
		fclose(file);
		return (0);
}
