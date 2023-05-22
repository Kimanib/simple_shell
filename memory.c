#include "shell.h"

/**
 * bfree - frees a pointer and NULLS the address
 * @ptr: addres of the pointer to free
 * 
 * Return: 1 if fred, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr)
		* ptr = NULL;
		return (1);
	}
	return (0);
}
