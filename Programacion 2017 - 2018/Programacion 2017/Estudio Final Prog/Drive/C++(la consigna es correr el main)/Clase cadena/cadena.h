#ifndef CADENA_H_
#define CADENA_H_

#include <stdlib.h>

#include "funciones.h"


class Cadena
{
    char   *cad;

friend ostream &operator <<(ostream &sal, const Cadena &obj);

public :
    Cadena(void);
    Cadena(const char *cad);
/// Cadena(const char *cad = NULL);
    ~Cadena(void);

    Cadena &operator =(const Cadena &obj);
    Cadena &operator =(const char *cad);
    Cadena &operator =(int n);
    Cadena &operator =(char c);

    Cadena &operator +=(const Cadena &obj);
    Cadena &operator +=(const char *cad);
    Cadena &operator +=(int n);
    Cadena &operator +=(char c);

/** para los siguientes 'operator' em muchos compiladores es imprescindible un
 **     constructor de copia de las clases que tienen asignación dinámica de
 **     memoria, porque devuelven un objeto que se devuelve pero se destruye
 **     al final del bloque de código en que están declarados
 ** algunos compiladores, para evitar la creación de una copia del objeto a
 **     devolver, hacen que el objeto que se devuelve tenga una 'sobrevida' y
 **     no se destruya hasta que se use, evitando así una sobrecarga de tiempos
 **     de ejecución
 ** aunque este compilador no lo requiere, debería resolverlo de todos modos
 **/
    Cadena(const Cadena &obj);

    Cadena operator +(const Cadena &obj) const;
    Cadena operator +(const char *cad) const;
friend Cadena operator +(const char *cad, Cadena const &obj);
    Cadena operator +(int b) const;
friend Cadena operator +(int n, Cadena const &obj);
    Cadena operator +(char c) const;
friend Cadena operator +(char c, Cadena const &obj);

/** aCadena
 **     en el mismo, no hay objeto this
 ** devuelve un objeto de la class Cadena con la representación como cadena de
 **     caracteres del argumento que recibe, en este caso un array de char
 ** se lo puede utilizar tanto con
 **         Cadena::aCadena("Que tal");
 **     como con
 **         c.aCadena("Que tal");       si c es un objeto de la clase
 **/
static Cadena aCadena(const char *cad);

};

#endif

