#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * struct print - structure for printing various data types
 * @t: data type to be printed
 * @f: function to print
 */
typedef struct formatspecifier
{
	char *x;
	int (*func)(va_list);
} formater_t;

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_func(const char *format))(va_list);
char *create_buffer(void);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_decimal(va_list d);
int print_unsigned(va_list u);
int print_b(va_list b);
int print_octal(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list R);
int print_percent(va_list P);

#endif 
