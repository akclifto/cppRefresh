#include <iostream>


class Adder{

    public:
        //ctor
        Adder(int i = 0) {
            total = i;
        }

        // interface to public
        void addNum(int num){
            total += num;
        }

        // interface to public
        int getTotal(){
            return total;
        }
    private:
        int total; // this var is hidden from user
};


int main() {

    Adder a;

    a.addNum(10);
    a.addNum(50);
    a.addNum(100);

    std::cout << "Total: " << a.getTotal() << std::endl;  // 160

    return 0;
}