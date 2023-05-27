#include "main.h"

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
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[i + 1])
			{
				case 's':
					printf("%s", va_arg(L, char *));
					break;
				case 'c':
					printf("%c", va_arg(L, int));
					break;
			}
		}
		else
		{
			printf("%c", format[i]);
			numc++;
		}
		i++;
	}
	va_end(L);
	return (numc);
}
