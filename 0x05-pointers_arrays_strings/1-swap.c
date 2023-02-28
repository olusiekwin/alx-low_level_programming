#include "main.h"
/***
 * swap_int - swaps the va;lue of an int a and b
 * olusiekwin
 * @a: first int
 * @b: second int
 * return 0
 */

void swap_int(int *a, int *b)
{
    int s;

    s = *a;
    *a = *b;
    *b = s;
}
