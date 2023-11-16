#include "monty.h"
int cant_pchar(unsigned int nth_line, char *output);
int unknown_opcode(unsigned int nth_line, char *opcode);
int cant_open(char *file_name);
int monty_file(void);
int malloc_failed(void);
/**
 * cant_pchar - print can't pchar
 * @nth_line: line number
 * @output: error output
 * Return: exit failure
*/
int cant_pchar(unsigned int nth_line, char *output)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", nth_line, output);
	return (EXIT_FAILURE);
}
/**
 * unknown_opcode - print unknown instruction
 * @nth_line: line number
 * @opcode: opcode postion
 * Return: exit failure
*/
int unknown_opcode(unsigned int nth_line, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", nth_line, opcode);
	return (EXIT_FAILURE);
}
/**
 * cant_open - print can't open file
 * @file_name: file name
 * Return: exit failure
*/
int cant_open(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}
/**
 * monty_file - print usage monty file
 *
 * Return: exit failure
*/
int monty_file(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * malloc_failed - print malloc failed
 *
 * Return: exit failure
*/
int malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
