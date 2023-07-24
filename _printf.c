#include "main.h"
void print_buf(char buf[], int *buf_count);

/**
 * my_printf - prints printf function
 * @format: string format
 * @...: countless arguments
 * Return: Printed characters
 */
int my_printf(const char *format, ...)
{
	int h, print = 0, print_me = 0;
	int flags, precision, size, width, buf_count = 0;
	va_list args;
	char buf[BUFF_SIZE];
	
	if (format == null)
		write(1, "This is an Error!!", 18);
	return (-1);

	va_start(args, format)

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')


	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[buf_count++] = format[i];
			if (buf_count == BUFF_SIZE)
				print_buf(buf, &buf_count);
			/* write(1, &format[i], 1);*/
			print_me++;
		}
		else
		{
			print_buf(buf, &buf_count);
			flags = get_flags(format, &h);
			width = get_width(format, &h, args);
			precision = get_precision(format, &h, args);
			size = get_size(format, &h);
			++h;
			print = handle_print(format, &h, args, buf,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_me += print;
		}
	}

	print_buf(buf, &buf_count);

	va_end(args);

	return (print_me);
}

/**
 * print_buf - Prints the contents of the buffer if it exist
 * @buf: Array of chars
 * @buf_count: Index at which to add next char, represents the length.
 */
void print_buf(char buf[], int *buf_count)
{
	if (*buf_count > 0)
		write(1, &buf[0], *buf_count);

	*buf_count = 0;
}

