#include "main.h"

/**
 * get_wid - Function that calculates the width for printing
 * @format: Formatted string
 * @i: input
 * @list: list of arguments.
 * Return: width
 */

int get_wid(const char *format, int *i, va_list arg)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
