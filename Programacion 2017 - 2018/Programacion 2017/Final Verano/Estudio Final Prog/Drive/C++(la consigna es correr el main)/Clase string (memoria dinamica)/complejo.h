#ifndef COMPLEJO_H
#define COMPLEJO_H


class Complejo
{
    public:
        Complejo(float x=0,float y=0);
        virtual ~Complejo();
        Complejo operator=(const float)const;
        Complejo operator*(const float)const;
        Complejo operator*(const int)const;
        void calcular(int nUno,int nDos,float fTre,float fCua,int nCin);
        float Getreal() { return real; }
        void Setreal(float val) { real = val; }
        int Getcomp() { return comp; }
        void Setcomp(float val) { comp = val; }
    protected:
    private:
        float real;
        float comp;
};

#endif // COMPLEJO_H
