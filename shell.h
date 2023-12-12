#ifndef SHELL_H
#define SHELL_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

char *_getline(void);
char **split(char *buffer, char *delim);
void _free_array(char **array);
int _exect(char **array, char **argv, int index);
char *_getenv(char *variable);
char *_getpath(char *array);

char *_itoa(int n);
void reverse_string(char *str, int len);
void print_error(char *name, char *cmd, int i);

char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);

void handle_built_in(char **array, char **argv, int *status, int index);
int is_built_in(char *array);
void print_env(char **array, int *status);
void exit_shell(char **array, char **argv, int *status, int index);

int is_pos_n(char *str);
int _atoi(char *str);

void exec_cd(char **argv);

#endif


