#include <stdio.h>
#include "monty.h"
unsigned int arr_tkns_lngth(void);
void err_optkns(int err);
void free_tkns(void);
char *itoa(int num);
/**
 * arr_tkns_lngth - get length of optkns
 *
 * Return: tkns_lngth
*/
unsigned int arr_tkns_lngth(void)
{
	unsigned int tkns_lngth = 0;

	while (optkns[tkns_lngth])
	{
		tkns_lngth++;
	}
	return (tkns_lngth);
}
/**
 * err_optkns - error code
 * @err_str: error string
 * @lngth: length of err_str
 * @f_ptr: file
 * Return: no return
*/
void err_optkns(int err)
{
	int tkns_lngth = 0, ndx = 0;
	char **tkns = NULL, *exitcode = NULL;

	tkns_lngth = arr_tkns_lngth();
	tkns = malloc(sizeof(char *) * (tkns_lngth + 2));
	if (optkns == NULL)
	{
		malloc_failed();
		return;
	}
	while (ndx < tkns_lngth)
	{
		tkns[ndx] = optkns[ndx];
		ndx++;
	}
	exitcode = itoa(err);
	if (!exitcode)
	{
		free(tkns), tkns = NULL;
		malloc_failed();
		return;
	}
	tkns[ndx++] = exitcode;
	tkns[ndx]  = NULL;
	free(optkns), optkns = NULL;
	optkns = tkns;
}
/**
 * free_tkns - free optkns
 *
 * Return: no return
*/
void free_tkns(void)
{
	size_t ndx = 0;

	if (optkns == NULL)
	{
		return;
	}
	for (ndx = 0; optkns[ndx]; ndx++)
	{
		free(optkns[ndx]);
	}
	free(optkns);
}
/**
 * itoa - integer to array
 * @num: number
 * Return: return string
*/
char *itoa(int num)
{
	int lngth;
	char *str;

	lngth = snprintf(NULL, 0, "%d", num);
	str = malloc(lngth + 1);

	if (str != NULL)
	{
		snprintf(str, lngth + 1, "%d", num);
	}
	return (str);
}
