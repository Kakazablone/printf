#include "main.h"
/*		PRINT POINTER		*/
/**
 * print_pointer - prints value of pointer variable
 * @form: list of args
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of char printed
 */
int print_pointer(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	char xtra_c = 0, padding = ' ';
	int index = BUFFSIZE - 2, length = 2, padding_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(form, void *);

	NOTUSED(width);
	NOTUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFFSIZE - 1] = '\0';
	NOTUSED(precision);
	num_address = (unsigned long)address;
	while (num_address > 0)
	{
		buffer[index--] = map_to[num_address % 16];
		num_address /= 16;
		lenght++;
	}
	if ((flags & ZERO_F) && !(flags & SUB_F))
		padding = '0';
	if (flags & ADD_F)
		xtra_c = '+', length++;
	else if (flags & BSPACE_F)
		xtra_c = ' ', length++;

	index++;
	/* return (write(1, &buffer[i], BUFFSIZE - i - 1));*/
	return (write_pointer(buffer, index, length, width, flags,
				padd, xtra_c, padding_start));
}
/*		PRINT A SRING IN ROT13		*/
/**
 * print_rot13string - print string in rot 13
 * @form: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Numbers of char printed
 */
int print_rot13string(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	char *str, c;
	unsigned int i, j;
	int count = 0;
	char entry[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char exit[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_args(form, char *);
	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	if (str == NULL)
		str = "(Nil)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; entry[j]; j++)
		{
			if (entry[j] == str[i])
			{
				c = exit[j];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!entry[j])
		{
			c = str[i];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
/*		PRINT REVERSE		*/
/**
 * print_reverse - prints reverse string
 * @form: list of arguments
 * @buffer: buffer array to handle
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Numbers of char printed
 */
int print_reverse(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	char *str;
	int i, count = 0;

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(size);

	str = va_arg(form, char *);
	if (str == NULL)
	{
		NOTUSED(precision);
		str = "(Null)";
	}
	for (i = 0; str[i]; i++)
	{
		for (i = i - 1; i >= 0; i--)
		{
			char z = str[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
/*		PRINT NON PRINTABLE		*/
/**
 * print_non_printable - prints ascii codes in hexad of non printable char
 * @form: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of char printed
 */
int print_non_printable(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(form, char *);

	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	if (str == NULL)
		return (write(1, "(NULL)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
