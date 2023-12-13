#include "shell.h"
/**
 * is_built_in - Checks if a given command is a built-in command.
 * @array: The command to be checked.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
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
/**
 * handle_built_in - Handles execution of built-in commands.
 * @array: The array of arguments passed to the program.
 * @argv: The array of arguments passed to the program.
 * @status: The exit status.
 * @index: The index associated with the command.
 */
void handle_built_in(char **array, char **argv, int *status, int index)
{


	if (_strcmp(array[0], "exit") == 0)
		exit_shell(array, argv, status, index);
	else if (_strcmp(array[0], "env") == 0)
		print_env(array, status);
	else if (_strcmp(array[0], "cd") == 0)
		exec_cd(array);
}
