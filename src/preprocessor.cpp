#include <iostream>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

#define DEBUG
#define MKSTR(x) #x
#define CONCAT(a, b) a##b
#define PI 3.14159
#define MIN(a, b) (((a) < (b)) ? a : b)

int main()
{
    cout << "PI definition: " << PI << endl;

    int i = 200;
    int j = 100;

    cout << "The minimum between i(200) and j(100) is: " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
    //This is commented out code that will not compile
    cout << MKSTR(HELLO C++) << endl;
#endif
    // This will output as defined
    cout << MKSTR(HELLO C++) << endl;

    int xy = 300;
    // This is transformed into xy, hence outputting the int variable xy.
    cout << CONCAT(x, y) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif

//predefined c++ macros
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;

    return 0;
}

/* To do processing of this use the the `-E` option to redirect the result to a file output.  Example: 
    
    g++ -E preprocessor.cpp > test.p

   Then view the test.p file and see what it outputs. The test.p file shows the compilation process, 
   and at the end of the file will include the source code with your predefined constant for PI:

   int main() {
    cout << "PI definition: " << 3.14159 << endl;
    return 0;
    }
*/
