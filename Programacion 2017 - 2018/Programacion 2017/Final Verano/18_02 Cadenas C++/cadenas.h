#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
using namespace std;

class Cadena
{
private:
    char* cad;
    Cadena(int tam);
public:
    Cadena(const char* cad);
    Cadena& operator=(const Cadena& otra);
    ~Cadena();
    Cadena operator+(const char c)const;
    Cadena operator+(const char* otra)const;
    Cadena operator+(const Cadena& otra)const;
    Cadena& operator+=(const Cadena&otra);
    friend ostream& operator<<(ostream& sal, Cadena& cad);
};

#endif // CADENAS_H_INCLUDED
