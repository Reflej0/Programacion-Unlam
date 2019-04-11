#include "fecha.h"
#include "cadena.h"
using namespace std;
class Persona
{
private:
    long dni;
    Cadena nya;
    Fecha fnac;
public:
    Persona(const long dni=0, const Cadena& = Cadena(), const Fecha& = Fecha());
    friend ostream& operator<<(ostream&, const Persona&);
};
