#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void process_instruction(char *opcode, char *data, unsigned int line_number,
stack_t **stack)
{
if (strcmp(opcode, "push") == 0)
{
/* Example implementation for push opcode */
/* Convert data to an integer and push it onto the stack */
int value = atoi(data);
push(stack, value);
}
else if (strcmp(opcode, "pall") == 0)
{
/* Example implementation for pall opcode */
/* Print all the elements in the stack */
pall(stack);
}
else
{
/* Handle unknown opcode */
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
