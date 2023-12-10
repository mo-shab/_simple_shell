#include "shell.h"

/**
* split - function that splits a string and return an
* array of each word of the string
* @buffer: the buffer string that
* @delim: the delimitar for fuction strtok
* Return: Array of string
*/

char **split(char *buffer, char *delim)
{
	char *tmp = NULL;
	char **arr = NULL;
	char *token = NULL;
	int word_count = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);
	tmp = _strdup(buffer);
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(buffer), buffer = NULL;
		return (NULL);
	}
	while (token)
	{
		word_count++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;
	arr = malloc((word_count + 1) * sizeof(char *));
	if (arr == NULL)
	{
		free(buffer), buffer = NULL;
		return (NULL);
	}
	token = strtok(buffer, delim);
	while (token)
	{
		arr[i] = _strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	arr[i] = NULL;
	free(buffer), buffer = NULL;

	return (arr);
}


