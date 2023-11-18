#include "monty.h"
void opcode_nop(stack_t **top, unsigned int nth_line);
void opcode_pcahr(stack_t **top, unsigned int nth_line);
void opcode_pstr(stack_t **top, unsigned int nth_line);
void opcode_rotl(stack_t **top, unsigned int nth_line);
void opcode_rotr(stack_t **top, unsigned int nth_line);
/**
 * opcode_nop - opcode nop
 * @top: top of ctack
 * @nth_line: line number
 * Return: no return
*/
void opcode_nop(stack_t **top, unsigned int nth_line)
{
	(void)top;
	(void)nth_line;
}
/**
 * opcode_pchar - print characters of top
 * @top: top of stack to be printed
 * @nth_line: line number
 * Return: no return
*/
void opcode_pchar(stack_t **top, unsigned int nth_line)
{
	if ((*top)->next == NULL)
	{
		err_optkns(cant_pchar(nth_line, "stack empty"));
		return;
	}
	if ((*top)->next->n < 0 || (*top)->next->n > 127)
	{
		err_optkns(cant_pchar(nth_line, "value out of range"));
		return;
	}
	printf("%c\n", (*top)->next->n);
}
/**
 * opcode_pstr - print the string in top of stack
 * @top: top of stack
 * @nth_line: line number
*/
void opcode_pstr(stack_t **top, unsigned int nth_line)
{
	stack_t *pass = (*top)->next;
	(void)nth_line;

	while (pass && (pass->n > 0 && pass->n <= 127))
	{
		printf("%c\n", pass->n);
		pass = pass->next;
	}
	printf("\n");
}
/**
 * opcode_rotl - rotate the stack to the top
 * @top: the top of stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_rotl(stack_t **top, unsigned int nth_line)
{
	stack_t *head = *top, *nexthead = (*top)->next;
	(void)nth_line;

	while (head->next)
	{
		head = head->next;
	}
	head->next = *top;
	(*top)->prev = head;
	nexthead->prev = NULL;
	*top = nexthead;
}
/**
 * opcode_rotr - rotate the top of stack to bottom
 * @top: top of stack
 * @nth_line: line number
 * Return: no return
*/
void opcode_rotr(stack_t **top, unsigned int nth_line)
{
	stack_t *bottom = *top;
	(void)nth_line;

	if (*top && (*top)->next)
	{
		while (bottom->next)
		{
			bottom = bottom->next;
		}
		bottom->prev->next = NULL;
		bottom->prev = NULL;
		bottom->next = *top;
		(*top)->prev = bottom;
		*top = bottom;
	}
}
