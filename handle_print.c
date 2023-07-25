#include "main.h"

/**
  *handle_print - will print an argument based on its type.
  *@frmt: the formated string in which 2 print arguments
  *@index: the index
  *@list: containing the list of arguments to be printed
  *@buffer: temporary array to handle print
  *@flags: populates active flags
  *@width: fetches the specific width
  *@precision: specifies parameter
  *@size: gets specific size
  *Return: 1 or 2
  */

int handle_print(const char *frmt, int *index, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, undef_length = 0, printed_chars = -1;
	frmt_t frmt_types[] = {
		{'c', print_char}, {'\0', NULL}, {'s', print_string},
		{'r', print_reverse}, {'b', print_binary}, {'i', print_int},
		{'X', print_hexad_up}, {'p', print_pointer},
		{'u', print_unsigned}, {'x', print_hexad}, {'o', print_octal},
		{'%', print_percent}, {'R', print_rot13string},
		{'S', print_non_printable}, {'d', print_int}
	};
	for (i = 0; frmt_types[i].frmt != '\0'; i++)
	{
		if (frmt[*index] == frmt_types[i].frmt)
			return (frmt_types[i].func(list, buffer, flags, width, precision, size));

		if (frmt_types[i].frmt == '\0')
		{
			if (frmt[*index] == '\0')
				return (-1);
			undef_length = undef_length + write(1, "%%", 1);
			if (frmt[*index - 1] == ' ')
				undef_length = undef_length + write(1, " ", 1);
			else if (width)
			{
				--(*index);
				while (frmt[*index] != ' ' && frmt[*index] != '%')
				{
					--(*index);
					if (frmt[*index] == ' ')
						--(*index);
					return (1);
				}
			}
			undef_length = undef_length + write(1, &frmt[*index], 1);
			return (undef_length);
		}
	}
	return (printed_chars);
}
