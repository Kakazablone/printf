#include "main.h"

/*		PRINT CHAR		*/

/**
 * print_char - Print a char
 * @form: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifications
 * @size: size specifier
 * Return: number of char printed
 */
int print_char(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = va_arg(form, int);

	return (write_my_char(c, buffer, flags, width, precision, size));
}

/*		PRINT A STRING		*/

/**
 * print_string - print a string
 * @form: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precicision specification
 * @size: number of strings printed
 * Return: number of char printed
 */
int print_string(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	int i, length = 0;
	char *str = va_arg(form, char *);

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[lenght] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & SUB_F)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/*		PRINT PERCENT SIGN		*/
/**
 * print_percent - print a percent sign
 * @form: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars to be printed
 */
int print_percent(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	NOTUSED(form);
	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);
	return (write(1, "%%", 1));
}
/*		PRINT INT		*/
/**
 * print_int - Print int
 * @form: list arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of char to be printed
 */
int print_int(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	int is_negative = 0;
	int i = BUFFSIZE - 2;
	long int n = va_arg(form, long int);
	unsigned long int num;

	n = convert_size_number(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFFSIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_numbers(is_negative, i, buffer, flags, width, precision, size));
}
/*		PRINT BINARY		*/
/**
 * print_binary - prints an unsigned number
 * @form: list arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */
int print_binary(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	int count;
	unsigned int n, m, i, sum;
	unsigned int a[32];

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	n = va_arg(form, unsigned int);
	m = 2147483648; /*(2 ^ 31)*/
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
