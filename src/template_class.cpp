#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

// lets make a stack
template <class T>
class Stack
{
private:
    std::vector<T> elems; // elements

public:
    void push(T const &); //push the elems
    void pop();           // pop an element
    T top() const;        //return the top element

    bool empty() const { return elems.empty(); } // check if stack is empty.
};

template <class T>
void Stack<T>::push(T const &elem)
{
    elems.push_back(elem); // append copy of passed element
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw std::out_of_range("pop == Empty stack.");
    }
    //pop the last element
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw std::out_of_range("top == Empty stack.");
    }
    //return the last element.
    return elems.back();
}

int main()
{
    try
    {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        //int stack
        intStack.push(34);
        std::cout << intStack.top() << std::endl;

        //string stack
        stringStack.push("string on the stack");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop(); // this will trigger the pop throw error block, stack is empty.
    }
    catch (std::exception const &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
        return -1;
    }
}