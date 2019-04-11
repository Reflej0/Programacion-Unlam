#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
protected:
    int width;
    int height;
public:
    Shape();
    Shape(int width, int height);
    void set_width(int width);
    void set_height(int height);
    int get_width();
    int get_height();
};

#endif
