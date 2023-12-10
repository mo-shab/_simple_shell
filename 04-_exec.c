#include "shell.h"

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
		if(execve(fcmd, array, environ) == -1)
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
