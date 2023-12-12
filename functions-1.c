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
/**
 * print_error - Prints an error message to STDERR.
 * @name: The name of the program.
 * @cmd: The command that caused the error.
 * @i: The index associated with the error.
 */
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
/**
 * print_env - Prints the current environment variables to STDOUT.
 * @array: The array of arguments passed to the program.
 * @status: The exit status.
 */
void print_env(char **array, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	_free_array(array);
	*status = 0;
}
/**
 * exit_shell - Exits the shell with a given exit value.
 * @array: The array of arguments passed to the program.
 * @argv: The array of arguments passed to the program.
 * @status: The exit status.
 * @index: The index associated with the exit command.
 */
void exit_shell(char **array, char **argv, int *status, int index)
{
	int ex_val;
	char *idx, msg[] = ": exit: Illegal number: ";

	if (array[1] != NULL)
	{
		if (is_pos_n(array[1]))
			ex_val = _atoi(array[1]);
		else
		{
			idx = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, array[1], _strlen(array[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			_free_array(array);
			(*status) = 2;
			return;
		}
	}
	_free_array(array);
	exit(ex_val);
}
