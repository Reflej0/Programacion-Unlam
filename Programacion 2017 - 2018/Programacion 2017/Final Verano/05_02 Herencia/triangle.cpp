#include <iostream>
#include "triangle.h"

Triangle::Triangle(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Triangle::get_area()
{
    return (Shape::height*Shape::width)/2;
}
