#include <stdio.h>
#include "main.h"

/**
 * flip_bits - prints digits
 *
 * Description: prints digits
 *
 * @n: integer to print
 * @m: index integer
 *
 * Return: return 1 or 0
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int difference;

	difference = 0;
	while (m > 0 || n > 0)
	{
		if ((n & 1) != (m & 1))
		{
			difference++;
		}

		m >>= 1;
		n >>= 1;
	}

	return (difference);
}
