#include "main.h"
/* Calculatation of a precision using a finction */
/**
 * get_precision - Gets the precision for Display
 * @format: String  Formation using  arguments
 * @i: argument parameter for list.
 * @list: arguments list.
 *
 * Return: Get Precision.
 */
/* Functionto get precision using format and va_list */
int get_precision(const char *format, int *i, va_list list)
{
	/* start ight from next xter after '%' specifier*/
	int curr_i = *i + 1;
	/* -1,precision initialization. No precision */
	int precision = -1;
	/* ., Is next precision a dot, then No: precision */
	if (format[curr_i] != '.')
		return (precision);
	 /*Iniialization of the precision to zero */
	precision = 0;
	 /*Looping through string format to check value of precision */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		 /* Check current character if its a digit* */
		if (is_digit(format[curr_i]))
		{
		 /*Pecision set to zero */
			precision *= 10;
		 /*precision is not equal to current format */
			precision += format[curr_i] - '0';
		}
		 /*if current character resembles '*' get precision value */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			 /*Move past '*' character */
			precision = va_arg(list, int);
			 /*Get precision value */
			break;
			 /*Finish loop on finding the precision */
		}
		else
			break;
	}
	 /*is it a '*'|| digit, else break */

	*i = curr_i - 1;
	 /*subtract by 1 */
 /*return extracted precision value */
	return (precision);
	 /*End */
}
