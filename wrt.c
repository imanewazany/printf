#include "main.h"

/**
 * print_uToBin - the unsigned int argument is converted to binary
 * @L: variadic list
 * Retrun: num of printed character
 */
int print_uToBin(va_list L)
{
	unsigned int n;
	unsigned int numc;

	n = va_arg(L, unsigned int);
	print_bin(n, &numc);
	print_bin(n, &numc);
	return (numc);
}

/**
 * print_bin - print binary 
 * @n: unsigned integer
 * @numc: integer
 * Return: void
 */
void print_bin(unsigned int n, unsigned int *numc)
{
	if (n > 1)
	{
		*numc += 1;
		print_bin(n >> 1, numc);
	}
	_putchar((n & 1) + '0');
}
