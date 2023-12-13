#include "shell.h"
/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 * Return: A dynamically allocated string containing the converted integer.
 */
char *_itoa(int n)
{
	char buffer[30];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
/**
 * reverse_string - Reverses a string in-place.
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
	char temp;
	int s = 0, e = len - 1;

	while (s < e)
	{
		temp = str[s];
		str[s] = str[e];
		str[e] = temp;
		s++;
		e--;
	}
}
