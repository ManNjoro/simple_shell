#include "shell.h"
/**
 * main - Main arguments functions
 * @argc: argument count
 * @argv: argument vector
 * @env: Environment
 * Return: _exit = 0.
 */
int main(int argc, char **argv, char **env)
{
	int pathValue = 0, status = 0, is_path = 0;
	char *line = NULL, /**ptr to inpt*/ **args = NULL; /**tokenized commands*/
	(void)argc;
	while (1)/* loop until exit */
	{
		errno = 0;
		line = read_line();/** reads user input*/
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			pathValue++;
			args = tokenize(line);/** tokenizes or parse user input*/
			if (!args)
				free(line);
			if (!_strcmp(args[0], "env"))/**checks if user wrote env"*/
				_getenv(env);
			else
			{
				is_path = value_path(&args[0], env);/** tokenizes PATH*/
				status = _fork(args, argv, env, line, pathValue, is_path);
				if (status == 200)
				{
					free(line);
					return (0);
				}
				if (is_path == 0)
					free(args[0]);
			}
			free(args);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(line);
	}
	return (status);
}
