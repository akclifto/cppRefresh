#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>


// lets make a stack
template <class T> class Stack {
    private:
        vector<T> elems; // elements

    public: 
        void push(T const&); //push the elems
        void pop(); // pop an element
        T top() const; //return the top element

        bool empty() const { return elems.empty(); } // check if stack is empty.
};


template <class T> void Stack<T>::push(T const& elem) {
    elems.push_back(elem); // append copy of passed element
}

template <class T> void Stack<T>::pop() {
    if(elems.empty()) {
        throw out_of_range("Stack pop:  The stack is empty.");
    }
    //pop the last element
     elems.pop_back();
}

template <class T> void Stack<T>::top() const {

}