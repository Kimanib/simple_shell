#include "shell.h"

/**
 * _erratoi - coverts a string to an integer
 * @s : the string to be converted
 * Return: 0 if no numbers in a strin, -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
			return (-1);
		}
	else
		return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containg error types
 * Return: 0 if no numbers and -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d -function prints a integer in base 10
 * @input: the input
 * @fd: the file desctiptor to write to
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		_putchar('-');
		count++;
	}
	else
		_abs_ = input;
		current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		 if (_abs_ / i)
		{
			_putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	_putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number -converter finctipn
 * @num: number
 * @base: base
 * @flags: arguments flags
 * Return: string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF"
	ptr = &bufer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - functionsreplaces first instance of '#' with '\e'
 * @buf: adress of the string to modify
 * Return: always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (bif[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
