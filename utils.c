#include "main.h"

/**
 * is_printable - Checks through the loop if actually a character can be printed.
 * @c: xter for checking
 *
 * Return: 1 if c can be  printed, or else print 0.
 */
int is_printable(char c)
{
	/* If the character falls within ASCII range printable xters */
	if (c >= 32 && c < 127)
		return (1); /* Yes, the character is printable */

	return (0); /* No the character is not printable */
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
	/* The hexadecmal representation format code is always 2 	  in this format */
	/* Sum up hexadecimal representation of ASCII numbers */
	if (ascii_code < 0) 
	/*Get first 4 ASCII numnbers and determine corresponding 	hexa xter*/
	ascii_code *= -1; 
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	 /*Get first 4 ASCII numnbers and determine corresponding        hexa xter*/
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	 /*Get first 4 ASCII numnbers and determine corresponding        hexa xter*/
	return (3);
	/*Return lenth of appende hexa*/
}
/**
 * is_digit - Checks whether digit is of type character
 * @c: This provides character to be checked
 *
 * Return: 1 is c really a digit, 0 Else
 */
int is_digit(char c)
/* Check if xter is in range of 0 - 9 (ASCII Codes)*/
{
	if (c >= '0' && c <= '9')
		return (1); /*Returns success: Is Digit */

	return (0); /* Returns 0: Is not Digit */
}

/**
 * convert_size_number - Assign an integer to a constant size
 * @num: Integer for assignment
 * @size: Integer showing type to be casted.
 *
 * Return: Assigned Value
 */
long int convert_size_number(long int num, int size)
/* Function for size conversion */
{
	if (size == S_LONG)
/* Checking if size arg determines target data set */		return (num);
	else if (size == S_SHORT)
/*Returns value as number */
	return ((short)num);

/*Default scenario:Assigned value 'num' as a digit */
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
/* Function that checks size arg to establish if it targets the data */
{
	/* Argument to determine the targhet data for assignment */
	if (size == S_LONG)
		return (num); /* Prints a number */
	else if (size == S_SHORT)
		return ((unsigned short)num); /*Prints num as an unsigned short integer */

	return ((unsigned int)num);
	/*  Case Default - Assigned number as an unsigned integer */
}
