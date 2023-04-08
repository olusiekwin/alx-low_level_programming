#include "main.h"

/**
 * get_bit_value - Gets the value of the bit at a given index.
 * @digit: The number to search the bit in.
 * @index: The index of the bit.
 *
 * Return: The value of the bit at the given index or -1 if an error occurred.
 */
int get_bit_value(unsigned long int digit, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((digit >> index) & 1);
}

