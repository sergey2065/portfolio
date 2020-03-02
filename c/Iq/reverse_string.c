#include <stdlib.h>

void Swap(char* a_first, char* a_second)\
{
    const char temp = *a_first;
    *a_first = *a_second;
    *a_second = temp;
}

void reverseString(char* a_str, int a_size)
{   size_t i;
    for(i = 0; i < a_size / 2; ++i)
    {
        Swap(a_str + i, a_str + a_size - 1 -i);
    }
}