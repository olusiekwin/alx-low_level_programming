#include "main.h"
#include <stdio.h>

/**
 * flip_bits - returns the number os bits
 * @n: unsigned long int
 * @m: unssigned long int
 *
 * Return: number of bytes that need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int y = 0;
	unsigned long int res;

	res = n ^ m;

	while (res)
	{
		y += res & 1;
		res >>= 1;
	}

	return (y);
}
