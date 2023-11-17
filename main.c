#include "monty.h"
/**
 * main - main function of monty
 * @argc: argument count
 * @argv: argument vector
 * Return: exit failure or exit success
 */
int main(int argc, char **argv)
{
	FILE *f = fopen(argv[1], "r");
	int exitcode = execute_monty(f);

	if (argc != 2)
	{
		return (monty_file());
	}
	if (f == NULL)
	{
		return (cant_open(argv[1]));
	}
	fclose(f);
	return (exitcode);
}
