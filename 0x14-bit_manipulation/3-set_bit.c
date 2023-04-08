#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1
 * @n: pointer to an unsigned long integer
 * @index: index of the bit to be set, starting from 0
 *
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1UL << index);
	return (1);
}

