#include "shell.h"

/**
 * tokenize - splits a string into tokens
 * @str: the string to split
 * @delim: the delimiters to split the string by
 *
 * Return: a pointer to an array of tokens
 */
char **tokenize(char *str, char *delim)
{
	#define MAX_TOKENS 64

	char **tokens = NULL;
	char *token = NULL;
	int pos = 0, bufsize = MAX_TOKENS;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += MAX_TOKENS;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delim);
	}

	tokens[pos] = NULL;
	return (tokens);
}
/**
 * _getcwd - gets the current working directory
 *
 * Return: a pointer to a string containing the current working directory
 */
char *_getcwd(void)
{
	char *cwd = NULL;
	size_t size = 64;

	do {
		cwd = realloc(cwd, size);
		if (!cwd)
		{
			perror("realloc");
			return (NULL);
		}

		if (getcwd(cwd, size) != NULL)
			return (cwd);

		size *= 2;
	} while (errno == ERANGE);

	perror("getcwd");
	free(cwd);
	return (NULL);
}

/**
 * free_tokens - Frees an array of strings
 * @tokens: The array of strings to be freed
 *
 * Return: void
 */
void free_tokens(char **tokens)
{
	size_t i = 0;

	if (!tokens)
		return;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}
