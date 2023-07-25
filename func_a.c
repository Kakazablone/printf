#include "main.h"

/**FUNCTION TO PRINT UNSIGNED NUMBER IN HEX**/

/**
  *print_hexad - uses the hexadecimal notation to print unsigned number
  *
  *@buffer: temporary array to handle print
  *@width: finds the width
  *@precision: specifies the precision
  *@size: specifies the size
  *@flags: will calculate active flags
  *@form: provides the list of arguements
  *
  *Return: the number of characters printed
  */

int print_hexad(va_list form, char buffer[], int flags, int width, int size,
		int precision)
{
	return (print_hexad_u_l(form, "0123456789abcdef", buffer, flags, 'x',
				width, precision, size));
}

/**FUNCTION TO PRINT UNSIGNED NUMBER IN UPPER HEX**/

/**
  *print_hexad_up - uses the hexadecimal notation to print an unsigned
  *number in upper hexadecimal notation
  *
  *@form: will provide the list of arguments
  *@flags: will calculate active flags
  *@width: find the width
  *@size: specify the size required
  *@precision: specifies the precision
  *@buffer: temporary array to handle print
  *
  *Return: number of characters printed
  */

int print_hexad_up(va_list form, char buffer[], int width, int flags, int size,
		int precision)
{
	return (print_hexad_u_l(form, "0123456789ABCDEF", buffer, flags, 'X',
				width, precision, size));
}

/**FUNCTION TO PRINT A HEXADECIMAL NUMBER IN UPPER OR LOWERCASE**/

/**
  *print_hexad_u_l - will print a hexadecimal number in lower or upper
  *
  *@form: provides the list of arguments to be used
  *@buffer: temporary array to handle print
  *@map_to_num: provides array of values to map the number to
  *@flags: calculate the active flags
  *@width: will find the width
  *@precision: specifies the precision
  *@size: specifies the size required
  *@flag_n: calculates active flags
  *@size: size specifier
  *
  *Return: printed characters number
  */

int print_hexad_u_l(va_list form, char map_to_num[], char buffer[], int flags,
		char flag_n, int width, int precision, int size)
{
	int i = BUFFSIZE - 2;
	unsigned long int num = va_arg(form, unsigned long int);
	unsigned long int start_num = num;

	NOTUSED(width);

	num = convert_size_nonsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFFSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to_num[num % 16];
		num = num / 16;
	}

	if (flags & HASH_F && start_num != 0)
	{
		buffer[i--] = flag_n;
		buffer[i--] = '0';
	}
	i++;

	return (write_nonsgnd(0, i, buffer, flags, width, precision, size));
}

/**FUNCTION TO PRINT AN UNSIGNED NUMBER**/

/**
  *print_unsigned - will print an unsigned number
  *
  *@form: will provide the list of arguments
  *@buffer: temporary array to handle print
  *@flags: calculate active flags
  *@width: specify the width
  *@precision: gives specific precision
  *@size: is a size specifier
  *
  *Return: number of printed chars
  */

int print_unsigned(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFFSIZE - 2;
	unsigned long int num = va_arg(form, unsigned long int);

	num = convert_size_nonsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}
	i++;

	return (write_nonsgnd(0, i, buffer, flags, width, precision, size));
}

/**FUNCTION TO PRINT AN UNSIGNED NUMBER IN OCTAL**/

/**
  *print_octal - will print an unsigned number in octal notation
  *
  *@form: provides the list of arguments
  *@buffer: a temporary array to handle print
  *@flags: populates active flags
  *@width: gets the width
  *@precision: specifies the precision
  *@size: gets the specific size
  *
  *Return: number of printed chars
  */

int print_octal(va_list form, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFFSIZE - 2;
	unsigned long int num = va_arg(form, unsigned long int);
	unsigned long int start_num = num;

	NOTUSED(width);

	num = convert_size_nonsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num = num / 8;
	}

	if (flags & HASH_F && start_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_nonsgnd(0, i, buffer, flags, width, precision, size));
}
