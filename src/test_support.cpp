#include <iostream>

using namespace std;

extern int counts;

void write_extern()
{
    cout << "Count is: " << counts << endl;
}
