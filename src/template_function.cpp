#include <iostream>
#include <string>

// This example is a FUNCTION template that returns the max of two values.
//This function will take in any type as shown in the main() below.
template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

int main()
{
    int i = 39;
    int j = 20;
    std::cout << "Max(i, j): " << Max(i, j) << std::endl;

    double f1 = 134.5;
    double f2 = 23.34;
    std::cout << "Max(f1, f2): " << Max(f1, f2) << std::endl;

    std::string s1 = "hello";
    std::string s2 = "world";
    std::cout << "Max(s1, s2): " << Max(s1, s2) << std::endl;

    return 0;
}