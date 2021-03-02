#include <iostream>

class Box {

    public:
        double getVolume(void) {
            return length * width * height;
        }
        void setParams(double l, double w, double h){
            length = l;
            width = w;
            height = h;
        }

        // here is the overloaded operator that is going to add two box objects together;
        Box operator+(const Box& b) {
            Box box;
            box.length = this->length + b.length;
            box.width = this->width + b.width;
            box.height = this->height + b.height;
            return box;
        }

    private:
        double length, width, height;
};


int main() {

    Box box1, box2, box3;
    double vol = 0.0;

    box1.setParams(6.0, 7.0, 5.0);
    box2.setParams(12.0, 13.0, 10.0);

    vol = box1.getVolume();
    std::cout << "Box 1 volume: " << vol << std::endl;

    vol = box2.getVolume();
    std::cout << "Box 2 volume: " << vol << std::endl;

    // use the overloaded operator here to add box1 and box2 together
    box3 = box1 + box2;

    vol = box3.getVolume();
    std::cout << "Box 3 volume: " << vol << std::endl;
    
    return 0;
}