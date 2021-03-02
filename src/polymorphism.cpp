#include <iostream>

class Shape
{
    public:
        Shape(int w = 0, int h = 0)
        {
            width = w;
            height = h;
        }

        // virtual int area()
        // {
        //     std::cout << "Parent class area :" << std::endl;
        //     return 0;

        // }
        
        //pure virtual funtion of int area()
        virtual int area() = 0;

    protected:
        int width, height;
};

class Rectangle : public Shape
{
    public:
        Rectangle(int w = 0, int h = 0) : Shape(w, h)
        {
        }

        int area()
        {
            double a = width * height;
            std::cout << "Rectangle class area: " << a << std::endl;
            return a;
        }
};

class Triangle : public Shape
{
    public:
        Triangle(int w = 0, int h = 0) : Shape(w, h)
        {
        }

        int area()
        {
            double a = (width * height / 2);
            std::cout << "Triangle class area: " << a << std::endl;
            return a;
        }
};

int main()
{
    Shape *shape;
    Rectangle r(10,7);
    Triangle t(10,5);

    //store rectangle addressed, then get address
    shape = &r;
    shape->area();

    //store triangle addressed, then get address
    shape = &t;
    shape->area();

    return 0;
}