#include "shell.h"

int is_built_in(char *array)
{
	char *built_ins[] = {
		"exit", "env", "setenv", "cd", "setenv", NULL
		};
	int i;

	for (i = 0; built_ins[i]; i++)
	{
		if (_strcmp(built_ins[i], array) == 0)
			return (1);
	}

	return (0);
}

void handle_built_in(char **array, char **argv, int *status, int index)
{


	if (_strcmp(array[0], "exit") == 0)
		exit_shell(array, argv, status, index);
	else if (_strcmp(array[0], "env") == 0)
		print_env(array, status);
	else if (_strcmp(array[0], "cd") == 0)
		exec_cd(array);
}
