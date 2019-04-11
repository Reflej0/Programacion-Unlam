#include <iostream>
#include "racional.h"

Racional::Racional(int num, int den)
{
    if((num*den)<0)
    {
        this->signo = -1;
    }
    else
    {
        this->signo = 1;
    }

}
