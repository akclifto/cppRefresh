# Cpp refresher

It's been a while.  Some review:

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

## Floating point literals

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
- A reference has to be initialized when it is created.  Pointers can be initialized at any time.

