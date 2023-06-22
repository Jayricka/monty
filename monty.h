#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack and queue implementation
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Function declarations */
void execute_instruction(char *instruction, stack_t **stack,
                         unsigned int line_number);
void execute_file(const char *filename);
void push(stack_t **stack, int n);
void pall(stack_t **stack);
void free_stack(stack_t *stack);

#endif /* MONTY_H */

