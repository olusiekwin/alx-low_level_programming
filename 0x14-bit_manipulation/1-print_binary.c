#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_binary - prints binary representation of a number
 * @n: unisgned int
 *
 */
void print_binary(unsigned long int n)
{
	size_t i;
	unsigned long int x;
	size_t bite = sizeof(unsigned long int) * 8;


	x = 1UL << (bite - 1);

	for (i = 0; i < bite; i++)
	{
		if (n & x)
			putchar('1');
		else
			putchar('0');
		x >>= 1;
	}
}

