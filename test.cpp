#include <iostream>
#include <stdlib.h>

using namespace std;
/**
 * Cpp refresher on base information for Cpp. See README.md for more cpp info.
 */

// declare variable scope like you do in C
int a, b, c;
float f;
//extern example
int counts;
extern void write_extern();

// declare function scope, like you do in C
void sizeExamples();
double varExample();

int main()
{
    cout << "hello\n";
    // data type sizes
    sizeExamples();
    varExample();

    //extern example
    counts = 5;
    write_extern();
    return 0;
}

void sizeExamples(void)
{
    cout << "Size of char : " << sizeof(char) << " bytes" << endl;
    cout << "Size of int : " << sizeof(int) << " bytes" << endl;
    cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
    cout << "Size of float : " << sizeof(float) << " bytes" << endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << endl;
}

double varExample()
{
    a = 10;
    b = 20;
    c = a + b;

    cout << "c: " << c << endl;

    f = 70.0 / c;
    cout << "f: " << f << endl;
    return 0.0;
}
