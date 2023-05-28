#include "main.h"

int _putchar(char c);
int print_str(char *s);
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	if (!c)
		return (-1);
	return (write(1, &c, 1));
}

/**
 * print_str - print strind
 * @s: String to print
 * Return: strlen of s
 */ 
int print_str(char *s)
{
	int i;

	i = 0;
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
 * _printf - produces output according to a format
 * @format: character string
 * Return: the number of characters printed
 *	(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int numc, i, a;
	va_list L;
	char *s;

	va_start(L, format);
	i = 0;
	numc = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			switch (format[i + 1])
			{
				case 's':
					s = va_arg(L, char *);
					if (s)
						numc = numc + print_str(s);
					i++;
					break;
				case 'c':
					a = va_arg(L, int);
					_putchar(a);
					numc++;
					i++;
					break;
				case '%':
					_putchar(format[i]);
					numc++;
					i++;
					break;
				default :
					_putchar(format[i]);
					numc++;
					break;
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
