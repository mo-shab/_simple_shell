#include "shell.h"
/**
 * _strdup - Duplicates a string.
 * @str: The string to be duplicated.
 *
 * Return: a duplication of str or NULL
 */
char *_strdup(const char *str)
{
	char *p;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len ; i++)
		p[i] = str[i];

	return (p);
}

/**
* _strcmp - function that compare two strings
* @s1: first string
* @s2: second string
* Return: 0 if s1 and s2 are equal
* negative value is s1 is less than s2
* positive value if s1 greater than s2
*/

int _strcmp(char *s1, char *s2)
{
	int dif = 0;
	int i;

	for (i = 0;  s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		dif = s1[i] - s2[i];
		if (dif != 0)
			return (dif);
	}

	return (dif);
}

/**
  * _strcpy - Copy a string
  * @dest: Destination value
  * @src: Source value
  *
  * Return: the pointer to dest
  */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i++] = '\0';

	return (dest);
}

/**
  * _strlen - function return lenght of string
  * @s: the string
  *
  * Return: len of a string
  */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}

/**
* _strcat - function appends the src to dest with \0 at the end
* @src: The char source
* @dest: the destination of the appends
*
* Return: a pointer to the result dest
*/
char *_strcat(char *dest, char *src)
{
	char *var = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (var);
}
