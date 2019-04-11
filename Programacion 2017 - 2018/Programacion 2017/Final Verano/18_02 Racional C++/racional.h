
using namespace std;

class Racional
{
private:
    int signo;
    unsigned num;
    unsigned den;
public:
    Racional(int num, int den);
    Racional();
    Racional operator+(Racional& otro);
    friend ostream& operator<<(ostream& sal, Racional& otro);
    int static MCD(unsigned int a, unsigned int b);
    int static MCM(unsigned int a, unsigned int b);
    friend Racional operator+(int e, Racional& r);
};
