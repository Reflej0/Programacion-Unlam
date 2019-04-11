#include "libro.h"
using namespace std;

int main()
{
    Libro lib1("Programacion C","Brian Kernighan y Dennis Ritchie",294);
    Libro lib2;
    Libro lib3("The C++ Programming Language","Bjarne Stroustrup",1350);
    Libro lib4 = lib1 + lib3;
    lib1 = lib3 = lib4;
    lib4 = lib2 + lib2;


    if(lib1 == lib2)
        cout<<"Iguales"<<endl;
    else
        cout<<"Distintos"<<endl;


    //cin>>lib1;


    cout<<"El libro lib1 es: "<<lib1<<endl;
    cout<<"El libro lib2 es: "<<lib2<<endl;
    cout<<"El libro lib3 es: "<<lib3<<endl;
    cout<<"El libro lib4 es: "<<lib4<<endl;




    return 0;
}
