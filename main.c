#include "shell.h"

/**
* main - simple shell main function
* @argc: argument count
* @argv: argument vectors
*
* Return: 0.
*/

int main(int argc, char **argv)
{
	char *buffer = NULL;
	char **array = NULL;
	char *delim = " \t\n";
	int status = 0, index = 0;
	(void) argc;

	while (1)
	{
		buffer = _getline();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		array = split(buffer, delim);
		if (array == NULL)
			continue;

		if (is_built_in(array[0]))
		{
			handle_built_in(array, argv, status, index);
		}
		else
			status = _exect(array, argv, index);
	}

	free(buffer);
	return (0);
}
