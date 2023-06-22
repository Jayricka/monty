#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "opcode_pint.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Pointer to the top of the stack
 */
void pint(stack_t **stack)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}