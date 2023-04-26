#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if the strings are equal, -1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	if (s1[i] || s2[i])
		return (-1);

	return (0);
}

/**
 * _strncmp - compares two strings up to n bytes
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes to compare
 *
 * Return: 0 if the strings are equal up to n bytes, -1 otherwise
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}

	if (i != n && (s1[i] || s2[i]))
		return (-1);

	return (0);
}

/**
 * _strlen - Computes the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strdup - Duplicates a string in memory.
 * @str: The input string.
 *
 * Return: A pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *copy = malloc(len);

	if (copy == NULL)
		return (NULL);

	return ((char *) memcpy(copy, str, len));
}
