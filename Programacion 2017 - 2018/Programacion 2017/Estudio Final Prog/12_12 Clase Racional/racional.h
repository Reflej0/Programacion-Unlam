#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED

#include <iostream>

using namespace std;

class Racional
{
private:
    unsigned numerador;
    unsigned denominador;
    int signo;
public:
    ///CONSTRUCTORES.
    Racional();
    Racional(float numero);
    Racional(unsigned numerador, unsigned denominador, int signo);
    ///SOBRECARGA DE OPERADORES CON UN FLOAT.
    /*
    Es construir el fraccionario en base al float
    y hacer lo mismo que con los operadores con otro racional.
    */
    Racional operator=(const Racional &otro);
    Racional operator+(float otro);
    Racional operator-(float otro);
    Racional operator*(float otro);
    Racional operator/(float otro);
    Racional& operator+=(float otro);
    Racional& operator-=(float otro);
    Racional& operator*=(float otro);
    Racional& operator/=(float otro);
    ///SOBRECARGA DE OPERADORES CON OTRO RACIONAL.
    Racional operator+(const Racional &otro);
    Racional operator-(const Racional &otro);
    Racional operator*(const Racional &otro);
    Racional operator/(const Racional &otro);
    Racional& operator+=(const Racional &otro);
    Racional& operator-=(const Racional &otro);
    Racional& operator*=(const Racional &otro);
    Racional& operator/=(const Racional &otro);


    ///SIMPLIFICA LA FRACCION.
    void Simplificar();
    ///FRIENDS.
    friend ostream& operator<<(ostream& sal, Racional otro);
    friend istream& operator>>(istream& sal, Racional otro);
    ///FUNCIONES ESTATICAS.
    static int MCD(int a, int b);
    static int MCM(int a, int b);
};

#endif // RACIONAL_H_INCLUDED
