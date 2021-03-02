#include <iostream>

int n = 0;

int add(int num);

// swap using pointers, when calling swap(), use addresses so pointers change value at address.
int swap(int *i, int *j); 

int main()
{

    n = add(10);
    std::cout << "num: " << n << std::endl;
    n = add(10);
    std::cout << "num: " << n << std::endl;

    int a = 5;
    int b = 25;
    std::cout << "before swap " << std::endl;
    std::cout << "a: " << a << " b: " << b << std::endl;
    swap(&a, &b);
    std::cout << "after swap " << std::endl;
    std::cout << "a: " << a << " b: " << b << std::endl;
    return 0;
}

int add(int num)
{
    return n + num;
}

int swap(int *i, int *j)
{

    int temp = *i;
    *i = *j;
    *j = temp;
}
