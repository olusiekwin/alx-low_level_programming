#include "main.h"


/**
 * flip_bits - returns the number of bits that need to be flipped to get from
 * one number to another
 * @numN: the first unsigned long integer input
 * @numM: the second unsigned long integer input
 *
 * Return: the number of bits that need to be flipped
 */

unsigned int flip_bits(unsigned long int numN, unsigned long int numM)
{
	unsigned long int xor_result = numN ^ numM;
	unsigned int count = 0;

	while (xor_result != 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}

