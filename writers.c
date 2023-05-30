#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_str - print string
 * @L: liste of parameters
 * Return: strlen of the printed String
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
 * @L: liste of parameters
 * Return: 1
 */
int print_char(va_list L)
{
	_putchar(va_arg(L, int));
	return (1);
}

/**
 * print_int - print %d and %i
 * @L: variadic list
 * Return: integer
 */
int print_int(va_list L)
{
	unsigned int div, i, resp, numc;
	int n;

	div = 1;
	numc = 0;
	n = va_arg(L, int);
	if (n < 0)
	{
		_putchar('-');
		numc++;
		n *= -1;
	}
	for (i = 0; n / div > 9; i++, div *= 10)
		;
	for (; div >= 1; n %= div, div /= 10, numc++)
	{
		resp = n / div;
		_putchar('0' + resp);
	}
	return (numc);
}
