#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/*Flags definition of xter reps.: - + 0 # ' ' */
	/*     -  -> 1 */
        /*     +  -> 2 */
        /*     0  -> 4 */
        /*     #  -> 8 */
        /*     ' '-> 16 */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
/* Characters representing the flags */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
/*integer values in correspondence with each flag*/
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

/* format string loop for printing next character*/	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			/* set correspondence when 0*/
			{
/* Ifa match is found, set the correspondence*/				flags |= FLAGS_ARR[j];
				break;
			}
/*When there is no match, stop*/
		if (FLAGS_CH[j] == 0)
			break;
	}
/* Output summed up flags */
	*i = curr_i - 1;

	return (flags);
}
