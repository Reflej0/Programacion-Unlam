#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include"string.h"

using namespace std;

class Color
{
    public:
        Color();
        Color(int a,int b,int c,char*nom);

        Color& operator=(const Color&obj);
        Color operator--(int); //x--
        Color operator++(int);//x++
        Color& operator++();//++x
        void CambiarColorNomb(char*nom);

        friend ostream& operator<<(ostream&sal,Color&obj);

    protected:

    private:
        int r,g,b;
        char nombre[50];
};

#endif // COLOR_H
