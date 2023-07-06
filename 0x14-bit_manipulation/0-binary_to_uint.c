#include "main.h"

/**
 * string_length - function retruns the length of a string
 *
 * Description: function returns the length of a string
 *
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Return: size of string
 */
int string_length(const char *b)
{
	int index, string_length;

	string_length = 0;
	if (b == 0)
		return (string_length);
	for (index = 0; b[index]; index++)
		string_length++;
	return (string_length);
}

/**
 * power - function that returns the exponential power
 *
 * Description: function that returns the exponential power
 *
 * @base: base integer
 * @exponent: exponential integer
 *
 * Return: unsigned integer
 */
unsigned int power(int base, int exponent)
{
	unsigned int total;

	total = 1;
	if (base < 0)
		return (0);
	if (exponent == 0)
		return (total);
	while (exponent > 0)
	{
		total *= base;
		exponent--;
	}
	return (total);
}

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 *
 * Description: function that converts a binary number to an unsigned int
 *
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Return: unsigned number or 0 is not valid
 */
unsigned int binary_to_uint(const char *b)
{
	int binary_string_position, binary_string_length;
	unsigned int total;

	total = 0;
	binary_string_length = string_length(b) - 1;

	if (b == 0)
		return (0);

	for (binary_string_position = binary_string_length;
			binary_string_position >= 0;
			binary_string_position--)
	{
		if (b[binary_string_position] == '1')
		{
			total += power(2, (binary_string_length - binary_string_position));
		}
		else if (b[binary_string_position] != '0'
				&& b[binary_string_position] != '1')
		{
			return (0);
		}
	}
	return (total);
}
