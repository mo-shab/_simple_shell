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
	char *str = malloc(strlen(buffer) + 1);
	char **arr;
	char *token;
	int word_count = 0;
	int i = 0;

	strcpy(str, buffer);
	token = strtok(str, delim);
	while (token)
	{
		word_count++;
		token = strtok(NULL, delim);
	}
	arr = malloc((word_count + 1) * sizeof(char *));
	if (arr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(str, buffer);
	token = strtok(str, delim);
	while (token)
	{
		arr[i] = malloc(strlen(token) + 1);
		if (arr[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(arr[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	arr[word_count] = NULL;
	free(str);

	return (arr);
}


