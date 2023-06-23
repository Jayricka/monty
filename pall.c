#include <stdio.h>
#include "monty.h"

/**
* pall - Prints all the values on the stack, starting from the top
* @stack: Double pointer to the stack
*/
void pall(stack_t **stack)
{
stack_t *current = *stack;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
