#include <iostream>
#include <string>

// this is the base class
class Shape {
    public:
        void setWidth(int w) {
            width = w;
        }

        void setHeight(int h) {
            height = h;
        }
    protected:
        int width;
        int height;

}; //make sure to put the semicolon at the end of the class

// this is another base class
class PaintCost {
    public:
        int getCost(int area) {
            return area * 50;
        }
}; 

// this is the derived class that inherits from the base class
class Rectangle: public Shape, public PaintCost {
    public:
        int getArea() {
            return (width * height);
        }
};

class baseClass {
    public:
        void setName(std::string n) {  
            name = n; //ensure the input name param is different from the name var (ie, `name = name` will produce null)
        }

    protected:
        std::string name;
};

class derivedClass: public baseClass {
    public:
        std::string getName() {
            return name;
        }
};

int main() {
    Rectangle r;

    r.setWidth(10);
    r.setHeight(3);

    int area = r.getArea();
    int cost = r.getCost(area);
    std::cout << "Total Area: " << area << std::endl;
    std::cout << "Paint Cost: $" << cost << std::endl;

    derivedClass d;
    d.setName("John");
    std::cout << "Name: " << d.getName() << std::endl;
    return 0;
}
