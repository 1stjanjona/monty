#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

extern char **optkns;

#define STACK 0
#define QUEUE 1

#define MAX_LINELENGTH 1024
#define MAX_TOKENS_PER_LINE 64
#define DLMTRS " \n\t\a\b"

#define opcode_push 1
#define opcode_pall 2

char **optkns;
int optkns_count;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**typedef struct
{
	char *op;

	op_code func;
} opcodes_t;*/

typedef int (*op_code)(stack_t **, unsigned int);

int cant_pchar(unsigned int nth_line, char *output);
int unknown_opcode(unsigned int nth_line, char *opcode);
int cant_open(char *file_name);
int monty_file(void);
int malloc_failed(void);

int push_int(unsigned int nth_line);
int pint_empty(unsigned int nth_line);
int pop_empty(unsigned int nth_line);
int stack_short(unsigned int nth_line, char *opcode);
int div_by_0(unsigned int nth_line);

void handle_push(stack_t **top, unsigned int nth_line);
void handle_pall(stack_t **top, unsigned int nth_line);
void handle_pint(stack_t **top, unsigned int nth_line);
void handle_pop(stack_t **top, unsigned int nth_line);
void handle_swap(stack_t **top, unsigned int nth_line);

int get_stk_que(stack_t **stk_que);
int is_stack_queue(stack_t *stk_que);
void set_free(stack_t **stk_que);

void (*get_op_code(char *op))(stack_t **, unsigned int);
int execute_monty(FILE *f);
int check_line(char *line, char *dlmtrs);

unsigned int arr_tkns_lngth(void);
void err_optkns(int err);
void free_tkns(void);

void opcode_add(stack_t **stk_que, unsigned int nth_line);
void opcode_sub(stack_t **stk_que, unsigned int nth_line);
void opcode_mul(stack_t **stk_que, unsigned int nth_line);
void opcode_div(stack_t **stk_que, unsigned int nth_line);
void opcode_mod(stack_t **stk_que, unsigned int nth_line);

void opcode_nop(stack_t **top, unsigned int nth_line);
void opcode_pchar(stack_t **top, unsigned int nth_line);
void opcode_pstr(stack_t **top, unsigned int nth_line);
void opcode_rotl(stack_t **top, unsigned int nth_line);
void opcode_rotr(stack_t **top, unsigned int nth_line);

int wordlngth(char *str, char *dlmtrs);
int wordcount(char *str, char *dlmtrs);
char *nextword(char *str, char *dlmtrs);
int check_dlmtrs(char chr, char *dlmtrs);
char **strtoword(char *str, char *dlmtrs);

#endif /* MONTY_H */
