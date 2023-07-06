#include <stdio.h>
#include "main.h"

/**
 * get_endianness - prints digits
 *
 * Description: prints digits
 *
 * Return: return 1 or 0
 */
int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 0x76543210;
	c = (char *) &x;

	if (*c == 0x10)
		return (1);
	else
		return (0);
}
