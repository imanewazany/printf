#include "main.h"

int print_format(va_list L, char f);

/**
 * print_format - print argument according a specific formating
 * @L: va_list
 * @f: caracter to handel
 * Return: number of printed caracter
 **/
int print_format(va_list L, char f)
{
	int i;
	pstruct pr[] = {
		{"s", print_str},
		{"c", print_char},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	for (i = 0; pr[i].ind != NULL; i++)
	{
		if (pr[i].ind[0] == f)
			return (pr[i].writer(L));
	}
	return (0);
}

/**
 * help_print - help printing
 * @s1: character
 * @s2: character
 * Return: num of printed characters
 */
int help_print(char s1, char s2, va_list L)
{
	int s;

	if (s2 == '%')
	{
		_putchar(s1);
		return (1);
	}
	s = print_format(L, s2);
	if (s == 0)
	{
		_putchar(s1);
		_putchar(s2);
		return (2);
	}
	return (s);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters printed
 *	(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int numc, i;
	va_list L;

	va_start(L, format);
	i = 0;
	numc = 0;
	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			numc = numc + help_print(format[i], format[i + 1], L);
			i++;
		}
		else
		{
			_putchar(format[i]);
			numc++;
		}
		i++;
	}
	va_end(L);
	return (numc);
}
