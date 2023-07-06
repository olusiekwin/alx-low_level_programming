#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: pointer
 *
 * Return: converted number else 0.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int x = 0;
	int i;

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		x = x << 1;
		x += b[i] - '0';
	}
	return (x);
}
