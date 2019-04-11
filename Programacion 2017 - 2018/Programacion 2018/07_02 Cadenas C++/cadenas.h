
using namespace std;

class Cadena
{
private:
    char* cadena;
    Cadena(int capacidad);
public:
    Cadena(const char* otra);
    Cadena& operator=(Cadena &otra);
    Cadena operator+(Cadena &otra);
    Cadena operator+(char* otra);
    Cadena operator+(char c);
    Cadena& operator+=(Cadena &otra);
    friend ostream& operator<<(ostream& sal, Cadena& otra);
};

