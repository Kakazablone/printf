#ifndef MAIN_H
#define MAIN_H
/* C standard library*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 1024
#define NOTUSED(x) (void)(x)

/* prototypes */
int _printf(const char *format, ...);

/**
 * struct fmt - structure operation
 * @fmt: the format
 * @fn: associated pointer function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - struct operation
 * @fmt: The format
 * @fmt_t: associated function
 */
typedef struct fmt fmt_t;

int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/* sizes */
#define SHORTS 1
#define LONGS 2

/* flags */
#define SUB_F 1
#define ADD_F 2
#define ZERO_F 4
#define HASH_F 8
#define BSPACE_F 16

/*		FUNCTIONS		*/

/* print numbers functions */
int print_int(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_binary(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);
/* print char and strings function */
int print_string(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_char(va_list form, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list form, char buffer[], int flags, int width,
		int precision, int size);

/* print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print non-printable char */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* handle other specifiers */
int find_size(const char *format, int *z);
int find_width(const char *format, int *i, va_list list);
int find_flags(const char *format, int *z);
int find_precision(const char *format, int *i, va_list list);

/* function to print string rot 13 */
int print_rot13string(va_list form, char buffer[], int flags,
		int width, int precision, int size);

/* function to print string in reverse */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* utilities */
int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_nonsgnd(unsigned long int num, int size);

#endif
