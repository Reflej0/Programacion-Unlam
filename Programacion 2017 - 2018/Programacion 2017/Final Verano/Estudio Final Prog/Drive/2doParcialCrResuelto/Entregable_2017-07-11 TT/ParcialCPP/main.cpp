
#include "Racional.h"


int main()
{
    Racional r1, r2(2, 4), r3, r4, r5;

    r1 = 3;
    r3 = r1 + r2;
    r4 = 2 + r3;
	cout << "r1: "<< r1 << ", r2: " << r2 << ", r3: " << r3 << ", r4: " << r4 << endl;
	cout << "r1: "<< r1.real() << ", r2: " << r2.real() << ", r3: " << r3.real() << ", r4: " << r4.real() << endl;
	cout<<"\nIngese la fracción (numerador/denominador): ";
	cin>>r5;
	cout<<endl<<"r5: "<<r5<<endl;
	if(r5>r3)
        cout<< "r5 es mayor"<<endl;

    return 0;
}
