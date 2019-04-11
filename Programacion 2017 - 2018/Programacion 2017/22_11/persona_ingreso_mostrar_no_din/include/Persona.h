#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

class Persona
{
    public:
        Persona();
        Persona(int d,char*nom);
        friend istream& operator>>(istream&ent,Persona&obj);
        friend ostream& operator<<(ostream&sal,Persona&obj);


    protected:

    private:
        int dni;
        char nombre[50];
};

#endif // PERSONA_H
