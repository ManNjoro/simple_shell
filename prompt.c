#include "shell.h"
/**
 * print_prompt - prints the shell prompt
 * Return: void
 */
void print_prompt(void)
{
	char *cwd = _getcwd();
	char *prompt = NULL;

	if (!cwd)
		perror("getcwd");
	prompt = _strcat(cwd, " $ ");
	write(STDOUT_FILENO, prompt, _strlen(prompt));

	free(cwd);
}
