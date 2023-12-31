#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * @fmt: The format
 * @fn: The function associated
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;

int ur_printf(const char *format, ...);
int handle_prnt(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_percnt(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int toprint_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octals(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimals(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_isupper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int toprint_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int toprint_non_prntable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int prnt_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_wid(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int prnt_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int my_handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int towrite_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int my_write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int to_write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
<<<<<<< HEAD
int is_printable(char);
=======

/****************** UTILS ******************/
int tis_printable(char);
>>>>>>> 88d96013c5e63ae5a2577eaa1047e67ebbbc2afc
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
