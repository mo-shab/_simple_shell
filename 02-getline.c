#include "shell.h"

/**
* _getline - function get line from terminal
* Return: line or NULL if CTR + D is detected
*/

char *_getline(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t eof;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	eof = getline(&buffer, &len, stdin);
	if (eof == -1)
	{
		free(buffer);
		return (NULL);
	}

	return (buffer);
}
