#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	char *s;
	char c;

	c = 'w';
	s = "String";
	len = _printf("Let's try to printf a simple sentence. %%s\n");
	len2 = printf("Let's try to printf a simple sentence. %%s\n");
	printf("_printf => %d\nprintf => %d\n", len, len2);
	_printf("_printf => %c\n", c);
	_printf("_printf => %s\n", s);
	_printf("_printf => %c, %%, %s\n", c, s);
	_printf("%%s");
	len2 = _printf("\n");
	printf("%d\n", len2);
	len = _printf("aaaa%bbbb");
	printf("%d\n", len);
	len  = printf("\n");
	printf("%d", len);
	printf("\n");
	return (0);
}
