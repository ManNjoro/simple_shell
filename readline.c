#include "shell.h"
/**
 * read_line - reads a line from stdin
 * Return: a pointer to the line, or NULL on failure
 */
char *read_line(void)
{
	size_t bufsize = 0;
	char *line = NULL;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		perror("getline");
		return (NULL);
	}

	return (line);
}

