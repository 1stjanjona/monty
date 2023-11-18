#include "monty.h"
int wordlngth(char *str, char *dlmtrs);
int wordcount(char *str, char *dlmtrs);
char *nextword(char *str, char *dlmtrs);
int check_dlmtrs(char chr, char *dlmtrs);
char **strtoword(char *str, char *dlmtrs);
/**
 * wordlngth - get word length
 * @str: string
 * @dlmtrs: delimiters
 * Return: return lngth of words
*/
int wordlngth(char *str, char *dlmtrs)
{
	int lngth = 0, idx = 0, pend = 1;

	while (*(str + idx))
	{
		if (check_dlmtrs(str[idx], dlmtrs))
		{
			pend = 1;
		}
		if (pend)
		{
			lngth++;
		}
		if ((lngth > 0) && check_dlmtrs(str[idx], dlmtrs))
		{
			break;
		}
		idx++;
	}
	return (lngth);
}
/**
 * wordcount - count words of string
 * @str: string
 * @dlmtrs: delimiters
 * Return: return counted words
*/
int wordcount(char *str, char *dlmtrs)
{
	int count = 0, pend = 1, idx = 0;

	while (*(str + idx))
	{
		if (check_dlmtrs(str[idx], dlmtrs))
		{
			pend = 1;
		}
		if (pend)
		{
			pend = 0;
			count++;
		}
		idx++;
	}
	return (count);
}
/**
 * nextword - get next word in string
 * @str: string
 * @dlmtrs: delimiters
 * Return: return next word
*/
char *nextword(char *str, char *dlmtrs)
{
	int pend = 0, idx = 0;

	while (*(str + idx))
	{
		if (check_dlmtrs(str[idx], dlmtrs))
		{
			pend = 1;
		}
		if (pend)
		{
			break;
		}
		idx++;
	}
	return (str + idx);
}
/**
 * check_dlmtrs - check if it is delimiter
 * @chr: character
 * @dlmtrs: array of dlmtrs
 * Return: 1 on success or 0 on failure
*/
int check_dlmtrs(char chr, char *dlmtrs)
{
	int ndx = 0;

	while (dlmtrs[ndx])
	{
		if (dlmtrs[ndx] == chr)
		{
			return (1);
		}
		ndx++;
	}
	return (0);
}
/**
 * strtoword - separate the string to words
 * @str: string to be separated
 * @dlmtrs: delimiters
 * Return: return array
*/
char **strtoword(char *str, char *dlmtrs)
{
	char **words = NULL;
	int count, lngth, ndx = 0, idx = 0;

	if (!*str || str == NULL)
	{
		return (NULL);
	}
	count = wordcount(str, dlmtrs);
	if (count == 0)
	{
		return (NULL);
	}
	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}
	while (idx < count)
	{
		lngth = wordcount(str, dlmtrs);
		if (check_dlmtrs(*str, dlmtrs))
		{
			count = wordcount(str, dlmtrs);
		}
		words[idx] = malloc((lngth + 1) * sizeof(char));
		if (words[idx] == NULL)
		{
			for (idx = 0; idx >= 0; idx--)
			{
				free(words[idx]);
			}
			free(words), words = NULL;
			return (NULL);
		}
		for (ndx = 0; ndx < lngth; ndx++)
		{
			words[idx][ndx] = *(str + ndx);
		}
		words[idx][ndx] = '\0';
		str = nextword(str, dlmtrs);
		idx++;
	}
	words[idx] = NULL;
	return (words);
}
