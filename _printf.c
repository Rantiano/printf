#include "main.h"
#include <stdio.h>
#include <stdarg.h>
void print_buf(char buf[], int *buf_count);/**
 * my_printf - Function to print characters
 * my_printf: printf function name
 * @format: String format
 *
 * Return: Printed characters
 */
int my_printf(const char *format, ...)
{
int h, print = 0, print_me = 0;
int buff_index = 0;
int flags, width, size, precision;
char buffer[BUFF_SIZE];
if (format == NULL)
{
write(1, "This is an Errors !!", 20);
return (-1);
}
va_list args;
va_start(args, format);
for (h = 0; format[h] != '\0'; h++)
{
if (format[h] == '%')
{
h++;
if (format[h] == '%')
{
putchr('%');
print_me++;
}
else if (format[h] != '\0')
{
print_buf(buffer, buff_index);
flags = get_flags(format, &h);
width = get_width(format, &h, args);
precision = get_precision(format, &h, args);
size = get_size(format, &h);
handle_print(format, &h, args, buffer, &buff_index, flags,
width, precision, size, flags, precision,  width);
}
}
else
{
buffer[buff_index++] = format[h];
if (buff_index == BUFF_SIZE)
print_buf(buffer, &buff_index);
print_me++;
}
}
print_buf(buffer, &buff_index);
va_end(args);
return (print_me);
}
/**
 * print_buf - Prints contents found in the buffer
 * print_buf: prints buffer contents
 * @buf: Arrays of characters
 * @buf_count: represents length of buffer
 */
void print_buf(char buf[], int *buf_count)
{
if (*buf_count > 0)
write(1, &buf[0], *buf_count);
*buf_count = 0;
}
