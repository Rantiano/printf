#include "main.h"

/**
 * get_size - Gets argument size
 * @format:  string format
 * @i: parametter
 * Return: Precision parameter.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	/*current arg incremental */
	int size = 0;
	/* size variable initialization */
	/* snoop through to check next character */
	if (format[curr_i] == 'l')
		size = S_LONG;
	/* S_LONG as the size */
	else if (format[curr_i] == 'h')
		/* S_SHORTas the size */
		size = S_SHORT;
	/* compares size to 0 */
	if (size == 0)
		*i = curr_i - 1;
	/* updates index argument */
	else
		*i = curr_i;
	/* Return determined size, Log or short */

	return (size);
	/* terminate here */
}
