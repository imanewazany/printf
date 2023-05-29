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

int print_int(va_list arg)
{
unsigned int divisor = 1, i, resp, charPrinted = 0;
int n = va_arg(arg, int);

	if (n < 0)
{	
	_putchar('-');
	charPrinted++;
	n *= -1;
	}
for (i = 0; n / divisor > 9; i++, divisor *= 10)
;

for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
{
	resp = n / divisor;
	_putchar('0' + resp);
}
return (charPrinted);
}
