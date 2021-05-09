#include <iostream>
using namespace std;

#define PI 3.14159

int main() {
    cout << "PI definition: " << PI << endl;
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