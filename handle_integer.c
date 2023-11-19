#include "monty.h"
int buffer_len(unsigned int ntgr, unsigned int base);
void add_buffer(unsigned int ntgr, unsigned int base, char *buffer, int size);
unsigned int abs_num(int ntgr);
char *get_int(char *line, size_t *lngth, FILE *f);
/**
 * buffer_len - get the buffer length
 * @ntgr: the number we need len for it
 * @base: number base
 * Return: return len
*/
int buffer_len(unsigned int ntgr, unsigned int base)
{
	int lngth = 1;

	while (ntgr > (base - 1))
	{
		lngth++;
		ntgr /= base;
	}
	return (lngth);
}
/**
 * add_buffer - add to buffer
 * @ntgr: number to string
 * @base: base of number
 * @buffer: buffer
 * @size: buffer size
 * Return: no return
*/
void add_buffer(unsigned int ntgr, unsigned int base, char *buffer, int size)
{
	int tmp, ndx = size - 1;

	buffer[size] = '\0';
	while (ndx >= 0)
	{
		tmp = ntgr % base;
		if (tmp > 9)
		{
			buffer[ndx] = tmp + 87;
		}
		else
		{
			buffer[ndx] = tmp + '0';
		}
		ntgr /= base;
		ndx--;
	}
}
/**
 * abs_num - absolute value of integer
 * @ntgr: integer
 * Return: return ans_num
*/
unsigned int abs_num(int ntgr)
{
	if (ntgr < 0)
	{
		return (-(unsigned int)ntgr);
	}
	return ((unsigned int)ntgr);
}
/**
 * get_int - get a char from str int
 * @line: line
 * @lngth: length
 * @f: file
 * Return: return char
*/
char *get_int(char *line, size_t *lngth, FILE *f)
{
	unsigned int tmp;
	char *s;
	int l = 0;
	long num = 0;
	int ntgr = atoi(line);
	(void)(*f);

	tmp = abs_num(ntgr);
	l = buffer_len(tmp, 10);
	if (ntgr < 0 || num < 0)
	{
		l++;
	}
	s = malloc(l + 1);
	if (!s)
	{
		return (NULL);
	}
	add_buffer(tmp, 10, s, l);
	if (ntgr < 0 || num < 0)
	{
		s[0] = '-';
	}
	*lngth = l;
	return (s);
}
