#include "main.h"

/**FUNCTIONS TO WRITE NUMBER TO THE STD OUTPUT**/

/**
  *write_nonsgnd - This function writes an unsigned number
  *
  *@index: represents the index at which the number starts in the buffer
  *@is_negative: inicates a negative number
  *@buffer: temporary array to handle print
  *@flags: populates the active flags
  *@width: specifies the width
  *@precision: specifies the precision
  *@size: fetches the specific size
  *
  *Return: Number of characters written
  */

int write_nonsgnd(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFFSIZE - index - 1, i = 0;
	/**
	  *the number will start at position i & will be stored a
	  *the buffer's right
	  */

	char padding = ' ';

	NOTUSED(is_negative);
	NOTUSED(size);

	if (precision == 0 && ind == BUFFSIZE - 2 && buffer[index] == '0')
		return (0);/* printf(".0d", 0)no char is printed[buffer > pad*/

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & ZERO_F) && !(flags & SUB_F))
		padding = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding;
		if (flags & SUB_F)/* assign extra char to left of buffer*/
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		else/* assign extra char to the left of padding[pad > buffer]*/
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
	}
	return (write(1, &buffer[index], length));
}

/**
  *write_pointer - this will write a memory adress
  *
  *@padd_start: the index at which padding starts
  *@xtra_c: repesents an ectra char
  *@index: the index at which number starts in the buffer
  *@padding: the char representing the padding
  *@buffer: a temporary array of chars
  *@length: the length of number
  *@width: specifies width
  *@flags: calculates active flags
  *
  *Return: number of written characters
  */

int write_pointer(char buffer[], int index, int length, int width, int flags,
		char padding, char xtra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padding;
		buffer[i] = '\0';
		if (flags & SUB_F && padding == ' ')/*assign extra char to left of buffer*/
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (xtra_c)
				buffer[--index] = xtra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & SUB_F) && padding == ' ')/*xtra char to left of buffer*/
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (xtra_c)
				buffer[--index] = xtra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & SUB_F) && padding == '0')/*assign char 2 left of padding*/
		{
			if (xtra_c)
				buffer[--padd_start] = xtra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) + write
					(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (xtra_c)
		buffer[--index] = xtra_c;

	return (write(1, &buffer[index], BUFFSIZE - index - 1));
}

/**
  *write_number - will print a string
  *
  *@index: char types
  *@is_negative: list
  *@buffer: temporary array to handle print
  *@flags: populate active flags
  *@width: get width
  *@precision: specifies precision
  *@size: size specifier
  *
  *Return: number of chars printed
  */

int write_number(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFFSIZE - index - 1;
	char padd = ' ', xtra_c = 0;

		NOTUSED(size);

		if ((flags & ZERO_F) && !(flags & SUB_F))
			padd = '0';
		if (is_negative)
			xtra_c = '-';
		else if (flags & ADD_F)
			xtra_c = '+';
		else if (flags & BSPACE_F)
			xtra_c = ' ';

		return (write_num(index, buffer, flags, width, precision,
					length, padd, xtra_c));
}

/**
  *write_num - will write a number using buffer
  *
  *@index: the index at which the number start on tghe buffer
  *@buffer: array of char for print
  *@flags: calculates active flags
  *@width: gets width
  *@precision: specifies precision
  *@length: length of number
  *@padd : padding char
  *@extra_c: provides extra char
  *
  *Return: printed chars
  */
int write_num(int index, char buffer[], int flags, int width,
		int precision, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFFSIZE - 2 && buffer[index]
			== '0' && width == 0)
		return (0);/*printf(".0d", 0)no char is printed*/
	if (precision == 0 && index == BUFFSIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';/*width is displayed with padding' '*/
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & SUB_F && padd == ' ')/*assign xtra char 2 left of buffer*/
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		else if (!(flags && SUB_F) && padd == ' ')/*xtra char to left of buffer*/
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & SUB_F) && padd == '0')/*xtra char 2 the left of padd*/
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) + write
					(1, &buffer_index, length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[index] = extra_c;
	return (write(1, &buffer[index], length));
}

/**
  *write_my_char - this function will print a string
  *
  *@c: char types
  *@buffer: temporary array of characters to handle print
  *@flags: populates active flags
  *@width: fetch the width
  *@precision: specifies precision
  *@size: size specifier
  *
  *Return: printed  chars count
  */

int write_my_char(char c, char buffer[], int flags, int width, int precision,
		int size)
{
	/*char is stored on the left & padding at buffer's right*/

	int i = 0;
	char padd = ' ';

	NOTUSED(precision);
	NOTUSED(size);

	if (flags & ZERO_F)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFSIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFSIZE - i - 2] = padd;

		if (flags & SUB_F)
			return (write(1, &buffer[0], 1) + write
					(1, &buffer[BUFFSIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFSIZE - i - 1], width - 1)
					+ write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
