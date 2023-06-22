#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "monty.h"

/**
* execute_instruction - Parse and execute a single instruction
* @instruction: The instruction string
* @stack: Pointer to the top of the stack
* @line_number: The line number in the file
*/
void execute_instruction(char *instruction, stack_t **stack,
unsigned int line_number)
{
char *opcode;
int arg;

opcode = strtok(instruction, " \t\n");
if (opcode == NULL)
return;

if (strcmp(opcode, "push") == 0)
{
/* Extract the argument for push */
char *arg_str = strtok(NULL, " \t\n");
if (arg_str == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

arg = atoi(arg_str);
push(stack, arg);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(stack);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}

/**
* execute_file - Execute instructions from a file
* @filename: The name of the file to read instructions from
*/
void execute_file(const char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t line_length = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, line_length, file) != NULL)
    {
        line_number++;
        read = strlen(line);
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';  /* Remove newline character */
        execute_instruction(line, &stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
}
/**
* push - Push an element onto the stack
* @stack: Pointer to the top of the stack
* @n: The value to push onto the stack
*/
void push(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}
/**
* pall - Print all elements of the stack
* @stack: Pointer to the top of the stack
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

/**
* free_stack - Free the stack
* @stack: Pointer to the top of the stack
*/
void free_stack(stack_t *stack)
{
stack_t *current = stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}
