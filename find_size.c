#include "main.h"

/**
  *find_size - computes the size needed for casting the argument
  *
  *@format: The formatted string in which tp print arguments
  *@z: list of arguments to be printed
  *
  *Return: specific size
  */

int find_size(const char *format, int *z)
{
	int curr_z = *z + 1;
	int size = 0;

	if (format[curr_z] == 'l')
	{
		size = LONGS;
	}
	else if (format[ curr_z] == 'h')
	{
		size = SHORTS;
	}

	if (size == 0)
	{
		*z = curr_z - 1;
	}
	else
		*z = curr_z;

	return (size);
}
