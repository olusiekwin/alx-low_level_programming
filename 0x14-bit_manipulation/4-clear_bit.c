#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: unsigned long int
 * @index: unsigned int
 *
 * Return: 1 if it worked and -1 if not.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	x = sizeof(unsigned long int) * 8;
	if (index >= x)
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}
