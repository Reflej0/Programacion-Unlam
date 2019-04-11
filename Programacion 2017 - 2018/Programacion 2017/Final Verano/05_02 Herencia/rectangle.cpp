#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Rectangle::get_area()
{
    return Shape::height*Shape::width;
}
