#include <iostream>

using namespace std;

class Racional
{
private:
    int numerador;
    int denominador;
    int signo;
    static int MCD(int a, int b);
    static int MCM(int a, int b);
public:
    Racional(double numero);
    Racional();
    friend ostream& operator<<(ostream&sal, Racional& r);

};
