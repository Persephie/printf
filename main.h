#ifndef PRINT_F
#define PRINT_F


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* Definitions of types */

typedef struct printer
{
	const char symbol;
	int (*func_t)(va_list);
} printer_t;

/* prototypes */

int _printf(const char *format, ...);
int print_string(char *parameter_content);
int _putchar(char c);
void NULL_test(char *parameter_content, int *char_param_counter);
int end_with_error(int error_number);
void test_null_char(char null_character, int *char_param_counter);
int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list arguments);
int print_string(va_list arguments);
int print_percent(__attribute__((unused))va_list arguments);
int print_i(va_list arguments);
int print_d(va_list arguments);
int (*get_flag_func(const char s))(va_list);
int print_integer(va_list arguments);
int print_decimal(va_list arguments);
int binary_recursive(unsigned int num, int len);
int print_binary(va_list arguments);
int print_unint(va_list arguments);
int print_octal(va_list args);
int rot13(va_list arguments);
char *_memcpy(char *dest, char *src, unsigned int n);
char *rev_str(char *s);
int print_reversed(va_list arg);
int (*func_t)(va_list);
#endif

