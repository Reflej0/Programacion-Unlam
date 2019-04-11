#include "Profesional.h"

int main()
{
    Profesional p1,p2("Carlos",18318,5000.56), p3("Carlos",126416),p4;
    float incremento;
    cin>>p4;
    system("cls");
    cout<<"\nPersona 1: "<<p1<<"\nPersona 2: "<<p2<<"\nPersona 3: "<<p3<<"\nPersona 4: "<<p4<<endl;
    cout<<"\nIngrese el monto que le desea aumentar al sueldo: ";
    cin>>incremento;
    p3+incremento;
    cout<<"\nPersona 3(con ingremento de sueldo de "<<"$"<<incremento<<"): "<<p3<<endl;
    p1=p2;
    cout<<"\nPersona 1(igualado a persona 2): "<<p1<<endl;
    return 0;
}
