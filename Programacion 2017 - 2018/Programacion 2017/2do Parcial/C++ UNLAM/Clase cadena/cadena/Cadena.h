#include <iostream>
#include <string.h>
#ifndef CADENA_H
#define CADENA_H
using namespace std;
class Cadena
{
    public:
        Cadena();
        Cadena (const char*);
        ~Cadena();
        Cadena(const Cadena&);
        Cadena& operator=(const Cadena&);
        friend ostream& operator<<(ostream&,const Cadena&);
        friend istream& operator>>(istream&,Cadena&);
    protected:
    private:
        char* cd;
        char ce[20];
};

#endif // CADENA_H
