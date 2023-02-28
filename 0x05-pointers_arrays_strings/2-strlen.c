#include "main.h"
/***
 * _strlen - string length always return the length of a string
 * olusiekwin
 * @s: char to be checked
 * Description:- this will always check for the length of a string
 * Retern: 0 if success
 * */

int _strlen(char *s)
{
    int a = 0;

    for (; *s++;)
            a++;
    return (a);
}