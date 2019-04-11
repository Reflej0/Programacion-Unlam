#include "Persona.h"
#include "string.h"

Persona::Persona(){

    dni=0;
    strcpy(nombre,"");
}
Persona::Persona(int d,char*nom){

    dni=d;
    strcpy(nombre,nom);
}
istream& operator>>(istream&ent,Persona&obj){

    cout<<"ingrese dni: "<<endl;
    ent>>obj.dni;
    cout<<"ingrese nombre: "<<endl;
    ent.ignore(1);
    ent.getline(obj.nombre,sizeof(obj.nombre));
    return ent;
}
ostream& operator<<(ostream&sal,Persona&obj){

    sal<<"dni: "<<obj.dni<<" nombre: "<<obj.nombre<<endl;

    return sal;
}
