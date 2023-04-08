#include "main.h"

/**
 * get_bit_value - returns the value of a bit at a given index
 * @number: the number to search the bit in
 * @index: the index of the bit to get, starting from 0
 *
 * Return: the value of the bit at the given index, or -1 if an error occurred
 */
int get_bit_value(unsigned long int number, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((number >> index) & 1);
}

