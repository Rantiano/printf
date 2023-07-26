#include "main.h"

/*======================== PRINT A STRING ========================*/
/**
 * print_string - Function for printing string characters
 * @types: arguments typres
 * @buffer: Arrays to a Buffer for  handling print
 * @flags: present flags
 * @width: total width
 * @precision: Precision parametr
 * @size: specifier for size
 * Return: Number of characters printable
 */
int print_string(va_list types, char buffer[],
/*Function to print a string with formatting options */
	int flags, int width, int precision, int size)
{
	/*initializes length to zero */
	int length = 0, i;
	char *str = va_arg(types, char *);
	/*Retrieves next arg as a character to a pointer */
/*Marking variables as unused to avoid warnings */
	UNUSED(buffer);
	/*buffer parameter */
	UNUSED(flags);
	   /* Flags parameter */
	UNUSED(width);
	   /* width parameter */
	UNUSED(precision);
	   /* precision parameter */
	UNUSED(size);
	   /* size parametr */
	/* Checks if the arg is NULL */
	if (str == NULL) /* When it is NULL set default value for str */
	{
		str = "(null)";
		/* String prints NULL  */
		if (precision >= 6)
			/*If precision is high, string should be replaced */
			str = "      ";
	}
/*Sums up string length */
	while (str[length] != '\0')
		length++;
/* Limits length string to a specified precision */
	if (precision >= 0 && precision < length)
		length = precision;
	/* Lenght equals precision 
	 *  Option to Handle width formatting */

	if (width > length)
	{
		/*Left justifiable checker */
		if (flags & F_MINUS)
		{
			/*when left justified - print flag as set */
			write(1, &str[0], length);
			/*when left justified - print flag as first */
			for (i = width - length; i > 0; i--)
				/* Pad rest of characters with spaces */
				write(1, " ", 1);
			return (width);
			/* Function terminates here or else loop continues */
		}
		else
		{
		/* If not left_justified, mpad beginning of line */
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
		/*Then print following string */
			write(1, &str[0], length);
			return (width);
		/* Function o return width */
		}
	}
/* If width is not greater than the length of the string, simply print the string
    // The function should return the number of characters written */
	return (write(1, str, length));
}
/************************* PRINT CHAR *************************/

/**
 * print_char - XTER prin
 * @types:  arguments
 * @buffer:Arrays to Buffer 
 * @flags: Curect flags
 * @width: Width
 * @precision: Parameter
 * @size: Size of buffer
 * Return: xters for printing
 */
int print_char(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        char c = va_arg(types, int);

        return (handle_write_char(c, buffer, flags, width, precision, size));
}

/* ======================== PRINT INT ======================== */
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
		/* Function fr printing integer */
	int flags, int width, int precision, int size)
	/*Declaring variables */
{
	/*Initializing variables */
	int i = BUFF_SIZE - 2;
	/*First index for inserting digits in buffer */
	int is_negative = 0;
	/* Determines if number is neg */
	long int n = va_arg(types, long int);
	/* int argument from va_list  */
	unsigned long int num;
	/* variable to store absolute int value  */
	n = convert_size_number(n, size);
	/* convert no. based on size specified */

	if (n == 0)
		buffer[i--] = '0';
	/* store zero in a buffer  */
/* IF NULL, TERMINATE BUFFER */
	buffer[BUFF_SIZE - 1] = '\0';
	/* number takes its absolute value */
	num = (unsigned long int)n;
/*Is number negative  */
	if (n < 0)
		/*compares negative and zero  */
	{
		num = (unsigned long int)((-1) * n);
		/*Get last number and change to character  */
		is_negative = 1;/*go to the next digit  */
	}
/*Extract last digit using modulo operand  */
	/*convert its character reps  */
	/*store xter in buffer  */
	/* remove last digit */
	while (num > 0)
	{
	/*variable i decremented  */		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
/*incremented  */
	i++;
/*after loop i points to last valid index  */
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
/* function passes value to index  */
	/* returns if value is negative */
}

/*========================  PRINT PERCENT SIGN ======================== */
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
/* function that prints percentage */
	int flags, int width, int precision, int size)
/* variable declaration */
{
	 UNUSED(types);
	  /*types parameter */
	UNUSED(buffer);
        /*buffer parameter */
        UNUSED(flags);
           /* Flags parameter */
        UNUSED(width);
           /* width parameter */
        UNUSED(precision);
           /* precision parameter */
        UNUSED(size);
           /* size parametr */
        /* returns 1 */
        return (write(1, "%%", 1));
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
/* function that pints binary */
		int flags, int width, int precision, int size)
/* variable declaration */
{
/* variable declaration */
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

 	UNUSED(buffer);
        /*buffer parameter */
        UNUSED(flags);
           /* Flags parameter */
        UNUSED(width);
           /* width parameter */
        UNUSED(precision);
           /* precision parameter */
        UNUSED(size);
           /* size parametr */

	/*  Variable arg generates next arg */	
	n = va_arg(types, unsigned int);
	/*initializes m to the number with the most significant bit  */
	m = 2147483648; /* (2 ^ 31) */
/* calculate representation of n and store *
 */
	a[0] = n / m;
	/* binaru store in [0] */
	for (i = 1; i < 32; i++)
	{
/* Devide n by m */
		m /= 2;
		/* store the result 0 or 1 in a[i]  */		a[i] = (n / m) % 2;
/*Print binary rep of n to the std output  */
/*Loop iterates through array from most important to least important  */
/*sum keeps track of cumulutive sum of binary numbers  */
/* counts number of binary numbers */	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];/*calcs cumulative sum of binary digits  */
		/* binary presentation printed */
		if (sum || i == 31)
		{
			/*convert all binary to its correct value  */
			char z = '0' + a[i];
/* write xter to std output */
			write(1, &z, 1);
			count++;
			/* increment character count */
		}
	}
	return (count);/* return total sum of xters printed in length */
}
