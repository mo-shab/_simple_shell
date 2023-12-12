#include "shell.h"
/**
 * is_pos_n - Checks if a string represents a positive integer.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a positive integer, 0 otherwise.
 */
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
/**
 * _atoi - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}
/**
 * exec_cd - Changes the current working directory.
 * @argv: The array of arguments passed to the program.
 */
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
