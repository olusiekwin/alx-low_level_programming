#include "main.h"

/**
* binary_to_uint - converts a binary number to an unsigned int.
*
* @b: pointer to a string of 0 and 1 chars.
*
* Return: converted number, or 0 if b is NULL or contains chars -
*  other than 0, 1.
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int gramm = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		gramm <<= 1;
		if (*b++ == '1')
			gramm++;
	}

	return (gramm);
}
