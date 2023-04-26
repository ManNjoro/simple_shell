#include "shell.h"
/**
 * split_line - splits a line into tokens
 * @line: the line to split
 * Return: a pointer to an array of tokens
 */
char **split_line(char *line)
{
	char **tokens = NULL;

	tokens = tokenize(line, " \t\r\n\a");

	return (tokens);
}

