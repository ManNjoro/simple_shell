#include "shell.h"

/**
 * main - entry point for the shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *line, **args;
	int status = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		print_prompt();

		line = read_line();

		args = split_line(line);

		status = execute(args);

		free(args);
		free(line);

		if (status == 2)
			break;
	}

	return (0);
}
