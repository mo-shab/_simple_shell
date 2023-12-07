#include "shell.h"

/**
* main - main function
* @argc: argument count
* @argv: argument vector
*
* Return: 0
*/

int main(int argc, char **argv)
{

	pid_t child_pid;
	size_t buf_len = 1024;
	char *buffer = malloc(sizeof(char) * buf_len);
	char **array;
	char *delim = "\t\n";
	int status;

	while (1)
	{
		prompt(buffer, buf_len);
		array = split(buffer, delim);
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("Error with the Exceve");
		}
		else
			wait(&status);
		free(array);
	}
	free(buffer);

	return (0);
}

