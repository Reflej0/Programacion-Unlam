#include <iostream>
#include "shape.h"

Shape::Shape(int width, int height)
{
    this->width = width;
    this->height = height;
}

Shape::Shape()
{
    this->width = 0;
    this->height = 0;
}

void Shape::set_width(int width)
{
    this->width = width;
}

void Shape::set_height(int height)
{
    this->height = height;
}

int Shape::get_width()
{
    return this->width;
}

int Shape::get_height()
{
    return this->height;
}
