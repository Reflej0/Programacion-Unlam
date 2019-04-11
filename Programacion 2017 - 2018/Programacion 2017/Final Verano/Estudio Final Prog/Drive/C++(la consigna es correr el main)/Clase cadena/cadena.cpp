
#include "cadena.h"

Cadena::Cadena(const char *cad)
/// : cad(dupliCadena(cad))
{
    this->cad = dupliCadena(cad);
    if(cad && *cad && this->cad == NULL)
        cerr << "ERROR - sin memoria constructor parametrizado." << endl;
}

Cadena::Cadena(void)
/// : cad(NULL)
{
    this->cad = NULL;
}

Cadena::~Cadena(void)
{
    delete [] cad;
/// cad = NULL;
}

Cadena &Cadena::operator =(const Cadena &obj)
{
    delete [] this->cad;
    this->cad = dupliCadena(obj.cad);
    if(obj.cad && this->cad == NULL)
        cerr << "ERROR - sin memoria operator =." << endl;
    return *this;
}

Cadena &Cadena::operator =(const char *cad)
{
    delete [] this->cad;
    this->cad = dupliCadena(cad);
    if(cad && *cad && this->cad == NULL)
        cerr << "ERROR - sin memoria operator = char *." << endl;
    return *this;
}

Cadena &Cadena::operator =(int n)
{
    char cad[12];
    itoa(n, cad, 10);
    delete [] this->cad;
    this->cad = dupliCadena(cad);
    if(this->cad == NULL)
        cerr << "ERROR - sin memoria operator = int." << endl;
    return *this;
}

Cadena &Cadena::operator =(char c)
{
    char cad[2];
    cad[0] = c;
    cad[1] = '\0';
    delete [] this->cad;
    this->cad = dupliCadena(cad);
    if(this->cad == NULL && c)
        cerr << "ERROR - sin memoria operator = char." << endl;
    return *this;
}

Cadena &Cadena::operator +=(const Cadena &obj)
{
    char *aux = concatCadena(this->cad, obj.cad);
    delete [] this->cad;
    this->cad = aux;
    if((obj.cad || this->cad) && this->cad == NULL)
        cerr << "ERROR - sin memoria operator += objetoCadena." << endl;
    return *this;
}

Cadena &Cadena::operator +=(int n)
{
    char num[12];
    itoa(n, num, 10);
    char *aux = concatCadena(this->cad, num);
    delete [] this->cad;
    this->cad = aux;
    if(this->cad == NULL)
        cerr << "ERROR - sin memoria operator += int." << endl;
    return *this;
}

Cadena &Cadena::operator +=(char c)
{
    char cad[2];
    cad[0] = c;
    cad[1] = '\0';
    char *aux = concatCadena(this->cad, cad);
    if((this->cad || c) && aux == NULL)
        cerr << "ERROR - sin memoria operator += char." << endl;
    delete [] this->cad;
    this->cad = aux;
    return *this;
}

ostream &operator <<(ostream &sal, const Cadena &obj)
{
    sal << (obj.cad ? obj.cad : "");
    return sal;
}

Cadena::Cadena(const Cadena &obj)
{
    this->cad = dupliCadena(obj.cad);
    if(obj.cad && this->cad == NULL)
        cerr << "ERROR - sin memoria constructor de copia." << endl;
}

Cadena Cadena::operator +(const Cadena &obj) const
{
    Cadena aux;
    aux.cad = concatCadena(this->cad, obj.cad);
    if((this->cad || obj.cad) && aux.cad == NULL)
        cerr << "ERROR - sin memoria operator + (cad + cad)." << endl;
    return aux;
}

Cadena Cadena::operator +(const char *cad) const
{
    Cadena aux;
    aux.cad = concatCadena(this->cad, cad);
    if(aux.cad == NULL && (this->cad || (cad && *cad)))
        cerr << "ERROR - sin memoria operator + char *." << endl;
    return aux;
}

Cadena operator +(const char *cad, Cadena const &obj)
{
    Cadena aux;
    aux.cad = concatCadena(cad, obj.cad);
    if(aux.cad == NULL && (obj.cad || (cad && *cad)))
        cerr << "ERROR - sin memoria operator + (char * + cadena)." << endl;
    return aux;

}

Cadena Cadena::operator +(int n) const
{
    char cad[12];
    itoa(n, cad, 10);
    Cadena aux;
    aux.cad = concatCadena(this->cad, cad);
    if(aux.cad == NULL)
        cerr << "ERROR - sin memoria operator + int." << endl;
    return aux;
}

Cadena operator +(int n, Cadena const &obj)
{
    char cad[12];
    itoa(n, cad, 10);
    Cadena aux;
    aux.cad = concatCadena(cad, obj.cad);
    if(aux.cad == NULL)
        cerr << "ERROR - sin memoria operator + (int + cadena)." << endl;
    return aux;
}

Cadena Cadena::operator +(char c) const
{
    char cad[2];
    cad[0] = c;
    cad[1] = '\0';
    Cadena aux;
    aux.cad = concatCadena(this->cad, cad);
    if(aux.cad == NULL && (this->cad || c))
        cerr << "ERROR - sin memoria operator + char." << endl;
    return aux;
}

Cadena operator +(char c, Cadena const &obj)
{
    char cad[2];
    cad[0] = c;
    cad[1] = '\0';
    Cadena aux;
    aux.cad = concatCadena(cad, obj.cad);
    if(aux.cad == NULL && (obj.cad || c))
        cerr << "ERROR - sin memoria operator + (char + cadena)." << endl;
    return aux;
}

/** este es un método estático de la clase Cadena
 **     en el mismo, no hay objeto this
 ** devuelve un objeto de la class Cadena con la representación como cadena de
 **     caracteres del argumento que recibe, en este caso un array de char
 ** se lo puede utilizar tanto con
 **         Cadena::aCadena("Que tal");
 **     como con
 **         c.aCadena("Que tal");       si c es un objeto de la clase
 **/
 Cadena Cadena::aCadena(const char *cad)
{
    return Cadena(cad);
}
