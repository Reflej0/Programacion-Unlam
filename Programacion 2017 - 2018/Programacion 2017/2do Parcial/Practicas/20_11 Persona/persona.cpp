#include "fecha.h"
#include "cadenas.h"
#include "persona.h"

Persona::Persona(int dni, const Cadena &apyn, char sexo, const Fecha &Fnac)
{
    //Validar();
    this->dni = dni;
    this->apyn = apyn;
    this->sexo = sexo;
    this->Fnac = Fnac;
}


int Persona::getEdad(const Fecha&f)const
{
    int dN, mN, aN, dF, mF, aF;
    this->Fnac.getDMA(dN, mN, aN);
    f.getDMA(dF, mF, aF);
    int dif = aF - aN;
    if(mN>=mF)
    {
        if(dN>dF)
        {
            dif--;
        }
    }
    return dif;
}

int Persona::getDni()const
{
    return this->dni;
}

const char*Persona::getApyn()const
{
    return this->apyn.getCadena();
}

Fecha Persona::getFnac()const
{
    return this->Fnac;
}

ostream&operator<<(ostream &sal, const Persona &P)
{
    char c = '\n';
    Fecha hoy(20, 11, 2017);
    sal << "DNI:" << P.getDni() << c <<  "Nombre y Apellido:" << P.getApyn() << c <<  "Edad:" << P.getEdad(hoy);
    return sal;
}
