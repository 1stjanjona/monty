#include "monty.h"
void handle_push(stack_t **top, unsigned int nth_line);
void handle_pall(stack_t **top, unsigned int nth_line);
void handle_pint(stack_t **top, unsigned int nth_line);
void handle_pop(stack_t **top, unsigned int nth_line);
void handle_swap(stack_t **top, unsigned int nth_line);
/**
 * handle_push - push value to top
 * @top: pushed value to the top
 * @nth_line: the line number
 * Return: no return
*/
void handle_push(stack_t **top, unsigned int nth_line)
{
	stack_t *pass, *new;
	int ndx;
	(void)nth_line;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return;
	}
	if (optkns[1] == NULL)
	{
		return;
	}
	for (ndx = 0; optkns[1][ndx]; ndx++)
	{
		if (optkns[1][0] == '-')
		{
			continue;
		}
		if (optkns[1][ndx] < '0' || optkns[1][ndx] > '9')
		{
			return;
		}
	}
	new->n = atoi(optkns[1]);
	if (is_stack_queue(*top) == STACK)
	{
		pass = (*top)->next;
		new->prev = *top;
		new->next = pass;
		if (pass)
		{
			pass->prev = new;
		}
		(*top)->next = new;
	}
	else
	{
		pass = *top;
		if (pass->next)
		{
			pass = pass->next;
		}
		new->prev = pass;
		new->next = NULL;
		pass->next = new;
	}
}
/**
 * handle_pall - print the values of stack
 * @top: palled pointer to top
 * @nth_line: the line number
 * Return: no return
*/
void handle_pall(stack_t **top, unsigned int nth_line)
{
	stack_t *pass = (*top)->next;
	(void)nth_line;

	while (pass)
	{
		printf("%d\n", pass->n);
		pass = pass->next;
	}
}
/**
 * handle_pint - print the top value
 * @top: pinted pointer to top
 * @nth_line: the line number
 * Return: no return
*/
void handle_pint(stack_t **top, unsigned int nth_line)
{
	(void)nth_line;

	if ((*top)->next == NULL)
	{
		return;
	}
	printf("%d\n", (*top)->next->n);
}
/**
 * handle_pop - delete or remove the top value
 * @top: poped pointer to top
 * @nth_line: the line number
 * Return: no return
*/
void handle_pop(stack_t **top, unsigned int nth_line)
{
	stack_t *next = NULL;
	(void)nth_line;

	if ((*top)->next == NULL)
	{
		return;
	}
	next = (*top)->next->next;
	free((*top)->next);
	if (next)
	{
		next->prev = *top;
	}
	(*top)->next = next;
}
/**
 * handle_swap - swap the top two values
 * @top: swaped pointer to top
 * @nth_line: the line number
 * Return: no return
*/
void handle_swap(stack_t **top, unsigned int nth_line)
{
	stack_t *pass;
	(void)nth_line;

	if ((*top)->next == NULL || (*top)->next->next == NULL)
	{
		return;
	}
	pass = (*top)->next->next;
	(*top)->next->next = pass->next;
	(*top)->next->prev = pass;
	if (pass->next)
	{
		pass->next->prev = (*top)->next;
	}
	pass->next = (*top)->next;
	pass->prev = *top;
	(*top)->next = pass;
}
