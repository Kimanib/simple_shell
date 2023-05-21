#include "shell.h"

/**
 * _strlen- returns the lenght of the string
 * @s: the string whose length to check
 * Return: integer value of the length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs comparision of 2 strings
 * @s1: first string
 * @s2: second string
 * Return: negative is s1 < S2 , positive if s2 < s1 and zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (s1 != s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: substrings to files
 * Return: adress to the next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
		return ((char *)haystack);
}

/**
 * _strcat- concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: points to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++
	while (*src)
		*dest++ = src++;
	*dest = *src;
	return (ret);
}
