using namespace std;

class Hora
{
private:
    int segundos;
    int minutos;
    int horas;
public:
    Hora();
    Hora(int segundos);
    Hora operator+(Hora otro);
    Hora& operator++();
    friend ostream& operator<<(ostream& sal, Hora otro);
};
