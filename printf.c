#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _putchar - printfs one character
 *
 * @c: the character parameter of the character to be printed
 *
 * Return: Always return 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * NULL_test - test whether the value of our string literals is NULL
 *
 * @parameter_content: the string we want to check
 * @char_param_counter: pointer to number of characters in the string
 *
 * Return: Always return nothing
 */

void NULL_test(char *parameter_content, int *char_param_counter)
{
	if (parameter_content != NULL)
	{
		*char_param_counter += print_string(parameter_content);
	}
	else
	{
		parameter_content = "(null)";
		*char_param_counter += print_string(parameter_content);
	}
}

/**
 * test_null_char - test whether the value of our string literals is NULL
 *
 * @null_character: character we want to check
 * @char_param_counter: pointer to number of characters in the string
 *
 * Return: Always return nothing
 */

void test_null_char(char null_character, int *char_param_counter)
{
	if (null_character != 0)
	{
		_putchar(null_character);
	}
	else
	{
		*char_param_counter += print_string("") - 1;
	}
}

/**
 * print_string - prints contents of a string
 *
 * @parameter_content: the parameter that holds the string
 *
 * Return: returns the number of string characters
 */

int print_string(char *parameter_content)
{
	int char_param_counter = 0;

	while (parameter_content[char_param_counter] != '\0')
	{
		_putchar(parameter_content[char_param_counter]);
		char_param_counter++;
	}
	return (char_param_counter);
}
/**
 * _printf -prints out output to colsele using the specified format
 *
 * @format: the string that includes the specifiers
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int char_counter = 0;
	int char_param_ctr = 0;
	int len = 0;
	va_list parameter_list;

	if (format == NULL || parameter_list == NULL)
		return (-1);
	va_start(parameter_list, format);
	for (char_counter = 0; format && format[char_counter] != '\0'; char_counter++)
	{
		if (format[char_counter] != '%')
			_putchar(format[char_counter]);
		else
		{
			switch (format[char_counter + 1])
			{
				case 'c':
					test_null_char(va_arg(parameter_list, int), &char_param_ctr);
					char_counter++;
					len++;
					break;
				case 's':
					NULL_test(va_arg(parameter_list, char*), &char_param_ctr);
					char_counter++;
					len += 2;
					break;
				case '%':
					_putchar(format[char_counter]);
					char_counter++;
					format[char_counter + 1] != '%' ? len++ : (len += 2);
					break;
				default:
					_putchar(format[char_counter]);
					break;
			}
		}
	}
	va_end(parameter_list);
	return ((char_counter - len) + char_param_ctr);
}
