#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFSIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	NOTUSED(width);
	NOTUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFSIZE - 1] = '\0';
	NOTUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & ZERO_F) && !(flags & SUB_F))
		padd = '0';
	if (flags & ADD_F)
		extra_c = '+', length++;
	else if (flags & BSPACE_F)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

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

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		NOTUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}



/***	ROT 13	**/
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

	str = va_arg(form, char *);
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
