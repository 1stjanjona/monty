#include "monty.h"
/**
 * main - main function of monty
 * @argc: argument count
 * @argv: argument vector
 * Return: exit failure or exit success
 */
int main(int argc, char **argv)
{
	FILE *f = NULL;
	int exitcode = EXIT_SUCCESS;

	if (argc != 2)
	{
		return (monty_file());
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		return (cant_open(argv[1]));
	}
	exitcode = execute_monty(f);
	fclose(f);
	free_tkns();
	return (exitcode);
}
