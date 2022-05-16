#include "main.h"
#include <stdlib.h>

/**
 * get_func - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
int (*get_func(const char *format))(va_list)
{
        unsigned int i;
        formater_t type[] = {
                {"c", print_char},
                {"s", print_string},
                {"i", print_int},
                {"d", print_decimal},
                {"u", print_unsigned},
                {"b", print_b},
                {"o", print_octal},
                {"x", print_x},
                {"X", print_X},
                {"p", print_p},
                {"S", print_S},
                {"r", print_r},
                {"R", print_R},
                {"%", print_percent},
                {NULL, NULL}
        };

        i = 0;
        while (type[i].t[0])
        {
                if (type[i].t[0] == *format)
                {
                        break;
                }
                i++;
        }
        return (type[i].func);
}

/**
 * _printf - function that imitates the printf function
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list arg;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = get_func(&format[i + 1]);
		if (f != NULL)
		{
			count += f(arg);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		while (format[i + 1])
		{
			if (format[i + 1] == '%')
			{
				f = get_func(&format[i + i]);
				break;
			}
			i++;
		}
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(arg);
	return (count);
}
