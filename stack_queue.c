#include "monty.h"
int get_stk_que(stack_t **stk_que);
int is_stack_queue(stack_t *stk_que);
void set_free(stack_t **stk_que);
void opcode_stack(stack_t **stk_que, unsigned int nth_line);
void opcode_queue(stack_t **stk_que, unsigned int nth_line);
/**
 * get_stk_que - make a stack or queue
 * @stk_que: stack_t stack
 * Return: exit failure or success
*/
int get_stk_que(stack_t **stk_que)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		return (EXIT_FAILURE);
	}
	stack->n = STACK;
	stack->prev = NULL;
	stack->next = NULL;
	*stk_que = stack;
	return (EXIT_SUCCESS);
}
/**
 * is_stack_queue - check if stack or queue
 * @stk_que: stack on top or queue on bottom
 * Return: return 0 for stck, 1 for que, else 2
*/
int is_stack_queue(stack_t *stk_que)
{
	(void)(*stk_que);

	if (stk_que->n == STACK)
	{
		return (STACK);
	}
	if (stk_que->n == QUEUE)
	{
		return (QUEUE);
	}
	return (2);
}
/**
 * set_free - free stack
 * @stk_que: top of stack
 * Return: no return
*/
void set_free(stack_t **stk_que)
{
	stack_t *pass = *stk_que;

	if (!stk_que || *stk_que)
	{
		return;
	}
	while (*stk_que)
	{
		(*stk_que) = (*stk_que)->next;
		free(pass);
		pass = NULL;
	}
}
/**
 * opcode_stack: opcode stack
 * @stk_que: stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_stack(stack_t **stk_que, unsigned int nth_line)
{
	(void)nth_line;

	if (*stk_que)
	{
		(*stk_que)->n = STACK;
	}
}
/**
 * opcode_queue - opcode queue
 * @stk_que: queue
 * @nth_line: line number
 * Return: no return
*/
void opcode_queue(stack_t **stk_que, unsigned int nth_line)
{
	(void)nth_line;

	if (*stk_que)
	{
		(*stk_que)->n = QUEUE;
	}
}
