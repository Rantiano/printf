#include "main.h"

/**
 * is_printable - Checks through the loop if character is printable
 * @c: xter for checking
 *
 * Return: 1 if c can be  printed, or else print 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1)

	return (0);
}

/**
 * append_hexa_code - Appends hexadecimal code of ASCII to buffer
 * @buffer: Characters in the array
 * @i: The start of appending in the index.
 * @ascii_code: Standard Code guidelines
 * Return: Always (3)
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa representation format code is always 2 in this format */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks whether digit is of type character
 * @c: This provides character to be checked
 *
 * Return: 1 is c really a digit, 0 Else
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Assign an integer to a constant size
 * @num: Integer for assignment
 * @size: Integer showing type to be casted.
 *
 * Return: Assigned Value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Assigns anumber to a constant size
 * @num: Integer for Assignment
 * @size:Integer showing type to be assigned
 *
 * Return: Assigned Value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
