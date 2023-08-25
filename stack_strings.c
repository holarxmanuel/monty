#include "monty.h"

/**
 * print_char - Prints the ASCII value as a character.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
		string_err(10, line_number);
	printf("%c\n", ascii_value);
}

/**
 * print_str - Prints a string using ASCII values.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int ascii_value;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii_value = tmp->n;
		if (ascii_value <= 0 || ascii_value > 127)
			break;
		printf("%c", ascii_value);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
