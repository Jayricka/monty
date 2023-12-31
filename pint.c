#include "monty.h"
/**
 * pinter - prints the value at the top of the stack.
 * @head: pointer to stack head
 * @line_counter: line_number
 *
*/
void pinter(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(dataHolder.file);
		free(dataHolder.linecontent);
		free_stak(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
