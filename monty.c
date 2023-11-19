#include "monty.h"
#include <string.h>
#include <stdio.h>
void (*get_op_code(char *op))(stack_t **, unsigned int);
int execute_monty(FILE *f);
int check_line(char **line, size_t *lngth, FILE *f, char *dlmtrs);
int str_empty(char *line);
/**
 * get_op_code - get opcode
 * @op: opcode
 * Return: void
*/
void (*get_op_code(char *opcode))(stack_t **, unsigned int)
{
	size_t ndx;

	instruction_t code_op[] = {
		{"push", handle_push}, {"pall", handle_pall},
		{"pint", handle_pint}, {"pop", handle_pop},
		{"swap", handle_swap}, {"add", opcode_add},
		{"nop", opcode_nop}, {"div", opcode_div},
		{"pchar", opcode_pchar}, {"pstr", opcode_pstr},
		{"stack", opcode_stack}, {"queue", opcode_queue},
		{"sub", opcode_sub}, {"mul", opcode_mul},
		{"rotr", opcode_rotr}, {"rotl", opcode_rotl},
		{"mod", opcode_mod}, {NULL, NULL}
	};
	for (ndx = 0; code_op[ndx].opcode; ndx++)
	{
		if (strcmp(opcode, code_op[ndx].opcode) == 0)
		{
			return (code_op[ndx].f);
		}
	}
	return (NULL);
}
/**
 * execute_monty - execute monty
 * @f: file to open
 * Return: exit success, exit failure
*/
int execute_monty(FILE *f)
{
	stack_t *stk_que = NULL;
	char *line = NULL;
	size_t lngth = 0, exitcode = EXIT_SUCCESS;
	unsigned int nth_line = 0, prev_lngth = 0;
	void (*code_op)(stack_t **, unsigned int);

	if (get_stk_que(&stk_que) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	while (get_int(line, &lngth, f) != NULL)
	{
		nth_line++;
		optkns = strtoword(line, DLMTRS);
		if (optkns == NULL)
		{
			if (check_line(&line, &lngth, f, DLMTRS))
			{
				continue;
			}
			set_free(&stk_que);
			return (malloc_failed());
		}
		else if (optkns[0][0] == '#')
		{
			free_tkns();
			continue;
		}
		code_op = get_op_code(optkns[0]);
		if (code_op == NULL)
		{
			set_free(&stk_que);
			exitcode = unknown_opcode(optkns[0], nth_line);
			free_tkns();
			break;
		}
		prev_lngth = arr_tkns_lngth();
		code_op(&stk_que, nth_line);
		if (arr_tkns_lngth() != prev_lngth)
		{
			if (optkns && optkns[prev_lngth])
			{
				exitcode = atoi(optkns[prev_lngth]);
			}
			else
			{
				exitcode = EXIT_FAILURE;
			}
			free_tkns();
			break;
		}
		free_tkns();
	}
	set_free(&stk_que);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_failed());
	}
	free(line);
	return (exitcode);
}
/**
 * check_line - check line
 * @line: line
 * @lngth: length
 * @f: file
 * @dlmtrs: string of delimiters
 * Return: return -1 for delimiters, else return 0
*/
int check_line(char **line, size_t *lngth, FILE *f, char *dlmtrs)
{
	int ndx, idx;

	if (get_int(*line, lngth, f) == NULL)
	{
		return (-1);
	}
	for (idx = 0; (*line)[idx]; idx++)
	{
		for (ndx = 0; dlmtrs[ndx]; ndx++)
		{
			if ((*line)[idx] == dlmtrs[ndx])
			{
				break;
			}
		}
		if (dlmtrs[ndx] == '\0')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * str_empty - check if str is empty
 * @line: line
 * Return: return 1 for empty, otherwise return 0
*/
int str_empty(char *line)
{
	while (*line)
	{
		if (!isspace((unsigned char)*line))
		{
			return (0);
		}
		line++;
	}
	return (1);
}
