#include "main.h"

/**
  *find_flags - calculates active flags
  *
  *@format: Is the formatted string where arguments should be printed
  *@z: this is a pointer that takes a parameter
  *
  *Return: Flags
  */

int find_flags(const char *format, int *z)
{
	/**** 1 2 4 8 16 ****/
	/**** - + 0 # '' ****/

	int f, curr_z;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {SUB_F, ADD_F, ZERO_F, HASH_F, BSPACE_F, 0};

	for (curr_z = *z + 1; format[curr_z] != '\0'; curr_z++)
	{
		for (f = 0; FLAGS_CH[f] != '\0'; f++)
		{
			if (format[curr_z] == FLAGS_CH[f])
			{
				flags |= FLAGS_ARR[f];
				break;
			}
		}
		if (FLAGS_CH[f] == 0)
			break;
	}
	*z = curr_z - 1;

	return (flags);
}
