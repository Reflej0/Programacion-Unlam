#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[]="143.3";
    float float_cadena = atof(cadena);
    int int_cadena = atoi(cadena);
    char char_cadena[5];
    itoa(int_cadena, char_cadena, 10);
    printf("Float:%.2f", (float_cadena+20.23));
    printf("\nInt:%d", (int_cadena+20));
    printf("\nChar:%s", char_cadena);
}
