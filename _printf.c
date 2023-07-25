#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
  *_printf - this is our print function
  *
  *@format: Pointer to the list of various formats
  *
  *Return: printed characters
  */

int _printf(const char *format, ...)
{
	int i, printed_chars = 0, output = 0;
	int flags, size, precision, width, buffer_index = 0;
	char buffer[BUFFSIZE];
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFSIZE)
			{
				print_buffer(buffer, &buff_index);
			}
			/* write(1, &format[i], 1) */
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = find_flags(format, &i);
			width = find_width(format, &i, list);
			precision = find_precision(format, &i, list);
			size = find_size(format, &i);
			++i;
			output = handle_print(format, &i, list, buffer, flags, width,
				precision, size);
			if (output == -1)
			{
				return (-1);
			}
			printed_chars = printed_chars + output;
		}
	}
	print_buffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}

/**
  *print_buffer - if the contents of a buffer exist then they are printed
  *
  *@buffer: string - an array of characters
  *@buff_index: represents the length and index at which to add the next char.
  */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
	{
		write(1, &buffer[0], *buff_index);
	}
	*buff_index = 0;
}
