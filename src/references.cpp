#include <iostream>

int main()
{
    int i = 10;
    double d = 5.0;

    // declare reference variables
    int &r = i;
    double &s = d;

    i = 5;
    std::cout << "Value of i: " << i << std::endl;
    std::cout << "Value of r (i's reference): " << r << std::endl;

    d = 45.12;
    std::cout << "Value of d: " << d << std::endl;
    std::cout << "Value of s (d's reference): " << s << std::endl;
    return 0;
}