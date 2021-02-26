#include <iostream>

int main()
{

    int var = 50;    // regular variable
    int *pointerVar; // initialize pointer

    pointerVar = &var; //address of var

    std::cout << "Value of the var: ";
    std::cout << var << std::endl;

    std::cout << "Address of the var: ";
    std::cout << &var << std::endl;

    std::cout << "Address stored in pointerVar (var's address): ";
    std::cout << pointerVar << std::endl;

    std::cout << "Value stored in pointerVar (var's value): ";
    std::cout << *pointerVar << std::endl;
    return 0;
}