#include <iostream>

using namespace std;

class Entero
{
private:
    int numero;
    int signo;
public:
    ///CONSTRUCTORES.
    Entero(int numero);
    Entero();
    ///FRIENDS.
    friend ostream& operator<<(ostream& sal, Entero otro);
    friend istream& operator>>(istream& sal, Entero& otro);
    ///ARITMETICOS.
    Entero operator+(Entero otro);
    Entero operator-(Entero otro);
    Entero operator*(Entero otro);
    Entero operator/(Entero otro);
    ///ARITMETICOS PRE.
    Entero& operator+();
    Entero& operator-();
    Entero& operator*(); // No tiene sentido en números.
    //Entero operator/();
    ///ARITMETICOS CON IGUAL.
    Entero operator=(const Entero &otro);
    Entero& operator+=(Entero otro);
    Entero& operator-=(Entero otro);
    Entero& operator*=(Entero otro);
    Entero& operator/=(Entero otro);
    ///COMPARACION.
    bool operator==(Entero otro);
    bool operator!=(Entero otro);
    bool operator<(Entero otro);
    bool operator>(Entero otro);
    bool operator<=(Entero otro);
    bool operator>=(Entero otro);
    ///INCREMENTOS, DECREMENTOS, UNARIOS.
    Entero& operator++(); //PRE-INCREMENTO.
    Entero& operator++(int); //POST-INCREMENTO.
    Entero& operator--(); //PRE-INCREMENTO.
    Entero& operator--(int); //POST-INCREMENTO.
    ///ARRAY
    Entero& operator[](int otro); //DEFINIR PARA QUE VOY A USAR ESTO.

};
