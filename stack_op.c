#include "monty.h"

/**
 * mod_nodes - Computes the modulo of the top two elements in the stack.
 * @stack: Pointer to a pointer
 * @line_number: Line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer
 * @line_number: Line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
