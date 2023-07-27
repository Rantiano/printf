#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Prints a Printf function
 * @format: format for string.
 * Return: characters to be printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
<<<<<<< HEAD
	/* Loop inside string formart */
	if (format[i] != '%')
	{
	/* If yoou dont find '%' print Error the add it to the buffer */
	buffer[buff_ind++] = format[i];
	/* Is Buffer Full!? Display its contects and initialize the index of buffer */
	if (buff_ind == BUFF_SIZE)
	print_buffer(buffer, &buff_ind);
	/* write(1, &format[i], 1);*/
	printed_chars++;
	}
	else
	{
	/* Space holders incase there will be more code later to handle specifiers */
			/* Place it here '%' plus any other specifiers' */
			print_buffer(buffer, &buff_ind);
			/* If you find anything else inside the buffer, output it on the Terminal */
=======
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			rint_buffer(buffer, &buff_ind);
>>>>>>> e7f2664193ea8004fd6eadf580b2ffbeefc1bff5
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);
<<<<<<< HEAD
	/* Terminate at this point */
=======

>>>>>>> e7f2664193ea8004fd6eadf580b2ffbeefc1bff5
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
