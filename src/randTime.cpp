#include <iostream>
#include<ctime>

using namespace std;

int randTime();

int main() {
    
    randTime();
}

int randTime() {

    srand((unsigned) time(NULL));

    for(int i = 0; i < 5; i++){
        int j = rand();
        cout << "Random: " << j << endl;
    }

    return 0;
}
