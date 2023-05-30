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
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters printed
 *	(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int numc, i, s;
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
			if (format[i + 1] == '%')
			{
			_putchar(format[i]);
				numc++;
				i++;
			}
			else
			{
				s = print_format(L, format[i + 1]);
				if (s == 0)
				{
					_putchar(format[i]);
					numc++;
				}
				else
				{
					numc = numc + s;
					i++;
				}
			}
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
