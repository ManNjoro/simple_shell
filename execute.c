#include "shell.h"

/**
 * execute - executes a command with arguments
 * @args: the command-line arguments
 *
 * Return: 1 on success, -1 on failure
 */

int execute(char **args)
{
	int status;
	int (*builtin)(char **args);

	if (args[0] == NULL)
	{
		return (1);
	}

	builtin = get_builtin(args[0]);

	if (builtin)
	{
		status = (*builtin)(args);
	}
	else
	{
		status = launch(args);
	}

	return (status);
}

/**
 * launch - launches a non-built-in command
 * @args: the command and its arguments
 * Return: 0 on success, 1 on failure
 */
int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 *execute_builtin - executes a built-in command with arguments
 *@builtin: the function pointer for the built-in command
 *@args: the command-line arguments
 *Return: the return value of the built-in command function
*/
int execute_builtin(int (*builtin)(char **args), char **args)
{
	return (builtin(args));
}
