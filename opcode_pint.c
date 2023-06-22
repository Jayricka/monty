#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (current == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
