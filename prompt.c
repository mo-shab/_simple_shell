#include "shell.h"

/**
* prompt - function that print $
* @buffer: string to store bufffer from stdin
* @buf_len: size of the buffre
* Return: Nothng
*/

void prompt(char *buffer, size_t buf_len)
{

	write(1, "#cisfun$ ", 9);
	getline(&buffer, &buf_len, stdin);
}

