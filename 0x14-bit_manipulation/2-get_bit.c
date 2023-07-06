#include "main.h"
#include <stdio.h>
/**
 * get_bit - function that returns value at a given index
 *@n: unsigned long int
 *@index: unsigned int
 *
 * Return: value of bit given
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int x_bits;
	unsigned long int y;
	unsigned long int result;

	x_bits = sizeof(unsigned long int) * 8;

	if (index >= x_bits)
		return (-1);

	y = 1UL << index;

	result = (n & y);

	if (result != 0)
		return (1);
	else
		return (0);
}
