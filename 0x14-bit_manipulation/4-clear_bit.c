#include "main.h"

/**
* clear_bit - set to 0 the bit value at a given index
* @num_ptr: pointer to the integer to modify
* @bit_index: index of the bit to clear
* Return: 1 on success, -1 on failure
*/
int clear_bit(unsigned long int *num_ptr, unsigned int bit_index)
{
if (bit_index >= sizeof(unsigned long int) * 8)
return (-1);

*num_ptr &= ~(1 << bit_index);

return (1);
}

