#include "main.h"
/*===================PRINT HEXX NUM IN LOWER OR UPPER =====================*/
/**
 * print_hexa - Function that prints number in lower || upper
 * @types: argument lists
 * @map_to: values
 * @buffer: for handling prints
 * @flags: sum of flags
 * @flag_ch: active flags
 * @width: gets width
 * @precision: parameter
 * @size: size parameter
 * Return: characters to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	/*UNSIGNED LONG INT NUM = VA_ARG(TYPES, UNSIGNED LONG INT);*/
	/* UNSIGNED LONG INT INIT_NUM */
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	/*unsigned variable declaration*/

	UNUSED(width);
	/* to avoid compiler warnings of unused variable*/
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	/* checks if buffer is at '0'*/
	buffer[BUFF_SIZE - 1] = '\0';
	/* gkjhjsjakjhjdj */
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
		/*tjhagdhgsfdsadfgjhgdhsh*/
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	/*ushisdidhasdgsdjsdfgh*/
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*==================PRINT UNSIGNED NUMBER IN HEXADECIMAL ==========*/
/**
 * print_hexadecimal - unsigned hexadecimal notation
 * @: argument list
 * @buffer: Arrays to handle print
 * @size: specifier
 * @width: get width
 * @precision: parameter
 * @types: parameter
 * @flags: parameter
 * Return: characters to be printed
 */
/* Function to handle print*/
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
			flags, 'x', width, precision, size));
	/* gdjahjdjhsdskfjhjfhsjfkjh */
}
/*================ PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ===========*/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	/*output in upper hexadecimal notation*/
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/*==========================* PRINT UNSIGNED NUMBER =======================*/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
	/*Variable declaration to be used in this function*/
{
	/*Variable initialization*/
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	/*num initialization*/
	if (num == 0)
	buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*=====================PRINT UNSIGNED NUMBER IN OCTAL =====================*/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 * @i: integer
 */
/*sjahfkhkfhSAHGADJADJ*/
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	/*variable declaration*/
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
/*jhjdsajHGFGSAKJLD*/
	UNUSED(width);
	UNUSED(init_num);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	num = convert_size_unsgnd(num, size);
	/*check num*/
	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
	buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
	}


