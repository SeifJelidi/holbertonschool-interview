#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>

/**
* is_palindrome : checking if a number is a palindrome
* @n: the input number
* Return : 1 if the number is a palindrome , otherwise 0 
*/
int is_palindrome(unsigned long n)
{
    unsigned long num, ts = 0;
    num = n;

    while (num > 0)
    {
        ts *= 10;
        ts += num % 10;
        num /= 10;
    }
    if (n == ts)
        return 1;

    return 0;
}
