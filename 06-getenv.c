#include "shell.h"

/**
* _getenv - function that get the PATH
* @variable: The Path
* Return: NULL or the envirnement variable of PATH
*/

char *_getenv(char *variable)
{
	char *tmp, *key, *val, *envr;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			val = strtok(NULL, "\n");
			envr = _strdup(val);
			free(tmp);
			return (envr);
		}
		free(tmp), tmp = NULL;
	}

	return (NULL);
}

