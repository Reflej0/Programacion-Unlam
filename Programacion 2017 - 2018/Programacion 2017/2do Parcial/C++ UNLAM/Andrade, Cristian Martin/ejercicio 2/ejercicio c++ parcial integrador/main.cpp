#include "Carta.h"


int main()
{
    Carta c1,c2("Pepe","Arabia",12352);
    cout<<"\nC1: ";
    cout<<c1<<endl;
    cout<<"\nC2: ";
    cout<<c2<<endl;
    cin>>c1;
    cout<<"\nC1(cargado con cin): ";
    cout<<c1<<endl;
    c1=c2;
    cout<<("\nC1 (igualado a C2): ");
    cout<<c1<<endl;
    ++c1;
    cout<<("\nC1 (preincrementado): ");
    cout<<c1<<endl;
    return 0;
}
