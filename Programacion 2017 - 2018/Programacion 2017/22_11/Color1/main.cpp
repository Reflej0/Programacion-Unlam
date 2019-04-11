#include <iostream>
#include "Color.h"

using namespace std;

int main()
{
    Color c1(255,0,0,"Rojo pleno"),
            c2,
            c3;
    c2 = c1--; //decrementa,si se puede, cada valor entero
    //c2 = c1, c2=(255,0,0) ,c1=(244,255,255)
    c3 = ++c2; //incrementa,si se peude, cada valor entero
    //c2 = (0,1,1) c3 = c2  c3=(0,1,1)
    Color c4 = c3++;
    //c4 = c3 c4=(0,1,1) c3=(1,2,2)

    c4.CambiarColorNomb("Amarillo patito");

    cout<<c4<<endl;

    cout<<c1<<c2<<c3<<(c4=c3)<<endl; //por el c4=c3, c4=(1,2,2,"Rojo Pleno")

    //c4 = c3 c4=(1,2,2)

    /*Salida:
    r: 0 g: 1 b: 1 nom: Amarillo patito

    r: 254 g: 255 b: 255 nom: Rojo pleno
    r: 0 g: 1 b: 1 nom: Rojo pleno
    r: 1 g: 2 b: 2 nom: Rojo pleno
    r: 1 g: 2 b: 2 nom: Rojo pleno

    It's not a question of preference, but of logic.

    x++ increments the value of variable x after processing the current statement.

    ++x increments the value of variable x before processing the current statement.
    */
    return 0;
}
