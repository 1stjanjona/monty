#include "monty.h"
int get_stk_que(stack_t **stk_que);
int is_stack_queue(stack_t *stk_que);
void set_free(stack_t **stk_que);
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
 * @stk_que: stack or queue
 * Return: no return
*/
void set_free(stack_t **stk_que)
{
	stack_t *pass = *stk_que;

	while (*stk_que)
	{
		pass = (*stk_que)->next;
		free(stk_que), stk_que = NULL;
		*stk_que = pass;
	}
}
