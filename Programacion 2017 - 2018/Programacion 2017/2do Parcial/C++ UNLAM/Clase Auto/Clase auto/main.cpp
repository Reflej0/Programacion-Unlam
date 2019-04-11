#include "Auto.h"

int main()
{
    Auto coche1, coche2("Ford","Focus",2012,130988.99);
    float aumento;
    cout<<"Coche 1: "<<coche1<<"\n"<<"\nCoche 2: "<<coche2<<endl;
    coche1=coche2;
    cout<<"\nCoche 1(igualado a coche2): "<<coche1<<endl;
    ++coche2;
    cout<<"\nCoche 2(preincrementado): "<<coche2<<endl;
    do
    {
        cout<<"Ingrese el porcentaje de aumento de precio: ";
        cin>>aumento;
    }while(aumento<0||aumento>100);
    coche2.aumentarPrecio(aumento);
    cout<<"Coche 2(con aumento de precio): "<<coche2<<endl;
    return 0;
}
