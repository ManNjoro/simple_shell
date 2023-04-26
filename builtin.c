#include "shell.h"

/**
 * get_builtin - gets the function pointer for a built-in command
 * @cmd: the command name
 *
 * Return: a pointer to the function for the command, NULL if not found
 */

int (*get_builtin(char *cmd))(char **args)
{
	int i;

	builtin builtins[] = {
		{"exit", shell_exit},
		{"cd", shell_cd},
		{NULL, NULL}
	};
	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(cmd, builtins[i].name) == 0)
			return (builtins[i].func);
	}

	return (NULL);
}

/**
 * shell_exit - exits the shell
 * @args: ...
 *
 * Return: 0 to signal to exit the shell
 */
int shell_exit(char **args)
{
	(void)args;

	return (0);
}

/**
 * shell_cd - changes the current directory
 * @args: the command-line arguments
 *
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char **args)
{
	if (args[1])
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{
		chdir(getenv("HOME"));
	}

	return (0);
}
