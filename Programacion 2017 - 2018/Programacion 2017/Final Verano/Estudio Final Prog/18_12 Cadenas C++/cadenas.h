#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

using namespace std;

class Cadena
{
private:
    char* cadena;
    Cadena(int capacidad);
public:
    Cadena(const char* cadena);
    Cadena& operator+=(const Cadena& otra);
    Cadena& operator=(const char* otra);
    ~Cadena();
    Cadena operator+(const char* otra)const;
    Cadena operator+(const Cadena& otra)const;
    Cadena operator+(char c)const;
    friend ostream& operator<<(ostream& sal, Cadena& otra);
};

#endif // CADENAS_H_INCLUDED
