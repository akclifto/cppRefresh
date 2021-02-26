# Cpp Refresher

It's been a while. Some review:

## Contents

- [Integer Literals](#Integer-Literals)
- [Floating Point Literals](#Floating-Point-Literals)
- [Pointers](#Pointers)
- [References](#References)
- [Pointers to Structures](#Pointers-to-Structures)
- [OOP with Cpp](#OOP-with-Cpp)
- [Inheritance](#Inheritance)
- [Overloading Functions](#Overloading-(Functions))
- [Overloading Operators](#Overloading-(Operators))

## Integer Literals

An integer literal can be a decimal, octal, or hexadecimal constant. A prefix specifies the base or radix: 0x or 0X for hexadecimal, 0 for octal, and nothing for decimal.

An integer literal can also have a suffix that is a combination of U and L, for unsigned and long, respectively. The suffix can be uppercase or lowercase and can be in any order.

Examples of Integer literals:

```cpp
212         // Legal
215u        // Legal
0xFeeL      // Legal
078         // Illegal: 8 is not an octal digit
032UU       // Illegal: cannot repeat a suffix
```

Examples of TYPES of integer literals:

```cpp
85         // decimal
0213       // octal
0x4b       // hexadecimal
30         // int
30u        // unsigned int
30l        // long
30ul       // unsigned long
```

## Floating Point Literals

A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

While representing using decimal form, you must include the decimal point, the exponent, or both and while representing using exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

```cpp
3.14159       // Legal
314159E-5L    // Legal
510E          // Illegal: incomplete exponent
210f          // Illegal: no decimal or exponent
.e55          // Illegal: missing integer or fraction
```

## Pointers

There are few important operations, which we will do with the pointers very frequently.

- (a) We define a pointer variable.
- (b) Assign the address of a variable to a pointer.
- (c) Finally access the value at the address available in the pointer variable.

```cpp
int var = 340;      // variable
int *pointer;       // initialized pointer
pointer = &var;     // set pointer to address of var
std::cout << *pointer; //access value of var through "*" pointer
```

## References

A reference variable is an alias, that is, another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.

### Differences between References and Pointers

- Cannot have NULL references, can have NULL pointers.
- Once a reference is initialized to an object, it cannot be changes to refer to another object.
- A reference has to be initialized when it is created. Pointers can be initialized at any time.

```cpp
int i = 5;      // variable
int &k = i;     // initialize reference to i
std:cout << k << endl; // access value of k reference, which is same as i;
```

## Pointers to Structures

Pointers to structures are defined just like pointers to variables. Define the pointer, assign the address, and then access the value at the address in the pointer.

To access the value at the address in the pointer, use the arrow `->`.
In Java, this would just be Book1.title. In cpp, it is

```cpp
struct Books {
    char title[50];
    char auther[50];
}

int main() {
    struct Books Book1;
    struct Books *structPointer;
    structPointer = &Book1;

    strcpy( Book1.title, "Learn C++ Programming");
    strcpy( Book1.author, "Chand Miyan");

    std::cout << "Book1 title: " << structPointer->title << endl;
}
```

You can use `typedef` keyword for non-structs to make a bunch of pointers at once under the same variable name:

```cpp
typedef long int *pint32;

pint32 x,y,z; // x,y,z are all pointers to long int
```

## OOP with Cpp

This section will provide general syntax structure for OOP in C++.

## Inheritance

A base class is the parent class. A derived class is the inheriting class to the base class.  A derived class can inherit from multiple base classes.  
Syntax:  ```class derived-class-name: access-specifier base-class-name```  
Example: ```class someInheritedClass: public someBaseClass, public someOtherBaseClass```

```cpp
class baseClass {
    public:
        void setName(std::string n) {  
            name = n; //ensure the input name param is different from the name var 
            // (ie, `name = name` will produce null)
        }

    protected:
        std::string name;
};

// inherited class
class derivedClass: public baseClass {
    public:
        std::string getName() {
            return name;
        }
};

int main() {
    derivedClass d;

    d.setName("John");
    cout << d.getName() << endl; //prints John
}
```

## Overloading (Functions)

## Overloading (Operators)
