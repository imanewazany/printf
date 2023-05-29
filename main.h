#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * pstruct - printer strcuture
 * @ind: special character 
 * wtiter: writer function
 */
typedef struct pstruct
{
	char *ind;
	int (*writer)(va_list);
} pstruct;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list L);
int print_str(va_list L);

#endif
