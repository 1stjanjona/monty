#include "monty.h"
void opcode_add(stack_t **stk_que, unsigned int nth_line);
void opcode_sub(stack_t **stk_que, unsigned int nth_line);
void opcode_mul(stack_t **stk_que, unsigned int nth_line);
void opcode_div(stack_t **stk_que, unsigned int nth_line);
void opcode_mod(stack_t **stk_que, unsigned int nth_line);
/**
 * opcode_add - add the top two
 * @stk_que: the top stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_add(stack_t **stk_que, unsigned int nth_line)
{
	if ((*stk_que)->next == NULL || (*stk_que)->next->next == NULL)
	{
		err_optkns(stack_short(nth_line, "add"));
		return;
	}
	(*stk_que)->next->next->n += (*stk_que)->next->n;
	handle_pop(stk_que, nth_line);
}
/**
 * opcode_sub - sub top two
 * @stk_que: top stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_sub(stack_t **stk_que, unsigned int nth_line)
{
	if ((*stk_que)->next == NULL || (*stk_que)->next->next == NULL)
	{
		err_optkns(stack_short(nth_line, "sub"));
		return;
	}
	(*stk_que)->next->next->n -= (*stk_que)->n;
	handle_pop(stk_que, nth_line);
}
/**
 * opcode_mul - multiply top two
 * @stk_que: top stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_mul(stack_t **stk_que, unsigned int nth_line)
{
	if ((*stk_que)->next == NULL || (*stk_que)->next->next == NULL)
	{
		err_optkns(stack_short(nth_line, "mul"));
		return;
	}
	(*stk_que)->next->next->n *= (*stk_que)->next->n;
	handle_pop(stk_que, nth_line);
}
/**
 * opcode_div - divide top two
 * @stk_que: top stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_div(stack_t **stk_que, unsigned int nth_line)
{
	if ((*stk_que)->next == NULL || (*stk_que)->next->next == NULL)
	{
		err_optkns(stack_short(nth_line, "div"));
		return;
	}
	if ((*stk_que)->next->n == 0)
	{
		err_optkns(div_by_0(nth_line));
		return;
	}
	(*stk_que)->next->next->n /= (*stk_que)->next->n;
	handle_pop(stk_que, nth_line);
}
/**
 * opcode_mod - top two modulus
 * @stk_que: top stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_mod(stack_t **stk_que, unsigned int nth_line)
{
	if ((*stk_que)->next == NULL || (*stk_que)->next->next == NULL)
	{
		err_optkns(stack_short(nth_line, "mod"));
		return;
	}
	if ((*stk_que)->next->n == 0)
	{
		err_optkns(div_by_0(nth_line));
		return;
	}
	(*stk_que)->next->next->n %= (*stk_que)->next->n;
	handle_pop(stk_que, nth_line);
}
