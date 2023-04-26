#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

void env_init(char **env);
void add_var(char *str);
int set_var(char *name, char *value);
void print_prompt(void);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
char **tokenize(char *str, char *delim);
int launch(char **args);
size_t _strlen(const char *str);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_getcwd(void);
int shell_exit(char **args);
int shell_cd(char **args);
int (*get_builtin(char *cmd))(char **args);
char *_getenv(char *name);
void free_tokens(char **tokens);


/* Global variables */
extern char **environ;
extern char *shell_name;
extern char *shell_version;
extern char **shell_builtins;
extern int (*shell_builtin_funcs[])(char **);
extern int shell_num_builtins;

/**
 * struct built - struct type
 * @name : pointer to a string that represents the name of the built-in command
 * @func : function pointer
 */
typedef struct built
{
	char *name;
	int (*func)(char **args);
} builtin;
#endif

