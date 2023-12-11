#include "shell.h"

int is_pos_n(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

int _atoi(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		n *=10;
		n += (str[i] - '0');
	}

	return (n);
}

void exec_cd(char **argv)
{
	char *dir = argv[1], msg[] = "cd: No HOME directory found\n";
	int r;

	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			write(STDERR_FILENO, msg, _strlen(msg));
			return;
		}
	}

	r = chdir(dir);
	if (r == -1)
		perror("cd");
}
