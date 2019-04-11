#include "shape.h"


class Triangle: public Shape
{
public:
    Triangle(int width, int height);
    int get_area();
};
