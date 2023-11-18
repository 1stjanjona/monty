#include "monty.h"
unsigned int arr_tkns_lngth(void);
void err_optkns(int err);
void free_tkns(void);
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
 * @err: optkns integer
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
	exitcode = err;
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
