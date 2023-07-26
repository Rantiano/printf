#include "main.h"

/*=========================* PRINT UNSIGNED NUMBER *=========================*/
/**
 * print_unsigned - function
 * @types: arguments types
 * @buffer: Arrays to handle print
 * @flags: Sum 
 * @width: get width
 * @precision: First paarameter
 * @size: total length
 * Return: characters for ptinting
 */
int print_unsigned(va_list types, char buffer[],
		/* use of formatting options and variable aarg & declaration */
	int flags, int width, int precision, int size)
 /*Define max buffer size  */
{
	int i = BUFF_SIZE - 2;
 /* Retrieve next arg from variable list */
	unsigned long int num = va_arg(types, unsigned long int);
 /*convert value based on specified size  */
	num = convert_size_unsgnd(num, size);
 /*When value be zero, decrement bffer  */
	if (num == 0)
		buffer[i--] = '0';
 /*set last digit to null  */
	buffer[BUFF_SIZE - 1] = '\0';
 /* Extracts digits of number one by one and store them in buffer */
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		 /* index points first digit of number in buffer */
		num /= 10;
	}

	i++;
	 /*returns un_asigne formatted number */
	 /*Write returned characater value  */

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*============================ PRINT UNSIGNED NUMBER IN OCTAL===================*/
/**
 * print_octal - Function to print octal value
 * @types: args types
 * @buffer: Arrays to Buffer
 * @flags: Summation sof flags
 * @width: width
 * @precision: Precision parameter
 * @size: Size specifier of octal
 * Return: characters for printing
 */
/*unasigned int value print function */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
/* formatin options & variable args */
{
/* Determine max buffer size */

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
/* Next argument from list arg goten */
	unsigned long int init_num = num;
/* Unused variable kept for futer */
	UNUSED(width);
/*blocks compiler warnings  */
	num = convert_size_unsgnd(num, size);
/*Decrementing when buffer is 0  */
	if (num == 0)
		buffer[i--] = '0';
			/* Get lastcharacters */

	buffer[BUFF_SIZE - 1] = '\0';
	/* buffer initialization */
/*NULL Terminator for last char  */
	while (num > 0)
		/* Extract octal digits and store one by one */
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
/*flag in format string  */
	/*buffer indicated octal representation  */
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;
/*return formatted number asa null terminator  */
	/*start from index 0  */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*================* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL *================*/
/**
 * print_hexa_upper - function fo hexadecimal upper
 * @types: args
 * @buffer:Arrays to  Buffer 
 * @flags: summation of flags
 * @width: get width
 * @precision: Precision parameter
 * @size: Size 
 * Return: characters for printing
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	/* function for hexadevcimal upper */
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}/* returns hexa values */
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - function for hexadecimal notation
 * @types: args
 * @buffer: Arrays of Buffer
 * @flags:  summation flags
 * @width: get width
 * @precision: Precision parameter 
 * @size: Size specification
 * Return: characters for printing */
int print_hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
	/*function for hexadecimal notation */
{
        return (print_hexa(types, "0123456789abcdef", buffer,
                flags, 'x', width, precision, size));
	/* returns and outputs hexa notation numbers */
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
/* Function that converts unsigned int to hexa rep.s */
/* Takes 2 arg variables */
/8 character mapping array for hexa xaters */
{
	int i = BUFF_SIZE - 2;
/* Defines buffer size */
	unsigned long int num = va_arg(types, unsigned long int);
/* Extration of unsign long int */	unsigned long int init_num = num;

	UNUSED(width); /* archived for later use */

	num = convert_size_unsgnd(num, size);
	/* Null terminator added to end of buffer*/

	if (num == 0)
		buffer[i--] = '0';
	/* apply specified size converstion on the number */

	buffer[BUFF_SIZE - 1] = '\0';
/*null terminator at end of buffer */
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		/* get rem devide by 16*/
		num /= 16;
	}
/*initial no not 0 as flag is initialized */
	if (flags & F_HASH && init_num != 0)
/*flag is specified */	{
		buffer[i--] = flag_ch;
	/*decremental of buffer */ 	
		buffer[i--] = '0';
		/* hexadecimanl number */ 
	}
/*incremental of the index */ 
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
/*right function called *
 * No of chars to write plus other format options
 * output destination file*/ 
}
