#include <iostream>
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main()
{
    Rectangle r1(10, 15);
    Triangle t1(5, 17);
    cout << "El area del rectangulo es:" << r1.get_area();
    cout << "El area del triangulo es:" << t1.get_area();
}
