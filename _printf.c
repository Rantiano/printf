#include "main.h"
/* Function that prints formated characters */
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Function for print file
 * @format: string formart
 * Return: Characters to be printed
 */
/*Function for printing a constant character*/
int _printf(const char *format, ...)
{
	/* variable dclaration */
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	/* RESET buffer to Null */
	if (format == NULL)
		return (-1);
	va_start(list, format);
	/*initialize i to 0 */
	for (i = 0; format && format[i] != '\0'; i++)
	{
		/*check if the character is %*/
		if (format[i] != '%')
		{
			/*increment the buffer index*/
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i],1);*/
			printed_chars++;
		}
		else
		{
		/* list of parameters and their respective types */
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
			flags, width, precision, size);
	/* checks if it returns */
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - outputs cntents in the buffer
 * @buffer: Characters of arrays
 * @buff_ind: shows length and place for next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
