#include <stdio.h>
#include "main.h"

/**
 * get_bit - prints digits
 *
 * Description: prints digits
 *
 * @n: integer to print
 * @index: index integer
 *
 * Return: return 1 or 0
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (n == 0 && index == 0)
		return (0);
	if (index > (8 * 8))
		return (-1);

	if (n & (1 << index))
		return (1);
	else
		return (0);
}
