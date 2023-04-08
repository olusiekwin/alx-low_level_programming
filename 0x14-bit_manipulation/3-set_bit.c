#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the value of bit to 1.
 * @o: pointer to the unsigned long integer.
 * @index: index of the bit being set, starting from 0.
 *
 * Return: 1 upon success, -1 upon failure.
 */
int set_bit(unsigned long int *o, unsigned int gramm)
{
	if (gramm >= sizeof(unsigned long int) * 8)
		return (-1);

	*o |= (1UL << gramm);
	return (1);
}

