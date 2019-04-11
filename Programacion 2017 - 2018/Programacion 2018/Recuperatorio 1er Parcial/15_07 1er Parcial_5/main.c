#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t _strlen(const char* s)
{
    size_t l = 0;
    while(*s)
    {
        s++;
        l++;
    }
    return l;
}

char* _strstr(const char* donde, const char* que)
{
    if(!donde || !*donde || !que || !*que) return (char*)donde;
    const char* inicio = que;
    while(*donde)
    {
        if(*donde == *que)
        {
            que++;
            if(*que == '\0')
                return (char*)donde-_strlen(inicio)+1;
        }
        else
            que = inicio;
        donde++;
    }
    return NULL;
}

unsigned __strstr(const char* donde, const char* que)
{
    if(!donde || !*donde || !que || !*que) return 0;
    const char* inicio = que;
    unsigned ocurrencias = 0;
    while(*donde)
    {
        if(*donde == *que)
        {
            que++;
            if(*que == '\0')
            {
                ocurrencias++;
                que = inicio;
            }
        }
        else
            que = inicio;
        donde++;
    }
    return ocurrencias;
}

int main()
{
    char lote[50] = "ABRACADABRA PATA DE CABRA";
    char car1[20] = "ABRA";
    char car2[20] = "EBRA";
    char car3[20] = "";
    printf("%d", __strstr(lote, car3));
    return 0;
}
