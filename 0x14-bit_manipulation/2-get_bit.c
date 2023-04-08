#include "main.h"

/**
* get_bit - get the bit value at a given index
* @numbers: unsigned long integer
* @indexs: unsigned integer
*
* Return: the value of the bit at the given index, or -1 if an error occurred
*/
int get_bit(unsigned long int numbers, unsigned int indexs)
{
if (indexs >= sizeof(unsigned long int) * 8)
return (-1);

return ((numbers >> indexs) & 1);
}
