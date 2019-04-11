#include <iostream>

using namespace std;

class Entero
{
private:
    int numero;
    bool positivo;
    Entero(const int numero, const bool positivo);
public:
    ///CONSTRUCTORES.
    //Constructor parametrizado por defecto.
    Entero(const int numero = 0);
    Entero(const Entero& e);
    ////Constructor parametrizado
    //Entero(int numero);
    ////Constructor por defecto.
    //Entero();

    ///GETS
    int getNumero()const;
    bool getPositivo()const;

    ///FRIENDS.
    friend ostream& operator<<(ostream& sal, const Entero& otro);
    friend istream& operator>>(istream& ent, Entero& otro);


    ///ARITMETICOS ENTRE OBJETOS.
    Entero operator+(const Entero& otro)const;
    Entero operator-(const Entero& otro)const;
    Entero operator*(const Entero& otro)const;
    Entero operator/(const Entero& otro)const;
    ///ARITMETICOS PRE.
    Entero& operator+();
    Entero& operator-();
    // No tiene sentido en números.
    //Entero& operator*();
    //Entero operator/();
    ///ARITMETICOS CON IGUAL.
    //Entero& operator=(const Entero &otro); // No tiene sentido si no hay new.
    Entero& operator+=(const Entero &otro);
    Entero& operator-=(const Entero &otro);
    Entero& operator*=(const Entero &otro);
    Entero& operator/=(const Entero &otro);
    ///COMPARACION.
    bool operator==(const Entero& otro)const;
    bool operator!=(const Entero& otro)const;
    bool operator<(const Entero& otro)const;
    bool operator>(const Entero& otro)const;
    bool operator<=(const Entero& otro)const;
    bool operator>=(const Entero& otro)const;
    ///INCREMENTOS, DECREMENTOS, UNARIOS.
    Entero& operator++(); //PRE-INCREMENTO.
    Entero operator++(int); //POST-INCREMENTO.
    Entero& operator--(); //PRE-INCREMENTO.
    Entero operator--(int); //POST-INCREMENTO.
    ///ARRAY
    //Entero& operator[](int otro); //DEFINIR PARA QUE VOY A USAR ESTO.

};

int operator+(int primitivo, const Entero& otro); // PRIMITIVO + OBJETO.
