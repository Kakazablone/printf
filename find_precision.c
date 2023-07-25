#include "main.h"

/**
 * find_precision - calculates the precision printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments printed
 * @list: list of arguments
 * Return: precision
 */
int find_precision(const char *format, int *i, va_list list)
{
	int index = *i + 1;
	int precision = -1;

	if (format[index] != '.')
		return (precision);

	precision = 0;
	for (index += 1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			precision *= 10;
			precision += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = index - 1;
	return (precision);
}
