#include <iostream>
#include "Racional.h"

using namespace std;

int main()
{
    Racional r1,r2,r3;

    r3 = r1/r2;

    cout<<r1<<" / "<<r2<<" = "<<r3<<endl;

    int n1=10,n2=25;

    r1 -= n1;

    cout<<"r1: "<<r1<<endl;

    r1 /= n2;

    r3 = r1/r2;

    cout<<r1<<" / "<<r2<<" = "<<r3<<endl;

    n1=20;
    n2=-25;

    r1=r2;

    r1 -= n1;

    r1 /= n2;

    r3 = r1 / r2;

    cout<<r1<<" / "<<r2<<" = "<<r3<<endl;

    Racional r4(34,51),
            r5(11,22),
            r6(76,57),
            rx(1);

    n1=3;

    rx=(r4+n1)/(r5+r6);

    cout<<'('<<r4<<'+'<<n1<<")/("<<r5<<'+'<<r6<<") = "<<rx<<endl;

    Racional ry = rx;

    cout<<ry<<"*="<<r4<<'+'<<r6<<'+'<<rx<<"++ = ";

    ry *= r4+r6+rx++;

    cout<<ry<<endl;

    cout<<"rx= "<<rx;

    /*
        Salida:

        ( 0 / 1 ) / ( 0 / 1) = (Indet.)

        (-2 / 5 ) / ( 0 / 1) = (-Inf)

        ( 4 / 5 ) / ( 0 / 1 ) = (+Inf)

        ((2/3)+3)/((1/2)+(4/3))=(2/1)

        (2/1) *= (2/3)+(4/3)+(2/1)++ = (8/1)

        rx=(3/1)
    */

    /*
        Salida de este:

        (0 / 1) / (0 / 1) = (Indet.)
        r1: (-10 / 1)
        (-2 / 5) / (0 / 1) = (-Inf.)
        (4 / 5) / (0 / 1) = (+Inf)
        ((2 / 3)+3)/((1 / 2)+(4 / 3)) = (2 / 1)
        (2 / 1)*=(2 / 3)+(4 / 3)+(2 / 1)++ = (8 / 1)
        rx= (3 / 1)
    */
    return 0;
}
