#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class Libro
{
    private:
        char nombre[60];
        char autor[50];
        int paginas;

    public:
        Libro(char* nom="El libro de Cosme Fulanito",char* au="Cosme Fulanito" ,int pag=1000);
        Libro operator+(const Libro&)const;
        bool operator==(const Libro&)const;
        friend ostream& operator<<(ostream& out,Libro& libro);
};

#endif // LIBRO_H_INCLUDED
