using namespace std;
class Fecha
{
private:
    int d;
    int m;
    int a;
    static bool esBisiesto(int a);
    static int cantDiasMes(int m, int a);
    static bool validarFecha(int d, int m, int a);
public:
    Fecha(int d=0, int m=0, int a=0);
    int getDia()const;
    int getMes()const;
    int getAnio()const;
    friend ostream& operator<<(ostream&, const Fecha&);
    friend istream& operator>>(istream&, Fecha&);
};
