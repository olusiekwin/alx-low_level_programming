#include "main.h"

/**
 * get_endianness - checks the endianness of the system.
 *
 * Return: 0 if big_endian, 1 if little_endian.
 */

int get_endianness(void)
{
	int my_num = 1;
	char *endian = (char *)&my_num;

	if (*endian == 1) /* Checks if first byte is equal to 1 */
	{
		return (1); /* Little_endian */
	}
	else
	{
		return (0); /* Big_endian */
	}
}

