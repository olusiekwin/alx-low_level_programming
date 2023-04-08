#include <main.h>


/**
* flip_bits - counts the number of bits needed to be flipped to get
* from n to m
* @num1: first number
* @num2: second number
*
* Return: number of bits that need to be flipped
*/
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned long int bit_difference;
	unsigned int n_bits = 0;

	bit_difference = num1 ^ num2;

	while (bit_difference)
	{
		n_bits += bit_difference & 1;
		bit_difference >>= 1;
	}

	return (n_bits);
}

