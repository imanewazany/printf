#include "main.h"

int _putchar(char c);
void print_str(char *s);
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
 * Return: void
 */
void print_str(char *s)
{
	int i;

	i = 0;
	if (!s)
		return;
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
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
					{
						print_str(s);
					}
					else
					{
						return (-1);
					}
					i++;
					break;
				case 'c':
					a = va_arg(L, int);
					if (a)
					{
						_putchar(a);
					}
					else
					{
						return(-1);
					}
					i++;
					break;
				case '%':
					_putchar(format[i]);
					i++;
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
