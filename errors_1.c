#include "monty.h"

/**
 * usage_error - Handles usage error.
 *
 * Return: EXIT_FAILURE.
 */
int usage_error(void)
{
	fprintf(stderr, "ERROR: Usage: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Handles memory allocation error.
 *
 * Return: EXIT_FAILURE.
 */
int malloc_error(void)
{
	fprintf(stderr, "ERROR: Memory allocation failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Handles file open error.
 * @filename: Name of file.
 *
 * Return: EXIT_FAILURE.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "ERROR: Unable to open file: %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Handles unknown operation error.
 * @opcode: Opcode.
 * @line_number: Line number.
 *
 * Return: EXIT_FAILURE.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "ERROR: Unknown instruction '%s' at line %u\n", opcode, line_number);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Handles invalid integer error.
 * @line_number: Line number.
 *
 * Return: EXIT_FAILURE.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "ERROR: Invalid argument for 'push' at line %u\n", line_number);
	return (EXIT_FAILURE);
}
