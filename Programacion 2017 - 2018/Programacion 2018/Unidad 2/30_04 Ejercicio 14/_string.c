#include <stdio.h>
#include <stdlib.h>
#include "_string.h"

char toupper_(char c)
{
    if(c>='a' && c<='z')
    {
        return (c-32);
    }
    return c;
}

size_t strlen_(const char* cad)
{
    size_t l = 0;
    while(*cad)
    {
        l++;
        cad++;
    }
    return l;
}

int strcmpi_(const char* cad1, const char* cad2)
{
    size_t l1 = strlen_(cad1);
    size_t l2 = strlen_(cad2);
    if(l1<l2)
    {
        return -1;
    }
    if(l1>l2)
    {
        return 1;
    }
    while(*cad1)
    {
        if(toupper_(*cad1)<toupper_(*cad2))
        {
            return -1;
        }
        if(toupper_(*cad1)>toupper_(*cad2))
        {
            return 1;
        }
        cad1++;
        cad2++;
    }
    return 0;
}

char* strcpy_(char* dest, const char* src)
{
    char* inicio = dest;
    while(*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return inicio;
}
