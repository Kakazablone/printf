#include "main.h"

/**
 * is_printable - evaluates if char is printable
 * @c: char to be evaluated
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * is_digit - verifies if char is a digit
 * @c: char to  be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * append_hexa_code - append asccii in hexa code buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASSCI code
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * convert_size_number - Cast a number to the specified size
 * @num: number to be casted
 * @size: number indicating tyoe casted
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == LONGS)
		return (num);
	else if (size == SHORTS)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_nonsgnd - cast a number to specified size
 * @num: no to be casted
 * @size: no indicating the type to be casted
 * Return: casted value of num
 */
long int convert_size_nonsgnd(unsigned long int num, int size)
{
	if (size == LONGS)
		return (num);
	else if (size == SHORTS)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
