#include "monty.h"
int push_int(unsigned int nth_line);
int pint_empty(unsigned int nth_line);
int pop_empty(unsigned int nth_line);
int stack_short(unsigned int nth_line, char *opcode);
int div_by_0(unsigned int nth_line);
/**
 * push_int - push int for no integer
 * @nth_line: line number
 * Return: exit failure
*/
int push_int(unsigned int nth_line)
{
	fprintf(stderr, "L%u: usage: push integer\n", nth_line);
	return (EXIT_FAILURE);
}
/**
 * pint_empty - print pint empty
 * @nth_line: line number
 * Return: exit failure
*/
int pint_empty(unsigned int nth_line)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", nth_line);
	return (EXIT_FAILURE);
}
/**
 * pop_empty - print pop empty
 * @nth_line: line number
 * Return: exit failure
*/
int pop_empty(unsigned int nth_line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", nth_line);
	return (EXIT_FAILURE);
}
/**
 * stack_short - print stack too short
 * @nth_line: line number
 * @opcode: error position
 * Return: exit failure
*/
int stack_short(unsigned int nth_line, char *opcode)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", nth_line, opcode);
	return (EXIT_FAILURE);
}
/**
 * div_by_0 - print division by zero
 * @nth_line: line number
 * Return: exit failure
*/
int div_by_0(unsigned int nth_line)
{
	fprintf(stderr, "L%u: division by zero\n", nth_line);
	return (EXIT_FAILURE);
}
