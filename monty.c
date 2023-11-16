#include "monty.h"
void (*get_op_code(char *op))(stack_t**, unsigned int);
int execute_monty(FILE *f);
int check_line(char *line, char *dlmtrs);
/**
 * get_op_code - get opcode
 * @op: opcode
 * Return: void
*/
void (*get_op_code(char *op))(stack_t**, unsigned int)
{
	size_t ndx;

	opcodes_t code_op[] = {
		{"push", opcode_push}, {"pall", opcode_pall},
		{"pint", opcode_pint}, {"pop", opcode_pop},
		{"swap", opcode_swap}, {"add", opcode_add},
		{"nop", opcode_nop}, {"div", opcode_div},
		{"pchar", opcode_pchar}, {"pstr", opcode_pstr},
		{"stack", opcode_stack}, {"queue", opcode_queue},
		{"sub", opcode_sub}, {"mul", opcode_mul},
		{"rotr", opcode_rotr}, {"rotl", opdoce_rotl},
		{"mod", opcode_mod}, {NULL, NULL}
	};
	for (ndx = 0; code_op[ndx].op; ndx++)
	{
		if (strcmp(op, code_op[ndx].op) == 0)
		{
			return (code_op[ndx].func);
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
	void (*code_op)(stack_t**, unsigned int);

	if (get_stk_que(&stk_que) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	while (getline(&line, &lngth, f) != -1)
	{
		nth_line++;
		optkns = strtow(line, DLMTRS);
		if (optkns == NULL)
		{
			if (is_line_empty(line, DLMTRS))
			{
				continue;
			}
			free_stk(&stk_que);
			return (malloc_error());
		}
		else if (optkns[0][0] == '#')
		{
			free_tkns();
			continue;
		}
		code_op = get_op_code(optkns[0]);
		if (code_op == NULL)
		{
			free_stk(&stk_que);
			exitcode = err_unkwn_op(optkns[0], nth_line);
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
	free_stk_que(&stk_que);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exitcode);
}
/**
 * check_line - check line
 * @line: line
 * @dlmtrs: string of delimiters
 * Return: return -1 for delimiters, else return 0
*/
int check_line(char *line, char *dlmtrs)
{
	int ndx, idx;

	for (idx = 0; line[idx]; idx++)
	{
		for (ndx = 0; dlmtrs[ndx]; ndx++)
		{
			if (line[idx] == dlmtrs[ndx])
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
