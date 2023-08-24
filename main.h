#ifndef __MONTY_H_CUSTOM__
#define __MONTY_H_CUSTOM__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK_MODE 0
#define QUEUE_MODE 1
#define DELIMITERS " \n\t\a\b"

/* OPCODE TOKENS */
extern char **op_tokens;

/**
 *  * struct stack_s - Structure for doubly linked list node in stack or queue.
 *   * @n: Integer value.
 *    * @prev: Pointer to previous element.
 *     * @next: Pointer to next element.
 *      *
 *       * Description: Doubly linked list node structure for stack or queue.
 *        */
typedef struct stack_s
{
		int n;
			struct stack_s *prev;
				struct stack_s *next;
} stack_t;

/**
 *  * struct instruction_s - Structure for opcodes and corresponding functions.
 *   * @opcode: The opcode.
 *    * @f: Function to handle the opcode.
 *     *
 *      * Description: Structure mapping opcode to its function.
 *       */
typedef struct instruction_s
{
		char *opcode;
			void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int div_error(unsigned int line_number);
int f_open_error(char *filename);
int malloc_error(void);
int no_int_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int unknown_op_error(char *opcode, unsigned int line_number);
int usage_error(void);

/* OPCODE FUNCTIONS */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* PRIMARY INTERPRETER FUNCTIONS */
int check_mode(stack_t *stack);
void free_op_tokens(void);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int run_monty_script(FILE *script_fd);
void set_op_token_error(int error_code);

#endif /* __MONTY_H_CUSTOM__ */
