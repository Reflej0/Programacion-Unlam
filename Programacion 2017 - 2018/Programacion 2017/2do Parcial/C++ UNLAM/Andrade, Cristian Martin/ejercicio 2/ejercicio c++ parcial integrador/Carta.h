#ifndef CARTA_H
#define CARTA_H
#include <string.h>
#include <iostream>
using namespace std;

class Carta
{
    public:
        Carta(char* = NULL,char[20] = '\0',float = 0);
        ~Carta();
    Carta& operator=(const Carta&);
    Carta& operator++();
friend istream& operator>>(istream&,Carta&);
friend ostream& operator<<(ostream&,Carta&);
    protected:
    private:
        char* destinatario;
        char paisDeDestino[20];
        float precio;
};

#endif // CARTA_H
