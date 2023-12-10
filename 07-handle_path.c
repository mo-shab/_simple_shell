#include "shell.h"

char *_getpath(char *array)
{
	char *path_envr, *cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; array[i]; i++)
	{
		if (array[i] == '/')
		{
			if (stat(array, &st) == 0)
				return (_strdup(array));
			return (NULL);
		}
	}
	path_envr = _getenv("PATH");
	if (!path_envr)
		return (NULL);
	dir = strtok(path_envr, ":");
	while (dir)
	{
		cmd = malloc(_strlen(dir) + _strlen(array) + 2);
		if (cmd)
		{
			_strcpy(cmd, dir);
			_strcat(cmd, "/");
			_strcat(cmd, array);
			if (stat(cmd, &st) == 0)
			{
				free(path_envr);
				return (cmd);
			}
			free(cmd), cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_envr);

	return (NULL);
}
