#include "monty.h"
#include <string.h>

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 *
 * Description: Frees the memory used by a stack_t linked list.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes a stack_t stack with beginning stack and ending queue nodes.
 * @stack: A pointer to an uninitialized stack_t stack.
 *
 * Return: EXIT_FAILURE on error, otherwise EXIT_SUCCESS.
 *
 * Description: Initializes a stack_t stack with a beginning node.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 *
 * Return: STACK (0) for stack mode, QUEUE (1) for queue mode, 2 for unknown.
 *
 * Description: Determines whether the stack_t linked list is in stack or queue mode.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
