#include "main.h"

/*======================* PRINT POINTER *===================*/
/**
 * print_pointer - prints pointer value
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
/*Print a pointer to addres in hexa format */
/*take arg list for pointer container address */
/*buffer for storing hexa representation */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/*Define constant for buffer size */
	/*formats for pointer rep initialized */
	char extra_c = 0, padd = ' ';
	/*No extra character */
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	/*stores pointer address */
	char map_to[] = "0123456789abcdef";
	/*Array for hexa xters */
	void *addrs = va_arg(types, void *);
/*Unused Macros */
	UNUSED(width);
/*not used in specific code snippet */	
	UNUSED(size);
/*determine whether pointer address is null */
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
/*if null, directly store the string NULL */
	buffer[BUFF_SIZE - 1] = '\0';
	/*Null terminator at the end inorder to terminate string  */
	UNUSED(precision);    /*Archived for future use  */

	num_addrs = (unsigned long)addrs;    /*pointer address  */

	while (num_addrs > 0)
		   /* conversion of pointer to hexa rep and store in the buffer  */
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		   /*No devided by 16  */
		length++;
		   /*length increments to sum number of xters  */
	}   /*check for additional formating flags*/

	if ((flags & F_ZERO) && !(flags & F_MINUS))    /*If zero flag is et to minus, Flag not set */
		padd = '0';
	if (flags & F_PLUS)
		   /*change xter to output then increment  */
		extra_c = '+', length++;
	   /* increment then move it to correct position */
	else if (flags & F_SPACE)
		   /*call write pointer to handle final formating */
		extra_c = ' ', length++;
	   /*takes buffer the starting inde length of the rep  */

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
/*Function for formatting and printing non-printable characters of a string */
/*Variable arg list type of string pointer */
/*buffer: stores formatted string */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
/*variable initialization */{
	int i = 0, offset = 0;/*string inpu initialization */
	char *str = va_arg(types, char *);
	/*hexa handler */
/*Macro: to avoid compiler warnings of unused variables */
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	/*If NULL, return null to the output */

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			/*run program till it terminates at null */
			buffer[i + offset] = str[i];/*copy printable character to output */
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		/*move to the next string */
/*Iteration of i */
		i++;
	}
/*buffer offsets at 0 */
	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
