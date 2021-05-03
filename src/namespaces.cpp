#include <iostream>
using namespace std;

namespace first_space {
    void func() {
        cout << "This is the first namespace" << endl;
    }
}

namespace second_space {
    void func() {
        cout << "This is the second namespace" << endl;
    }
}

using namespace first_space;

int main() {
    first_space::func();
    second_space::func();

    //since using first_space for namespace, calls func() from first_space
    func();
    return 0;
}
