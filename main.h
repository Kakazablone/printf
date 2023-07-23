#ifndef MAIN_H
#define MAIN_H
/* C standard library*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFZISE 1024
#define NOTUSED(x) (void)(x)

/* prototypes */
int _printf(const char *format, ...);

/**
 * struct frmt - structure operation
 * @frmt: the format
 * @func: associated pointer function
 */
struct frmt
{
	char frmt;
	int (*func)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct frmt frmt_t - struct operation
 * @frmt: The format
 * @frm_t: associated function
 */
typedef struct frmt frmt_t;
int handle_print(const char *frmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);

/* sizes */
#define SHORTS 1
#define LONGS 2

/* flags */
#define SUB_F 1
#define ADD_F 2
#define ZER0_F 4
#define HASH_F 8
#define BSPACE_F 16

/*		FUNCTIONS		*/

/* print numbers functions */
int print_int(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int write_unsgnd(int is_negative, int ind,
		char buffer[],
			int flags, int width, int precision, int size);
int print_unsigned(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_binary(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_octal(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_hexad(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_hexad_u_l(va_list form, char map_to_sum[], char buffer[], int flags,
		char flag_n, int width, int precision, int size);
int print_hexad_up(va_list form, char buffer[], int flags,
		int width, int precision, int size);

/* print char and strings function */
int print_string(va_list form, char buffer[], int flags,
		int width, int precision, int size);
int print_char(va_list form, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list form, char buffer[], int flags, int width,
		int precision, int size);

/* print memory address */
int print_pointer(va_list form, char buffer[], int flags, int width,
		int precision, int size);

/* print non-printable char */
int print_non_printable(va_list form, char buffer[], int flags,
		int width, int precision, int size);

/* handle other specifiers */
int find_size(const char *format, int *i);
int find_width(const char *format, int *i, va_list list);
int find_flags(const char *format, int *i);
int find_precision(const char *format, int *i, va_list list);

/* function to print string rot 13 */
int print_rot13string(va_list form, char buffer[], int flags,
		int width, int precision, int size);

/* function to print string in reverse */
int print_reverse(va_list form, char buffer[], int flags,
		int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_num(int index, char buf[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_number(int is_positive, int index, char buffer[], int flags,
		int width, int precision, int size);
int write_pointer(char buffer[], int index, int length, int width, int flags,
char padd, char extra_c, int padd_start);
int write_nonsgnd(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size);

/* utilities */
int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_nonsgnd(unsigned long int num, int size);

#endif
