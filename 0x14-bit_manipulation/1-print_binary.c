#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @numry: The number to be printed in binary.
 */
void print_binary(unsigned long int numry)
{
	if (numry > 1)
		print_binary(numry >> 1);

	_putchar((numry & 1) + '0');
}

