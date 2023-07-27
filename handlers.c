#include "main.h"

/*=====================* WRITE HANDLE *=====================*/
/* 
 * handle_write_char - function to write a char
 * @c:a type of  char
 * @buffer: Arrays to a Buffer
 * @flags:  Summation of current flags.
 * @width: width parametr
 * @precision: precision parameter
 * @size: specifier to get the size
 *
 * Return:total characters to be printed
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	/*i, initialization */
	char padd = ' ';
	 /*padding ic checked */
/*Variables that have not been used to avoid warnings from the compiler */
	UNUSED(precision);
	UNUSED(size);
/*update character after checking if F is zero */
	if (flags & F_ZERO)
		padd = '0';
/*parameter c is stored in the buffer as an array */
	buffer[i++] = c;
	buffer[i] = '\0';
	/*Marks end of string indicated by a Null-terminator */
/*perfom width formatting if it is greater than 1 */
	if (width > 1)
	{
		/* padd, Loops through buffer to check padding xter */
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			/*check if F_MINUS is set */
			buffer[BUFF_SIZE - i - 2] = padd;
		/*writing result of the first character */

		if (flags & F_MINUS)
			/*check first character of buffer and return its value */
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			/*Return result of padded part of the first parameter */
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
		/* return buffer size */
	}
/*width is less than or equal to 1, return result of writing only */
	return (write(1, &buffer[0], 1));
}

/*===========================* WRITE NUMBER ===========================*/
/**
 * write_number - outputs a string
 * @is_negative: arguments types
 * @ind: types of characters.
 * @buffer: Arrays to  Buffer 
 * @flags: Get current flags
 * @width: calculate width
 * @precision: precision parameter
 * @size: specifier
 *
 * Return: characters that have been printed.
 */
/*Function that writes number of character to buffer with specified format */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	/*Get max buffer length */
	int length = BUFF_SIZE - ind - 1;
	/*Initialize padding character as space and extra */
	char padd = ' ', extra_ch = 0;
/*Macro indicates size that the parameter is not Used */
	UNUSED(size);
/*This marks that size parametr is UNUSED */
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	/*Is F_ZERO, flag is set and F_MINUS */
	/* If flag is set, set extra character as '+' */
	if (is_negative)
		/*set extra if number is negative */
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	/* '', is set if the character is extra */
	else if (flags & F_SPACE)
		extra_ch = ' ';
/*write num, function with provide parameters
 * Find, at the start of buffer index
 * buffer, writes number into buffer
 * flags, width, precision and formatting 
 * padd, formating for the padding character
 * extra_ch, additional character representation*/
	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
/*Returns all the parameters */
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
/* Function that writes a number of characters in a buffer with formatting options */
/*Takes several parameters as listed below */	
	int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
/*Parameters
 * int ind: Buffer indexing
 * char buffer: placeholder for the number
 * int flags: Control that provides formatting options
 * int width: minimum width of output
 * int prec: number of digits after output
 * int length: Actual length of number to be written
 * char padd: character used forpadding
 * char extr_c: calcuated length*/
{
	int i, padd_start = 1;
/*When precision is 0, index is at buffer's end
 * and when width is zero, the no character to be printed so value to be dispalyed is 0
 */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
/*If precision is equal to 0, index is at the end of buffer */
/*update buffer to display width with padding as ' '*/		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
/*Is precision greater than 0 and less than lentgh, set padd to '  ' */	
	while (prec > length)
		buffer[--ind] = '0', length++;
	/*If there's an extra character, increment the length */
	if (extra_c != 0)
		length++;
	/*If there is an extra character, increment the legth */
	if (width > length)
	/*Additional formatting for when width is greater than lenth */
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		/*Fill buffer with padd character upto specification */
		buffer[i] = '\0';
		/*Null terminator to buffer */
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			/*place 'extra_c' at left indentation */
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		/*Display legth characters starting from index */}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			/*place extra_c at the left most position */
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		/*output character starting from index for legth parameter */
		}
		else if (!(flags & F_MINUS) && padd == '0')
			/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
	/*place 'extra_c' at the top most position */
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		 /*output characters before length and characters before index i */ 
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	 /* place 'extra_c' at the top most position */ 
	return (write(1, &buffer[ind], length));
 /*write characters 'pad_start' then write length */ 
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
