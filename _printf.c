#include "main.h"
void print_mybuffer(char my_buffer[], int *buff_count);

/* my_printf -  prints printf function
 * @format: string format
 * @...: countless arguments
 * Return: Printed character`s
 */
int my_printf(const char *format, ...)
{
	int i, printed = 0, print_me = 0;
	va_list args;
	int flags, width, precision, size, buff_count = 0;
	char my_buffer[BUFF_SIZE];
if(format == NULL)
write(1, "This is an Error", 16);
return(-1);
	
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] != '%')
        {
	my_buffer[buff_count++] = format[i];
	if(buff_count == BUFF_SIZE)
	print_mybuffer(my_buffer, &buff_count);
	print_me++;
	}
	else
	{
	print_mybuffer(my_buffer, &buff_count);
	flags = get_flags(format, &i);
	width = get_width(format, &i, args);
	precision = get_precision(format, &i, args);
	size = get_size(format, &i);
	++i;
	printed = handle_print(format, &i, args, my_buffer, flags, width, precision, size);
	if(printed == -1)
	return (-1);
	print_me += printed;
	}
	}
	print_mybuffer(my_buffer, &buff_count);
	va_end(args);
	return (print_me);
	}
/** 
 * print_mybuffer - prints any contents in the buffer
 * @my_buffer: AArrays of Chars
 * @buff_count: Index which next char is added, also length.
 */
 void print_mybuffer(char my_buffer[], int *buff_count)
{
	if(*buff_count > 0)
		write(1, &my_buffer[0], *buff_count);
	*buff_count = 0;
}
