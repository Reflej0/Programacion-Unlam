#include "shape.h"

class Rectangle: public Shape
{
public:
    Rectangle(int width, int height);
    int get_area();
};
