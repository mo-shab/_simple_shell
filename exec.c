#include "shell.h"
/**
 * _exect - Executes a command with arguments.
 * @array: Array of command and arguments.
 * @argv: Array of arguments passed to the program.
 * @index: Index of the current command in the command line.
 * Return: The exit status of the executed command.
 */
int _exect(char **array, char **argv, int index)
{
	char *fcmd;
	pid_t child_pid;
	int status;

	fcmd = _getpath(array[0]);
	if (fcmd == NULL)
	{
		print_error(argv[0], array[0], index);
		_free_array(array);
		return (127);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(fcmd, array, environ) == -1)
		{
			free(fcmd), fcmd = NULL;
			_free_array(array);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		_free_array(array);
		free(fcmd), fcmd = NULL;
	}
	return (WEXITSTATUS(status));
}
