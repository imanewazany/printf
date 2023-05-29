#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_str - print strind
 * @s: String to print
 * Return: strlen of s
 */
int print_str(va_list L)
{
	char *s;
	int i;

	i = 0;
	s = va_arg(L, char *);
	if (!s)
		return (0);
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * print_char - print a character
 * @c: the charcter to print
 * @Return: 1 in success, 0 in fails
 */
int print_char(va_list L)
{
	_putchar(va_arg(L, int));
	return (1);
}
