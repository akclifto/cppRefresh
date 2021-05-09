# Cpp Refresher

It's been a while. Some review:

## Contents

- [Cpp Overview](#Cpp-Overview)
  - [Integer Literals](#Integer-Literals)
  - [Floating Point Literals](#Floating-Point-Literals)
  - [Pointers](#Pointers)
  - [References](#References)
  - [Pointers to Structures](#Pointers-to-Structures)
- [OOP with Cpp](#OOP-with-Cpp)
  - [Inheritance](#Inheritance)
  - [Overloading Functions](#Overloading-Functions)
  - [Overloading Operators](#Overloading-Operators)
  - [Polymorphism](#Polymorphism)
  - [Abstraction](#Abstraction)
  - [Encapsulation](#Encapsulation)
  - [Interfaces](#Interfaces)
- [Deeper Topics](#Deeper-Topics)
  - [Files and Streams](#Files-and-Streams)
  - [Exception Handling](#Exception-Handling)
  - [Dynamic Memory](#Dynamic-Memory)
  - [Namespaces](#Namespaces)
  - [Templates](#Templates)
  - [PreProcessor](#PreProcessor)
  - [Signal Handling](#Signal-Handling)
  - [Multi Threading](#Multi-Threading)
  - [Web Programming](#Web-Programming)
  
## Cpp Overview

### Integer Literals

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

[Back to Top](#Contents)

### Floating Point Literals

A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

While representing using decimal form, you must include the decimal point, the exponent, or both and while representing using exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

```cpp
3.14159       // Legal
314159E-5L    // Legal
510E          // Illegal: incomplete exponent
210f          // Illegal: no decimal or exponent
.e55          // Illegal: missing integer or fraction
```

[Back to Top](#Contents)

### Pointers

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

[Back to Top](#Contents)

### References

A reference variable is an alias, that is, another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.  See `references.cpp` for example.

[Back to Top](#Contents)

#### Differences between References and Pointers

- Cannot have NULL references, can have NULL pointers.
- Once a reference is initialized to an object, it cannot be changes to refer to another object.
- A reference has to be initialized when it is created. Pointers can be initialized at any time.

```cpp
int i = 5;      // variable
int &k = i;     // initialize reference to i
std:cout << k << std::endl; // access value of k reference, which is same as i;
```

[Back to Top](#Contents)

### Pointers to Structures

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

    std::cout << "Book1 title: " << structPointer->title << std::endl;
}
```

You can use `typedef` keyword for non-structs to make a bunch of pointers at once under the same variable name:

```cpp
typedef long int *pint32;

pint32 x,y,z; // x,y,z are all pointers to long int
```

## OOP with Cpp

This section will provide general syntax structure for OOP in C++.

### Inheritance

A base class is the parent class. A derived class is the inheriting class to the base class. A derived class can inherit from multiple base classes.  
Syntax: `class derived-class-name: access-specifier base-class-name`  
Example: `class someInheritedClass: public someBaseClass, public someOtherBaseClass`

[Back to Top](#Contents)

#### Warning

It is bad practice to inherit from multiple base classes in the same file. Doing this can create the diamond pattern inheritance. It is better to take a linear inheritance approach, and stack base/derived classes.

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
    std::cout << d.getName() << std::endl; //prints John
}
```

[Back to Top](#Contents)

### Overloading Functions

Function overloading obvious:

```cpp
int add(int a, int b) {
    return a + b;
}

// overload add
int add(int a, int b, int c) {
    return a + b + c;
}
```

[Back to Top](#Contents)

### Overloading Operators

Built-in operators can be overloaded using the ```operator``` keyword followed by the defining operator, Ex: ```operator+```.
This is used mainly to perform some operation on object and return something. See overloading.cpp for example.

|Overloadable operators | | | | | |  
|:-:|:---:|:---:|:---:|:---:|:---:|
| +  |  -  |  *  |  /  |  %  |  ^  |
| &  | verticalLine |  ~  |  !  |  ,  |  =  |
| <  |  >  |  <= |  >= |  ++ |  -- |
| << |  >> |  == |  != |  && |  || |
| += |  -= |  /= |  %= |  ^= |  &= |
| |= |  *= | <<= | >>= |  [] |  () |
| -> | ->* | new | new [] | delete | delete []

|Non-overloadable operators| | | |
| :-:| :-:| :-:| :-:|
| :: | .* | .  | ?: |

[Back to Top](#Contents)

### Polymorphism

A call to a member function will cause a different function to executed depending on the type  
of object that invokes the function (based on class hierarchy and related inheritance).  

Issues can arise in the hierarchy of functions.  A function can be set by the compiler as a version defined in the base class.  
This is called `static resolution`, or `static linkage`.  This causes the function call to be fixed before program execution  
(sometimes called `early binding`) because everything is bound during compilation.

```cpp
class baseClass {
    
    ...
    
    // use `virtual` keyword to tell compiler to look for the contents of the pointer instead of its type, 
    // stops static linkage.
    virtual int area() {  
        ... //return something specific to this base class.
    }
};

class derivedClass {
    ...
    int area() {
        ... // return something specific to this derived class
    }
};

class anotherDerivedClass {
    ...
    int area() {
        ... // return something specific to anotherDerivedClass
    }
};

int main() {
    baseClass *base;
    derivedClass d;
    anotherderivedClass a;

    base = &d; //store address of inherited class
    std::cout << base->area() << std::endl; // outputs function area() specific to derivedclass

    base = &a;
    std::cout << base->area() << std::endl; // outputs function area() specific to anotherDerivedClass

    return 0;
}
```

polymorphism is typically used like this:  differend classed with functions of same name, even same parameters have different implementations.  
The `virtual` keyword tells the compiler that you don't want to use `static linkage` and instead want to use `dynamic binding`, or `late binding`.

`pure virtual functions` transform the base class functions so no meaningful value comes from it, and ensures use in the derived classes.

```cpp
virtual int area() = 0;
```

[Back to Top](#Contents)

### Abstraction

Only essential information makes it out to the public.  Everything else stays hidden, or working in the background.  This is typically done by  
separating interface and implentation as an intentful design technique.  For example, you make a sort algorithm to public use.  The public can use
it without knowing how the sort() function is implemented.  You can change the algorithm and the public wouldn't know because they can't (and shouldn't be able to) access its implementation.  

Easy example: std::cout from iostream in cpp library

```cpp
#include <iostream>

int main() {
    std::cout << "How does cout work?" << std::endl;
    return 0;
}
```

`cout` console prints something to the screen. How does `cout` work? Don't know. Do you care how it works?  Probably not. Has it changed how it's been  
implemented over time?  Absolutely.  That's abstraction at work.  You don't need ot under how it console prints to the screen, only that it does console print.

abstraction is controlled with access labels `private, public, protected`.  You already know this.  

[Back to Top](#Contents)

### Encapsulation  

Similar to the purpose of abstraction, we want to hide all data and functions that the public doesn't need to see or know about.  This ensures our software is secure and can't easily be manipulated or penetrated by someone with malice intent.  You already know about this.  

[Back to Top](#Contents)

### Interfaces

Interfaces describe behavior and capabilities of classes without giving implementation or design away.

```cpp
class Shape {
    public:
        //pure virtual functions that have no meaningful use in the base class.
        virtual double getVolume() = 0; 
        virtual int getIndex() = 0;
    private:
        double l, w, h; // hidden variables needed to implement class.
}
```

pure virtual functions force derived classes to override them to implement.  If you fail to override the pure virtual function in a derived class, you cannot instantiate any objects; you will get a compilation error. Classes that can be used to instantiate objects are called `concrete classes`.  

[Back to Top](#Contents)

## Deeper Topics

### Files and Streams

- `ofstream`:  used to create and write to files.
- `ifstream`:  used as input stream to read from files.
- `fstream`: general stream that can doing duties of both `ofstream` and `ifstream`
- `iostream`: console read in and out.  Uses `cin` and `cout`.

You have to open a file before you can read it. Here is standard syntax for `open()`, which is member of `ifstream`, `ofstream`, `fstream` objects.

```cpp
// open( <file-to-open/read/write>, <ios mode flag> )
void open(const char *filename, ios::openmode mode);
```

#### Mode flags

- `ios::app` : Append mode.  All output to that file is appended to the end of the file.
- `ios::ate` : Open file for output and move the read/write control to the end of the file.
- `ios::in`  : Open file for reading.
- `ios::out` : Open file for writing.
- `ios::trunc` : If the file exists, its contents will be truncated (shortened or reduced) before opening.

You can OR operator to combine ios modes together:

```cpp
// write to file
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );

// read and write to file
fstream myFile
myFile.open("file.dat", ios::out | ios::in );
```

To close a file, `void close();`

- `<<` : output operator (writing)  
- `>>` : input operator (reading)

#### Positioning Within Streams

- `seekg` (seek get) : used for ifstream
- `seekp` (seek put) : used for ofstream

Both `seekg` and `seekp` are usually long integers.  A second argument is used to indicate direction of the seek.

- `ios::beg` : the default position relative to the beginning of the stream.
- `ios::cur` : position relative to the current position in the stream.
- `ios::end` : position relative to the end of the stream

Examples:

```cpp
// position at nth byte of fileObject (assumes ios::beg)
fileObject.seekg(n);

// position n bytes forward in fileObject
fileObject.seekg(n, ios::cur)


// position n bytes back from end of fileObject
fileObject.seekg(n, ios::end);

// position at end of fileObject
fileObject.seekg(0, ios::end);
```

[Back to Top](#Contents)

### Exception Handling

Try/catch/throw the same as Java:

```cpp

void function(int a, int b){
    
    if( a == 0 || b == 0) {
        throw "Some error";
    }
    try {

        // some code to protect from error

    } catch (const char *errorMessage) {

        // some code to handle error

        std::cerr << errorMessage << std::endl;
    }
}

//custom exception handling
struct MyException : public exception {
    // override exception classes what() function to return custom handling.
    const char *what() const throw() {
        return "Customer expection message";
    }
}

// use customer exception
void anotherFunction(int a) {
    try {

    } catch (MyException &e) {
        std::cout << "Custom exception caught" << std::endl;
        //using what() here gets the message by overriding expception class what()
        std::cout << e.what() << std::endl;  
    } catch (std::exception &e) {
        // other std error handling
    }
}
```

#### Standard Exception Types and Descriptions

- `std::exception` : An exception and parent class of all the standard C++ exceptions.
- `std::bad_alloc` : This can be thrown by `new`.
- `std::bad_cast` : This can be thrown by `dynamic_cast`.
- `std::bad_exception` : This is useful device to handle unexpected exceptions in a C++ program.
- `std::bad_typeid`: This can be thrown by `typeid`.
- `std::logic_error` : An exception that theoretically can be detected by reading the code.
- `std::domain_error` : This is an exception thrown when a mathematically invalid domain is used.
- `std::invalid_argument` : This is thrown due to invalid arguments.
- `std::length_error` : This is thrown when a too big std::string is created.
- `std::out_of_range` : This can be thrown by the 'at' method, for example a `std::vector` and `std::bitset<>::operator[]()`.
- `std::runtime_error` : An exception that theoretically cannot be detected by reading the code.
- `std::overflow_error` : This is thrown if a mathematical overflow occurs.
- `std::range_error` : This is occurred when you try to store a value which is out of range.
- `std::underflow_error` : This is thrown if a mathematical underflow occurs.
  - underflow: that is, situations where the result of a computation is a subnormal floating-point value.

[Back to Top](#Contents)

### Dynamic Memory  

- `The Stack`:  Automatic memory allocation.  All variable within functions use stack memory unless designated by programmer.
- `The Heap` :  Unused memory within program that can be allocated dynamically when the program runs.

Memory gets allocated using the `new` operator keyword: `List list = new List();` This `new` keyword allocates memory for the data-type.  
Memory can be deleted using the `delete` operator keyword: `delete list;` This is used when you're done with a dynamically created object and want to free up memory.  

```cpp
double *pointerVar = NULL; // pointer initialized to NULL
pointerVar = new double;  // request memory for new data var of type double

// use the pointerVar in some code

delete pointerVar;  // delete pointerVar from memory when done with it to free up system memory.
```

Sometimes memory allocation runs out, so be sure to handle:

```cpp
double *value = NULL;
if( !(value = new double)) {
    std::cout << "Uh-Oh! Out of memory" << std::endl;
    // derp handling
    exit(1);
}
```

`malloc()` exists in Cpp but is not advised to use it.  The `new` keyword replaces `malloc()` and is better than using `malloc()`.
The advantage of `new` is that it allocates memory and also constructs objects for you.  This is OOP and the very purpose of Cpp's creation: to be OOP.

#### Array allocation

```cpp
// standard array
char *arr = NULL;
arr = new char[20];

// use arr in code

delete [] arr; // free up when done.
```

#### Multi-dimensional array allocation

```cpp
// using double pointer here for dimension pointer.
double **mdArr = NULL;
mdArr = new double[4][5];

// use mdArr in code

//consider freeing memory at each position in array first, then deleting entire array, like below:
for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    delete[] mdArr[i];
}
delete [] mdArr; // free up remaining var.

```

#### Object allocation

Use constructors and destructors to dynamically allocate object memory

```cpp
class Box {
   public:
      Box() { 
         std::cout << "Constructor called!" << std::endl; 
      }
      ~Box() { 
         std::cout << "Destructor called!" << std::endl; 
      }
};
int main() {
   Box* myBoxArray = new Box[2];
   delete [] myBoxArray; // Delete array

   return 0;
}
```

[Back to Top](#Contents)

### Namespaces

Pretty straightforward.  Use namespaces to further organize your code.

```cpp
namespace some_namespace {
    func() {
        std::cout << "Using some namespace functions" << std::endl;
    }
}
using namespace some_namespace;

int main() {
    func();
    return 0;
}
```

This will output the `func()` inside namespace called `some_namespace`. See `namespaces.cpp` example in src.

Avoid using namespace std;  This is okay for simple programs but can cause problems in larger, more complex programs that use thrid party libraries. Use `std::<param>` (Ex: `std::cout`, `std::cin`, `std::endl`, `std::string`, etc.) instead.

[Back to Top](#Contents)

### Templates

Templates are the foundation for generic programming, and necessary to write code such that it is independent of any type.  It is a blueprint for a generic class or function.  The cpp library iterators are examples of templates.  For example, the `vector` class container has a single definition, but there are many types of vectors => `vector<int>`, `vector<string>`, etc.

General form:

```cpp
template <class type> return-type function-name(parameter list) {
    /// body of function or class
}
```

Example of function template:

```cpp
template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}
```

See `template_function.cpp` for example usage.

Example of class template: `

```cpp
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
```

See `template_class.cpp` for example usage.

[Back to Top](#Contents)

### PreProcessor

Preprocessors are directives that give instructions to the compiler before compilation occurs.  The directives begin with the pound symbol (`#`), and have been used with every example written so far (`#include`). Others include `#define, #if, #else, #line, #endif`.

#### #include

This is used to include a header file into the source file.

#### #define

This creates a symbolic constant.  The constant, `#define macro-name replacement-text`.  Example,

```cpp
#include <iostream>
using namespace std;

#define PI 3.14159

int main() {
    cout << "PI definition: " << PI << endl;
    return 0;
}
```

#### defining function-like macros

```cpp
//ternary operator that returns minimum value between to inputs. Macro-name = MIN(a,b) replacement-text = (((a) < (b)) ? a : b)
#define MIN(a,b) (((a) < (b)) ? a : b)
```

#### conditional compilations

```cpp
//if NULL is not defined (ifndef), define it, then end if (endif)
#ifndef NULL
    #define NULL 0
#endif
```

#### debugging

This can be done with a single macro to turn on debugging:

```cpp
// If #define DEBUG has been defined before #ifdef DEBUG, cerr statement will be compiled.
#ifdef DEBUG
    cerr << "Variable x = " << x << endl;
#endif
```

To skip code from running (like debugging), use following structure:

```cpp
#if 0
    some code prevented from compiling
#endif
```

[Back to Top](#Contents)

### Signal-Handling

[Back to Top](#Contents)

### Multi Threading

### Web Programming
