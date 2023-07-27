#include "main.h"
/**
 * handle_print - Determines output based on type
 * @fmt: String to be formatted
 * @list: argument list.
 * @ind: index
 * @buffer: Arrays of Buffer
 * @flag:  flags summation
 * @width:width size
 * @precision: Precision  parameter * @size: Size specifier
 * Return: 1 || 2
 */
/*Function of handling based on format specifier */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_hexa_upper},
		{'p', print_pointer},
		{'S', print_non_printable},
		{'r', print_reverse},
		{'R', print_rot13string},
		{'\0', NULL}
		/* Loop through 'fmt_types' upto the end of the string */
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	if (fmt[*ind] == fmt_types[i].fmt)
	return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	/*i, index variable */
	/*check if current character in 'fmt' matches any character */
	if (fmt_types[i].fmt == '\0')
	/*fn is called if a match is found */
	/*Return function call results */
	{
		if (fmt[*ind] == '\0')
			/*This indicates if there was an error */
			return (-1);
		/*case where '%' does not follow any format */
		unknow_len += write(1, "%%", 1);
		/*'%', not followed by any format space */

		if (fmt[*ind - 1] == ' ')
		unknow_len += write(1, " ", 1);
		else if (width)
		{
			/*width, is non-zero, specified width */
			--(*ind);
			/*if there is space befor '%' move index back once more */
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			/*character was printed successfully */
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
