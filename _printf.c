#include "main.h"
/* prototype function */
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
	/* use this to check if the string format is NULL */
	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		/* Loop inside string formart */
		if (format[i] != '%')
		{
			/* If yoou dont find '%' print Error the
                       add it to the buffer */
			buffer[buff_ind++] = format[i];
			/* Is Buffer Full!? Display its contects 			and initialize the index of buffer */
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
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					       flags, width, precision, size);
			if (printed == -1)
				return (-1);
			/* Return all chars printed summed up */
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);
 	/* Terminate at this point */
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
/* This is function to print buffer contents */
	*buff_ind = 0;
/* Initializes Buffer index to 0 */
}
