#include "main.h"

/**
 * get_width - Outputs the total width
 * @format: string in which will be formatd.
 * @iargument lists
 * @list: argumen parameters
 *
 * Return: width.
 */
/*Function to calculate the width */
int get_width(const char *format, int *i, va_list list)
/* Variable initialization */
{
	int curr_i;
	/* tracks current position in the format */
	int width = 0;
	/*stores calculated width in variable */
	/*Loops through string format, right from index pointed */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/*Checks if current character is a digit */
		if (is_digit(format[curr_i]))
		{
		/* is it Digit, Calculates the width */	
		/* Build a No. from the digit assuming there is no leadind zero's*/	
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* Check if the current character is asteric*/
		else if (format[curr_i] == '*')
		{
			/* If asteric is found, it means it is specified as variable arg */
			/*va_arg width from variable argument */
			/* update width viariable with this value'*/
			curr_i++;
			/* Move to next character after asteric */
			width = va_arg(list, int);
			/*Exit loop after handle_print argument*/
			break;
		}
		/* update pointer i with last index value*/
		else
			break;
	}

	*i = curr_i - 1;
	/* Show calculated width */

	return (width);
}
