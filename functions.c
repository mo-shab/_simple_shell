#include "shell.h"

/**
* _free_array - function that free array
* @array: the array to be freed
* Return: Nothing
*/

void _free_array(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
}


void print_error(char *name, char *cmd, int i)
{
	char *index;
	char msg[] = ": not found\n";

	index = _itoa(i);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(index);
}

void print_env(char **array, int status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	_free_array(array);
}

void exit_shell(char **array, int status)
{
	_free_array(array);
	exit(status);
}
