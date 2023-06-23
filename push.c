#include "monty.h"

/**
 * push - add node to the stack
 * @head: stack head
 * @line_counter: line_number
 *
 * Return: nothing to return
 */
void push(stack_t **head, unsigned int line_counter)
{
	int n, h = 0, flag = 0;

	if (dataHolder.arg)
	{
		if (dataHolder.arg[0] == '-')
			h++;
		for (; dataHolder.arg[h] != '\0'; h++)
		{
			if (dataHolder.arg[h] > 57 || dataHolder.arg[h] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			fclose(dataHolder.file);
			free(dataHolder.linecontent);
			free_stak(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		fclose(dataHolder.file);
		free(dataHolder.linecontent);
		free_stak(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(dataHolder.arg);
	if (dataHolder.mystack == 0)
		generate_node(head, n);
	else
		queue_creator(head, n);
}
