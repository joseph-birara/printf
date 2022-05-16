#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: character to be printed
 *
 * Return: On success 1, otherwise -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
